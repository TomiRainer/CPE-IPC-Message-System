#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>

int main() {

    // Shared Memory öffnen
    int fd = shm_open("/meine_shm", O_CREAT | O_RDWR, 0666);

    // Größe festlegen
    ftruncate(fd, 100);

    // Shared Memory einbinden
    char *shared_memory = mmap(
        NULL,
        100,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd,
        0
    );

    // Semaphore erstellen
    sem_t *semaphore = sem_open(
        "/meine_semaphore",
        O_CREAT,
        0666,
        1
    );

    // Speicher sperren
    sem_wait(semaphore);

    printf("Writer: Speicher gesperrt.\n");

    // Nachricht schreiben
    strcpy(shared_memory, "Hallo vom Writer!");

    printf("Writer: Nachricht geschrieben.\n");

    // Speicher wieder freigeben
    sem_post(semaphore);

    printf("Writer: Speicher freigegeben.\n");

    // Aufräumen
    munmap(shared_memory, 100);
    close(fd);

    return 0;
}