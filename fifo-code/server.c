#include "dc_fcntl.h"
#include "dc_unistd.h"
#include "dc_sys_stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FIFO_PATH "fifotest"


int main(int argc, const char *argv[])
{
    int fd;
    size_t len;
    
    if(argc < 2)
    {
        fprintf(stderr, "USAGE: server <word>\n");
        exit(EXIT_FAILURE);
    }
    
    dc_mkfifo(FIFO_PATH, S_IWUSR | S_IRUSR, true);
    fd = dc_open(FIFO_PATH, O_WRONLY);
    len = strlen(argv[1]);
    printf("WRITE len: %ld\n", len);
    dc_write(fd, &len, sizeof(len));
    printf("WRITE word: %s\n", argv[1]);
    dc_write(fd, argv[1], len);
    dc_close(fd);

    return EXIT_SUCCESS;
}
