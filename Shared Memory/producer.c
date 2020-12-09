#include "memory.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>



static void writeFunc(size_t times,
                      struct Memory *memory,
                      struct Semaphores *semaphores)
{
    memory->done = false;
    
    for(size_t i = 0; i < times; i++)
    {
        sem_wait(semaphores->empty);
        sem_wait(semaphores->put);
        memory->counter = i;
        printf("Wrote %zu\n", i);
        sem_post(semaphores->put);
        sem_post(semaphores->occupied);
    }
    
    memory->done = true;
}


int main(int argc, const char * argv[])
{
    struct Semaphores semaphores;
    int fd;
    struct Memory *ptr;
    
    sem_unlink("/occupied");
    sem_unlink("/empty");
    sem_unlink("/put");
    sem_unlink("/get");
    
    semaphores.occupied = sem_open("/occupied", O_CREAT, S_IRUSR|S_IWUSR, 0);
    semaphores.empty = sem_open("/empty", O_CREAT, S_IRUSR|S_IWUSR, 1);
    semaphores.put = sem_open("/put", O_CREAT, S_IRUSR|S_IWUSR, 1);
    semaphores.get = sem_open("/get", O_CREAT, S_IRUSR|S_IWUSR, 1);
    
    fd = shm_open(SHMEM_HAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(struct Memory));
    ptr = mmap(0, sizeof(struct Memory), PROT_WRITE, MAP_SHARED, fd, 0);
    writeFunc(10, ptr, &semaphores);
    
    sem_close(semaphores.occupied);
    sem_close(semaphores.empty);
    sem_close(semaphores.put);
    sem_close(semaphores.get);

    return EXIT_SUCCESS;
}
