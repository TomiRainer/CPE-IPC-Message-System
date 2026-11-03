#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>

int main() {

    // Shared Memory öffnen
    int fd = shm_open("/meine_shm", O_RDWR, 0666);

    // Shared Memory einbinden
    char *shared_memory = mmap(
        NULL,
        100,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd,
        0
    );

    // Semaphore öffnen
    sem_t *semaphore = sem_open(
        "/meine_semaphore",
        0
    );

    // Speicher sperren
    sem_wait(semaphore);

    printf("Reader: Speicher gesperrt.\n");

    // Nachricht lesen
    printf("Reader: %s\n", shared_memory);

    // Speicher freigeben
    sem_post(semaphore);

    printf("Reader: Speicher freigegeben.\n");

    // Aufräumen
    munmap(shared_memory, 100);
    close(fd);

    return 0;
}