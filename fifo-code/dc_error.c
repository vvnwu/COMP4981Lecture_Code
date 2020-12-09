#include "dc_error.h"
#include <stdio.h>
#include <stdlib.h>


void dc_handle_error(const char * func, int errno)
{
    perror(func);
    exit(EXIT_FAILURE);
}
