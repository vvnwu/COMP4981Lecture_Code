#ifndef MEMORY_H
#define MEMORY_H


#include <semaphore.h>
#include <stdbool.h>
#include <stddef.h>


#define SHMEM_HAME "dc_shared"

struct Memory
{
    size_t counter;
    bool done;
};


struct Semaphores
{
    sem_t *occupied;
    sem_t *empty;
    sem_t *put;
    sem_t *get;
};


#endif
