#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/meine_fifo"

int main(void) {
    char buffer[256];


    if (mkfifo(FIFO_PATH, 0666) == -1) {  // FIFO anlegen

        if (access(FIFO_PATH, F_OK) == -1) {
            perror("mkfifo");
            return 1;
        }
    }

    printf("Warte auf Sender an %s ...\n", FIFO_PATH);
    int fd = open(FIFO_PATH, O_RDONLY);  // wartet, bis Sender öffnet

    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Empfangene Nachricht: %s\n", buffer);
    } else {
        printf("Keine Nachricht empfangen.\n");
    }

    close(fd);
    return 0;
}
