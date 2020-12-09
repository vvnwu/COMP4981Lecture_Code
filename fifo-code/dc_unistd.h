#ifndef dc_unistd_h
#define dc_unistd_h

#include <sys/types.h>


ssize_t dc_read(int fd, void *data, size_t length);
ssize_t dc_read_error(void (*handler)(const char *, int), int fd, void *data, size_t length);
ssize_t dc_write(int fd, const void *data, size_t length);
ssize_t dc_write_error(void (*handler)(const char *, int), int fd, const void *data, size_t length);
void dc_close(int fd);
void dc_close_error(void (*handler)(const char *, int), int fd);


#endif
