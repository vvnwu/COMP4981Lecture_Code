#include "dc_error.h"
#include "dc_sys_stat.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


void dc_mkfifo(const char *path, mode_t mode, bool can_exist)
{
    fprintf(stderr, "Entering %s (%s %d, %d)\n", __FUNCTION__, path, mode, can_exist);
    dc_mkfifo_error(dc_handle_error, path, mode, can_exist);
    fprintf(stderr, "Leaving %s (%s %d, %d)\n", __FUNCTION__, path, mode, can_exist);
}


void dc_mkfifo_error(void (*handler)(const char *, int), const char *path, mode_t mode, bool can_exist)
{
    fprintf(stderr, "Entering %s (%s %d, %d)\n", __FUNCTION__, path, mode, can_exist);

    int status;
    
    status = mkfifo(path, S_IFIFO | mode);
    
    if(status == -1)
    {
        if(errno != EEXIST || !(can_exist))
        {
            if(handler)
            {
                handler("mkfifo", errno);
            }
        }
    }
    
    fprintf(stderr, "Leaving %s (%s %d, %d)\n", __FUNCTION__, path, mode, can_exist);
}

