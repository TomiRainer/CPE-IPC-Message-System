#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];                 // fd[0] = Lesen, fd[1] = Schreiben
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {            // Kindprozess: Sender
        close(fd[0]);          // Kind liest nicht
        const char message[] = "Hallo vom Kindprozess!";
        write(fd[1], message, sizeof(message));
        close(fd[1]);
        return 0;
    } else {                   // Elternprozess: Empfänger
        close(fd[1]);          // Elternprozess schreibt nicht
        ssize_t n = read(fd[0], buffer, sizeof(buffer) - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("Empfangen: %s\n", buffer);
        }
        close(fd[0]);
        wait(NULL);
    }

    return 0;
}

