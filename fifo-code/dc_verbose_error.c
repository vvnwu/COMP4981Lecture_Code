#include "dc_error.h"
#include <stdio.h>
#include <stdlib.h>


void dc_handle_error(const char *func, int errno)
{
    fprintf(stderr, "Entering %s (%s %d)\n", __FUNCTION__, func, errno);
    perror(func);
    fprintf(stderr, "Leaving %s (%s %d)\n", __FUNCTION__, func, errno);
    exit(EXIT_FAILURE);
}
