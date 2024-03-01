#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_CLIENTS 1
#define BUFFER_SIZE 1024
using namespace std;
int main() {
    int serverSocket, clientSocket, maxClients = MAX_CLIENTS;
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
    //create and initialize fd_set
    fd_set readFds;
    FD_ZERO(&readFds);
    FD_SET(serverSocket, &readFds);
    int maxFd = serverSocket;
    while (true) {
        fd_set tempReadFds = readFds;
     
        // select->monitor sockets for reading
        if (select(maxFd + 1, &tempReadFds, nullptr, nullptr, nullptr) == -1) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }
	
        // Check if there is a new connection
        if (FD_ISSET(serverSocket, &tempReadFds)) {
            //accept()
            if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) == -1) {
                perror("Accept error");
                continue;
            }
            cout << "New connection accepted" << endl;
            FD_SET(clientSocket, &readFds);
            maxFd = max(maxFd, clientSocket);
        }

        // Check for data from clients
        for (int i = 0; i <= maxFd; ++i) {
            if (i == serverSocket || !FD_ISSET(i, &tempReadFds))
                continue;

            int bytesReceived = recv(i, buffer, sizeof(buffer), 0);
            if (bytesReceived <= 0) {
                if (bytesReceived == 0)
                    cout << "Client disconnected" << endl;
                else
                    perror("Receive error");
                close(i);
                FD_CLR(i, &readFds);
            } else {
                buffer[bytesReceived] = '\0';
                cout << "Received from client : " << buffer << endl;
		 cout<<"Server Message: ";
                cin.getline(buffer,100);
                if (send(i, buffer, strlen(buffer), 0) == -1) {
                    perror("Send error");
                    close(i);
                    FD_CLR(i, &readFds);
                }
                if (strcmp(buffer,"bye")==0){
                	close(clientSocket);
                	close(serverSocket);
                	return 0;
                }	
            }
        }
    }

    close(serverSocket);
    return 0;
}

