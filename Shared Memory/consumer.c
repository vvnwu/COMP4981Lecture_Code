#include "memory.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>


static void readFunc(struct Memory *memory,
                     struct Semaphores *semaphores)
{
    while(!(memory->done))
    {
        size_t value;
        
        sem_wait(semaphores->occupied);
        sem_wait(semaphores->get);
        value = memory->counter;
        printf("Read %zu\n", value);
        sem_post(semaphores->get);
        sem_post(semaphores->empty);
    }
}

int main(int argc, const char * argv[])
{
    struct Semaphores semaphores;
    int fd;
    struct Memory *ptr;

    semaphores.occupied = sem_open("/occupied", O_CREAT, S_IRUSR|S_IWUSR, 0);
    semaphores.empty = sem_open("/empty", O_CREAT, S_IRUSR|S_IWUSR, 1);
    semaphores.put = sem_open("/put", O_CREAT, S_IRUSR|S_IWUSR, 1);
    semaphores.get = sem_open("/get", O_CREAT, S_IRUSR|S_IWUSR, 1);
    
    fd = shm_open(SHMEM_HAME, O_RDONLY, 0666);
    ptr = mmap(0, sizeof(struct Memory), PROT_READ, MAP_SHARED, fd, 0);
    readFunc(ptr, &semaphores);
    munmap(ptr, sizeof(struct Memory));

    sem_close(semaphores.occupied);
    sem_close(semaphores.empty);
    sem_close(semaphores.put);
    sem_close(semaphores.get);
    
    sem_unlink("/occupied");
    sem_unlink("/empty");
    sem_unlink("/put");
    sem_unlink("/get");

    return EXIT_SUCCESS;
}
