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
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
    cout << "Connected to server" << endl;

    // Prompt user to enter username
    cout << "Enter your username: ";
    cin.getline(buffer, BUFFER_SIZE);

    // Send username to server
    int bytesSent = send(clientSocket, buffer, strlen(buffer), 0);
    if (bytesSent == -1) {
        perror("Send failed");
        close(clientSocket);
        exit(EXIT_FAILURE);
    } else if (bytesSent == 0) {
        cerr << "No bytes sent" << endl;
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    fd_set readFds;
    FD_ZERO(&readFds);
    FD_SET(clientSocket, &readFds);
    FD_SET(STDIN_FILENO, &readFds);

    while (true) {
        fd_set tempReadFds = readFds;

        // Select
        if (select(clientSocket + 1, &tempReadFds, nullptr, nullptr, nullptr) == -1) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // Check if there is data to read from server
        if (FD_ISSET(clientSocket, &tempReadFds)) {
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
        }

        // Check if user has entered a message
        if (FD_ISSET(STDIN_FILENO, &tempReadFds)) {
            // Send message to server
            cin.getline(buffer, BUFFER_SIZE);
            if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
                perror("Send failed");
                close(clientSocket);
                exit(EXIT_FAILURE);
            }

            // Check if the client wants to exit
            if (strcmp(buffer, "bye") == 0) {
                cout << "Disconnected from server" << endl;
                break;
            }
        }
    }

    close(clientSocket);
    return 0;
}

