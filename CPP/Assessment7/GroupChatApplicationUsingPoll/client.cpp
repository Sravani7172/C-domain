#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>
#include <poll.h>

#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 12345

using namespace std;

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
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
    struct pollfd fds[2];
    fds[0].fd = 0;//stdin
    fds[0].events = POLLIN;
    fds[1].fd = clientSocket;
    fds[1].events = POLLIN;
    char name[1024];
    cout << "Enter your username: ";
    cin >> name;
    strcat(name ,"> ");
    char strMessage[1024];
    while (true) {
        if(poll(fds , 2,-1) < 0 ){
		cerr << "poll failed " << endl;
		break;
	}
	if(fds[0].revents & POLLIN){
		fgets(buffer , BUFFER_SIZE , stdin);
		memset(strMessage , 0 , BUFFER_SIZE);
		strcat(strMessage , name);
		buffer[strcspn(buffer , "\n")] = 0;
		if(strlen(buffer) != 0){
			strcat(strMessage , buffer);
			send(clientSocket , strMessage , strlen(strMessage) , 0);
		}
	}
	if (fds[1].revents & POLLIN) {
            // Data from the server is ready
            memset(buffer, 0, BUFFER_SIZE);
            // Handle data received from the server
            if (read(clientSocket, buffer, BUFFER_SIZE) <= 0) {
                cerr << "Server disconnected or error occurred." << endl;
                break;
            }
            buffer[strcspn(buffer, "\n")] = 0;
            cout << buffer << endl;
        }
    }
    close(clientSocket);
    return 0;
}

