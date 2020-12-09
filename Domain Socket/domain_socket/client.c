#include <dc/stdio.h>
#include <dc/unistd.h>
#include <dc/sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include "shared.h"



int main(int argc, char *argv[])
{
    struct sockaddr_un addr;
    int fd;
    ssize_t num_read;
    char buf[BUF_SIZE];
    
    fd = dc_socket(AF_UNIX, SOCK_STREAM, 0);
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);
    dc_connect(fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));
    
    while((num_read = dc_read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
    {
        dc_write(fd, buf, num_read);
    }
    
    dc_close(fd);

    return EXIT_SUCCESS;
}
