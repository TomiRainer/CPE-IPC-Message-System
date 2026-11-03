#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/meine_fifo"

int main(void) {
    const char message[] = "Hallo vom FIFO-Sender!";

    int fd = open(FIFO_PATH, O_WRONLY);  // wartet, bis Empfänger geöffnet hat
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, message, strlen(message) + 1) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Nachricht gesendet.\n");
    close(fd);
    return 0;
}