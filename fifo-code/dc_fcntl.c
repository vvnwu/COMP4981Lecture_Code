#include "dc_error.h"
#include "dc_fcntl.h"
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>


int dc_open(const char *path, int oflag, ...)
{
    va_list args;
    int fd;
    
    va_start(args, oflag);
    fd = dc_open_error(dc_handle_error, path, oflag, args);
    
    return fd;
}


int dc_open_error(void (*handler)(const char *, int), const char *path, int oflag, ...)
{
    int fd;
    
    fd = open(path, oflag);
    
    if(fd == -1)
    {
        if(handler)
        {
            handler("open", errno);
        }
    }
    
    return fd;
}
