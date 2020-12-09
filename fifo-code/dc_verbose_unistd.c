#include "dc_error.h"
#include "dc_unistd.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>


ssize_t dc_read(int fd, void *data, size_t length)
{
    ssize_t status;
    
    fprintf(stderr, "Entering %s (%d, %zu)\n", __FUNCTION__, fd, length);
    status = dc_read_error(dc_handle_error, fd, data, length);
    fprintf(stderr, "Leaving %s (%d, %zu) -> %zd\n", __FUNCTION__, fd, length, status);

    return status;
}


ssize_t dc_read_error(void (*handler)(const char *, int), int fd, void *data, size_t length)
{
    ssize_t status;
    
    fprintf(stderr, "Entering %s (%d, %zu)\n", __FUNCTION__, fd, length);
    status = read(fd, data, length);
    
    if(fd == -1)
    {
        if(handler)
        {
            handler("read", errno);
        }
    }
    
    fprintf(stderr, "Leaving %s (%d, %zu) -> %zd\n", __FUNCTION__, fd, length, status);
    
    return status;
}


ssize_t dc_write(int fd, const void *data, size_t length)
{
    ssize_t status;

    fprintf(stderr, "Entering %s (%d, %zu)\n", __FUNCTION__, fd, length);
    status = dc_write_error(dc_handle_error, fd, data, length);
    fprintf(stderr, "Leaving %s (%d, %zu) -> %zd\n", __FUNCTION__, fd, length, status);

    return status;
}


ssize_t dc_write_error(void (*handler)(const char *, int), int fd, const void *data, size_t length)
{
    ssize_t status;
    
    fprintf(stderr, "Entering %s (%d, %zu)\n", __FUNCTION__, fd, length);
    status = write(fd, data, length);
    
    if(fd == -1)
    {
        if(handler)
        {
            handler("write", errno);
        }
    }
    
    fprintf(stderr, "Leaving %s (%d, %zu) -> %zd\n", __FUNCTION__, fd, length, status);
    
    return status;
}


void dc_close(int fd)
{
    fprintf(stderr, "Entering %s (%d)\n", __FUNCTION__, fd);
    dc_close_error(dc_handle_error, fd);
    fprintf(stderr, "Leaving %s (%d)\n", __FUNCTION__, fd);
}


void dc_close_error(void (*handler)(const char *, int), int fd)
{
    int status;
    
    fprintf(stderr, "Entering %s (%d)\n", __FUNCTION__, fd);
    status = close(fd);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("close", errno);
        }
    }
    
    fprintf(stderr, "Leaving %s (%d)\n", __FUNCTION__, fd);
}
