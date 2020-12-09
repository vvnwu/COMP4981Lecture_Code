#ifndef DC_FIFO_H
#define DC_FIFO_H


#include <fcntl.h>
#include <stdbool.h>


void dc_mkfifo(const char *path, mode_t mode, bool can_exit);
void dc_mkfifo_error(void (*handler)(const char *, int), const char *path, mode_t mode, bool can_exit);


#endif
