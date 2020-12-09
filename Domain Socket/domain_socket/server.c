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


#define BACKLOG 5


int main(int argc, const char * argv[])
{
    struct sockaddr_un addr;
    int sfd;
    
    sfd = dc_socket(AF_UNIX, SOCK_STREAM, 0);
    dc_remove(SOCKET_PATH, false);
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);
    dc_bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));
    dc_listen(sfd, BACKLOG);
    
    for(;;)
    {
        int cfd;
        ssize_t num_read;
        char buf[BUF_SIZE];

        cfd = dc_accept(sfd, NULL, NULL);

        while((num_read = dc_read(cfd, buf, BUF_SIZE)) > 0)
        {
            dc_write(STDOUT_FILENO, buf, num_read);
        }
        
        dc_close(cfd);
    }
    
    // dc_close(sfd); <- never reached because for(;;) never ends.

    return EXIT_SUCCESS;
}
