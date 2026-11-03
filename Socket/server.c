#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    char buffer[1024] = {0};

    // Socket erstellen
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Socket an Port binden
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Auf Verbindung warten
    listen(server_fd, 3);

    printf("Warte auf Client...\n");

    // Verbindung akzeptieren
    client_fd = accept(server_fd, NULL, NULL);

    // Nachricht empfangen
    read(client_fd, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);

    // Nachricht senden
    char *message = "Hallo vom Server!";
    send(client_fd, message, strlen(message), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}