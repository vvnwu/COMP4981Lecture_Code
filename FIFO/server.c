#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define  FIFO_PATH "fifotest"

int main(int argc, const char* argv[]){
    int status, fd;

    printf("Server\n");

    status = mkfifo(FIFO_PATH, S_IFIFO | 0640);
    if(status == -1){
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_PATH, O_WRONLY);
    if(fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(argv[1]);
    ssize_t write_status;

    write_status = write(fd, &len, sizeof(len));
    if(write_status == -1){
        perror("write len");
        exit(EXIT_FAILURE);
    }

    write_status = write(fd, argv[1], len);
    if(write_status == -1){
        perror("write word");
        exit(EXIT_FAILURE);
    }

    status = close(fd);
    if(status == -1){
        perror("close");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}