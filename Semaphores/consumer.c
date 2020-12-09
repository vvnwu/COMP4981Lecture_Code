#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

struct Data
{
    sem_t *occupied;
    sem_t *empty;
    sem_t *put;
    sem_t *get;
};


static void readFunc(struct Data *arg)
{
    struct Data *data;
    
    data = arg;
    
    while(true)
    {
        sem_wait(data->occupied);
        sem_wait(data->get);
        printf("read\n");
        sem_post(data->get);
        sem_post(data->empty);
    }
}



int main(int argc, const char *argv[])
{
    struct Data data;

    data.occupied = sem_open("/occupied", O_CREAT, S_IRUSR|S_IWUSR, 0);
    data.empty = sem_open("/empty", O_CREAT, S_IRUSR|S_IWUSR, 1);
    data.put = sem_open("/put", O_CREAT, S_IRUSR|S_IWUSR, 1);
    data.get = sem_open("/get", O_CREAT, S_IRUSR|S_IWUSR, 1);

    readFunc(&data);
    
    sem_close(data.occupied);
    sem_close(data.empty);
    sem_close(data.put);
    sem_close(data.get);

    sem_unlink("/occupied");
    sem_unlink("/empty");
    sem_unlink("/put");
    sem_unlink("/get");

    return EXIT_SUCCESS;
}
