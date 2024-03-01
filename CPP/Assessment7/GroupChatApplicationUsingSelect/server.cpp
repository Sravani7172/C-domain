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
    int serverSocket, clientSockets[MAX_CLIENTS] = {0};
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(12345);

    // Bind socket
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

    fd_set readFds;
    FD_ZERO(&readFds);
    FD_SET(serverSocket, &readFds);
    int maxFd = serverSocket;

    while (true) {
        fd_set tempReadFds = readFds;

        // Select
        if (select(maxFd + 1, &tempReadFds, nullptr, nullptr, nullptr) == -1) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // Check if there is a new connection
        if (FD_ISSET(serverSocket, &tempReadFds)) {
            // Accept new connection
            int clientSocket;
            if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) == -1) {
                perror("Accept error");
                exit(EXIT_FAILURE);
            }
            cout << "New client connected.." << endl;

            // Add new client socket to the array
            int i;
            for (i = 0; i < MAX_CLIENTS; ++i) {
                if (clientSockets[i] == 0) {
                    clientSockets[i] = clientSocket;
                    FD_SET(clientSocket, &readFds);
                    if (clientSocket > maxFd) {
                        maxFd = clientSocket;
                    }
                    break;
                }
            }
            if (i == MAX_CLIENTS) {
                cerr << "Too many clients, connection rejected" << endl;
                close(clientSocket);
            }
        }

        // Check for data from clients
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (clientSockets[i] > 0 && FD_ISSET(clientSockets[i], &tempReadFds)) {
                memset(buffer, 0, BUFFER_SIZE);
                // Receive message from client
                int bytesReceived = recv(clientSockets[i], buffer, BUFFER_SIZE, 0);
                if (bytesReceived <= 0) {
                    cout << "Client disconnected" << endl;
                    close(clientSockets[i]);
                    FD_CLR(clientSockets[i], &readFds);
                    clientSockets[i] = 0;
                } else {
                    // Broadcast message to all other clients
                    for (int j = 0; j < MAX_CLIENTS; ++j) {
                        if (clientSockets[j] > 0 && clientSockets[j] != clientSockets[i]) {
                            if (send(clientSockets[j], buffer, bytesReceived, 0) == -1) {
                                perror("Send error");
                                close(clientSockets[j]);
                                FD_CLR(clientSockets[j], &readFds);
                                clientSockets[j] = 0;
                            }
                        }
                    }

                    // Check if the client wants to exit
                    if (strcmp(buffer, "bye") == 0) {
                        cout << "Client disconnected" << endl;
                        close(clientSockets[i]);
                        FD_CLR(clientSockets[i], &readFds);
                        clientSockets[i] = 0;
                    }
                }
            }
        }
    }

    close(serverSocket);
    return 0;
}

