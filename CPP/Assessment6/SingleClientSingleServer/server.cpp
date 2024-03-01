#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;
#define PORT 7890
#define BUFFER_SIZE 1024
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket for server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    cout << "Server listening on port " << PORT << "...\n";

    // Accepting connections
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_size);
    if (client_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Reading and writing data to/from the client
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        read(client_socket, buffer, BUFFER_SIZE);
        cout << "Client data: " << buffer << endl;
        cout << "server data ";
        cin.getline(buffer, BUFFER_SIZE);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(server_socket);
    return 0;
}

