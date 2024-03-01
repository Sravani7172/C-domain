#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>
#include <poll.h>
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 12345
using namespace std;
struct Client {
    int socket;
    string name;
};
int main() {
    int serverSocket;
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
    serverAddr.sin_port = htons(SERVER_PORT); 
    
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
    cout << "Server listening on port " << SERVER_PORT << ".." << endl;

    struct pollfd fds[MAX_CLIENTS + 1]; 
    memset(fds, 0, sizeof(fds));
    fds[0].fd = serverSocket;
    fds[0].events = POLLIN;
    Client clients[MAX_CLIENTS];
    int numClients = 0;

    while (true) {
        if (poll(fds, numClients + 1, -1) == -1) {
            perror("Poll error");
            exit(EXIT_FAILURE);
        }
	//check if there is an event on the serverSocket
        if (fds[0].revents & POLLIN) {
            int newClientSocket;
            if ((newClientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) == -1) {
                perror("Accept error");
                exit(EXIT_FAILURE);
            }
            cout << "New client connected.." << endl;
            if (numClients >= MAX_CLIENTS) {
                cout << "Maximum clients reached. Connection rejected." << endl;
                close(newClientSocket);
            } else {
                fds[numClients + 1].fd = newClientSocket;
                fds[numClients + 1].events = POLLIN;
                clients[numClients].socket = newClientSocket;
                numClients++;
            }
        }
        for (int i = 0; i < numClients; ++i) {
            if (fds[i + 1].revents & POLLIN) {//checks if there is an read event
                memset(buffer, 0, BUFFER_SIZE);
                if (read(clients[i].socket, buffer, BUFFER_SIZE) <= 0) {
                    cout << "Client disconnected: " << clients[i].name << endl;
                    close(clients[i].socket);
                    clients[i].socket = 0;
                    fds[i + 1].fd = -1;
                } else {
                    cout << "Message from " << clients[i].name << ": " << buffer << endl;
                    // Broadcast message to all other clients
                    for (int j = 0; j < numClients; ++j) {
                        if (clients[j].socket > 0 && j != i) {
                            string message = clients[i].name + ": " + buffer;
                            if (write(clients[j].socket, message.c_str(), message.length()) == -1) {
                                perror("Write error");
                                close(clients[j].socket);
                                clients[j].socket = 0;
                            }
                        }
                    }

                    // Check if the client wants to exit
                    if (strcmp(buffer, "bye") == 0) {
                        cout << "Client disconnected: " << clients[i].name << endl;
                        close(clients[i].socket);
                        clients[i].socket = 0;
                    }
                }
            }
        }
    }
    close(serverSocket);
    return 0;
}


