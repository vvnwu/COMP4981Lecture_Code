// cat < input.txt > output.txt
// redirect input from input.txt, redirect output to output.txt
// input.txt & output.txt argv params
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    int in;
    int out;

    in = open(argv[1], O_RDONLY);
    out = open(argv[2], O_WRONLY | O_TRUNC |O_CREAT, S_IRUSR| S_IRGRP |S_IWGRP |S_IWUSR);

    dup2(in, STDIN_FILENO);
    dup2(out, STDOUT_FILENO);

    close(in);
    close(out);

    execl("/bin/cat", "cat", (char*)0);
    perror("execl");

    return EXIT_FAILURE;
}
//NOTE: escape ! (\!) special cmd in shell