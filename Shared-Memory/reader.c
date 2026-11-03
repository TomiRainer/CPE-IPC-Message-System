#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
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

    // Nachricht ausgeben
    printf("Reader: %s\n", shared_memory);

    // Speicher wieder freigeben
    munmap(shared_memory, 100);

    close(fd);

    // Shared Memory löschen
    //shm_unlink("/meine_shm");

    return 0;
}