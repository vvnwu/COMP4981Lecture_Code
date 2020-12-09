#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>


struct Data
{
    bool done;
    size_t counter;
    sem_t occupied;
    sem_t empty;
    sem_t put;
    sem_t get;
};


static void *readFunc(void *arg)
{
    struct Data *data;
    
    data = arg;
    
    while(!(data->done))
    {
        sem_wait(&data->occupied);
        sem_wait(&data->get);
        printf("read - %ld\n", data->counter);
        sem_post(&data->get);
        sem_post(&data->empty);
    }
    
    return 0;
}


static void *writeFunc(void *arg)
{
    struct Data *data;
    
    data = arg;
    
    for(int i = 0; i < 10; i++)
    {
        sem_wait(&data->empty);
        sem_wait(&data->put);
        data->counter++;
        printf("write - %ld\n", data->counter);
        sem_post(&data->put);
        sem_post(&data->occupied);
    }
    
    data->done = true;
    
    return 0;
}


int main(int argc, const char *argv[])
{
    pthread_t read_thread_id;
    pthread_t write_thread_id;
    struct Data data;

    data.done = false;
    data.counter = 0;
    sem_init(&data.occupied, 0, 0);
    sem_init(&data.empty, 0, 1);
    sem_init(&data.put, 0, 1);
    sem_init(&data.get, 0, 1);

    pthread_create(&read_thread_id, NULL, readFunc, &data);
    pthread_create(&write_thread_id, NULL, writeFunc, &data);

    pthread_join(read_thread_id, NULL);
    pthread_join(write_thread_id, NULL);
    sem_destroy(&data.occupied);
    sem_destroy(&data.empty);
    sem_destroy(&data.put);
    sem_destroy(&data.get);

    return EXIT_SUCCESS;
}
