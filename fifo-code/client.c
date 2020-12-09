#include "dc_fcntl.h"
#include "dc_unistd.h"
#include "dc_sys_stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FIFO_PATH "fifotest"


int main(int argc, const char * argv[])
{
    int fd;
    size_t len;
    char *word;
    
    dc_mkfifo(FIFO_PATH, S_IWUSR | S_IRUSR, true);
    fd = dc_open(FIFO_PATH, O_RDONLY);
    len = 0;
    dc_read(fd, &len, sizeof(len));
    printf("READ len: %ld\n", len);
    word = malloc(len + 1 * sizeof(char));
    dc_read(fd, word, len);
    word[len] = '\0';
    printf("READ word: %s\n", word);
    free(word);
    dc_close(fd);

    return EXIT_SUCCESS;
}
