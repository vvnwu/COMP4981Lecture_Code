#include "dc_error.h"
#include "dc_unistd.h"
#include <errno.h>
#include <unistd.h>


ssize_t dc_read(int fd, void *data, size_t length)
{
    return dc_read_error(dc_handle_error, fd, data, length);
}


ssize_t dc_read_error(void (*handler)(const char *, int), int fd, void *data, size_t length)
{
    ssize_t status;
    
    status = read(fd, data, length);
    
    if(fd == -1)
    {
        if(handler)
        {
            handler("read", errno);
        }
    }
    
    return status;
}


ssize_t dc_write(int fd, const void *data, size_t length)
{
    return dc_write_error(dc_handle_error, fd, data, length);
}


ssize_t dc_write_error(void (*handler)(const char *, int), int fd, const void *data, size_t length)
{
    ssize_t status;
    
    status = write(fd, data, length);
    
    if(fd == -1)
    {
        if(handler)
        {
            handler("write", errno);
        }
    }
    
    return status;
}


void dc_close(int fd)
{
    dc_close_error(dc_handle_error, fd);
}


void dc_close_error(void (*handler)(const char *, int), int fd)
{
    int status;
    
    status = close(fd);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("close", errno);
        }
    }
}
