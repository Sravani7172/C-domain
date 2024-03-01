#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    int serverSocket, maxClients = MAX_CLIENTS;
    int clientSockets[MAX_CLIENTS] = {0};
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(12345); // Port number

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Binding failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Listening failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    cout << "Server listening on port 12345.." << endl;

    while (true) {
        // Accept new connection
        int clientSocket;
        if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) == -1) {
            perror("Accept error");
            continue;
        }
        cout << "New connection accepted" << endl;

        // Add new client socket to the array
        int i;
        for (i = 0; i < maxClients; ++i) {
            if (clientSockets[i] == 0) {
                clientSockets[i] = clientSocket;
                break;
            }
        }

        // Receive username from the client
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            perror("Receive username failed");
            close(clientSocket);
            clientSockets[i] = 0;
            continue;
        }
        buffer[bytesReceived] = '\0';
        cout << "User '" << buffer << "' connected." << endl;

        // Broadcast user joined message to other clients
        for (int j = 0; j < maxClients; ++j) {
            if (clientSockets[j] != 0 && clientSockets[j] != clientSocket) {
                send(clientSockets[j], buffer, bytesReceived, 0);
            }
        }

        while (true) {
            // Receive message from client
            bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesReceived <= 0) {
                if (bytesReceived == 0)
                    cout << "Client disconnected" << endl;
                else
                    perror("Receive error");
                close(clientSocket);
                clientSockets[i] = 0;
                break;
            }
            buffer[bytesReceived] = '\0';

            // Broadcast message to all other clients
            for (int j = 0; j < maxClients; ++j) {
                if (clientSockets[j] != 0 && clientSockets[j] != clientSocket[i]) {
                    send(clientSockets[j], buffer, bytesReceived, 0);
                }
            }

            // Check if the client wants to exit
            if (strcmp(buffer, "bye") == 0) {
                cout << "User '" << buffer << "' disconnected." << endl;
                close(clientSocket);
                clientSockets[i] = 0;
                break;
            }
        }
    }

    close(serverSocket);
    
    return 0;
}

