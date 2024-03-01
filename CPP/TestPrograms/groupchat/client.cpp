#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Connection failed");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
    cout << "Connected to server" << endl;

    // Enter username
    cout << "Enter your username: ";
    cin.getline(buffer, BUFFER_SIZE);

    // Send username to the server
    send(clientSocket, buffer, strlen(buffer), 0);

    while (true) {
        // Receive message from server
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == -1) {
            perror("Receive failed");
            close(clientSocket);
            exit(EXIT_FAILURE);
        } else if (bytesReceived == 0) {
            cout << "Server disconnected" << endl;
            break;
        }

        buffer[bytesReceived] = '\0';
        cout << "Received: " << buffer << endl;

        // Send message to server
        cout << "Enter message: ";
        cin.getline(buffer, BUFFER_SIZE);
        if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
            perror("Send failed");
            close(clientSocket);
            exit(EXIT_FAILURE);
        }

        // Check if the client wants to exit
        if (strcmp(buffer, "bye") == 0) {
            close(clientSocket);
            break;
        }
    }

    close(clientSocket);
    return 0;
}

