
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd < 0) {
        perror("File open Failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        exit(1);
    }
    else if (pid == 0) {
        char child_msg[] = "This line is written by child process.\n";
        write(fd, child_msg, strlen(child_msg));
        close(fd);
        exit(0);
    }
    else {
        
        wait(NULL);
        char parent_msg[] = "This line is written by the parent process.\n";
        write(fd, parent_msg, strlen(parent_msg));
        close(fd);
    }

    return 0;
}


