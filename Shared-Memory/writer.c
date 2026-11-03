#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {

    // Shared Memory öffnen/erstellen
    int fd = shm_open("/meine_shm", O_CREAT | O_RDWR, 0666);

    // Größe auf 100 Bytes setzen
    ftruncate(fd, 100);

    // Shared Memory in den Prozess einbinden
    char *shared_memory = mmap(
        NULL,
        100,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd,
        0
    );

    // Nachricht direkt in den Shared Memory schreiben
    strcpy(shared_memory, "Hallo vom Shared-Memory-Writer!");

    printf("Writer: Nachricht geschrieben!\n");

    // Speicher wieder freigeben
    munmap(shared_memory, 100);

    close(fd);

    return 0;
}