#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//using pipes for interprocess communication
int main(int argc, char* argv[]) {
    //creating pipe for interprocess communication (read & write channel)
        //for two way communication; create two pipes!
    int pipefd[2];
    pid_t child_pid;
    int pipe_status;

    //creates read write channel (end memory file)
    pipe_status = pipe(pipefd);
    if(pipe_status == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    //create child
    child_pid = fork();
    if(child_pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }else if(child_pid == 0){
        size_t len;
        int status;
        ssize_t length;

        //close read end of pipe
        status = close(pipefd[0]);
        if(status == -1){
            perror("close");
            exit(EXIT_FAILURE);
        }

        //length of input
        len = strlen(argv[1]);
        //write to write pipe end (note write fn is polymorphic)
        length = write(pipefd[1], &len, sizeof(int));
        if(length == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }

        //close write end of pipe
        status = close(pipefd[1]);
        if(status == -1){
            perror("close");
            exit(EXIT_FAILURE);
        }
        //NOTE: error checking will eventually become easier
    }else{
        size_t len;
        int status;
        ssize_t length;

        //parent closes read end
        status = close(pipefd[1]);
        if(status ==-1){
            perror("close");
            exit(EXIT_FAILURE);
        }

        //parent reads as well
        printf("read: %d\n", len);

        //parent closes write end
        status = close(pipefd[0]);
        if(status == -1){
            perror("close");
            exit(EXIT_FAILURE);
        }

        //waits for child to finish
        do{
            pid_t wpid;
            wpid = waitpid(child_pid, &status, WUNTRACED
                #ifdef WCONTINUED
                    |WCONTINUED
                #endif
                );

            if(wpid == -1){
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if(WIFEXITED(status)){
                printf("child exited, status=%d\n", WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
                printf("child killed, status=%d\n", WTERMSIG(status));
            }else if(WIFSTOPPED(status)){
                printf("child stopped, status=%d\n", WSTOPSIG(status));
#ifdef WIFCONTINUED
            }else if(WIFCONTINUED(status)){
                printf("child continued\n");
#endif
            }else{
                printf("Unexpected status (0x%x)\n", status);
            }
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return EXIT_SUCCESS;
}
