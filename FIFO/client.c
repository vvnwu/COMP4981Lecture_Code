#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define  FIFO_PATH "fifotest"

int main(int argc, const char* argv[]){
    int status, fd;

    printf("Client\n");

    status = mkfifo(FIFO_PATH, S_IFIFO | 0640);
    if(status == -1){
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_PATH, O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    ssize_t read_status;
    size_t len;

    read_status = read(fd, &len, sizeof(len));
    if(read_status == -1){
        perror("read len");
        exit(EXIT_FAILURE);
    }
    printf("READ len: %d\n",len);

    char* word;
    word = malloc(len + 1 *sizeof(char));
    read_status = read(fd, word, len);
    if(read_status == -1){
        perror("read len");
        exit(EXIT_FAILURE);
    }

    word[len] = '\0';
    printf("READ word: %s\n",word);
    free(word);

    status = close(fd);
    if(status == -1){
        perror("close");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}