#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in address;
    char buffer[1024] = {0};

    // Socket erstellen
    sock = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    // Mit Server verbinden
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    connect(sock, (struct sockaddr *)&address, sizeof(address));

    // Nachricht senden
    char *message = "Hallo vom Client!";
    send(sock, message, strlen(message), 0);

    // Antwort empfangen
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s\n", buffer);

    close(sock);

    return 0;
}