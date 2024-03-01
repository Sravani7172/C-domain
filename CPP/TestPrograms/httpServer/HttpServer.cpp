#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Failed to create socket");
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(54321);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Bind failed");
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == -1) {
        perror("Listen failed");
        close(serverSocket);
        return 1;
    }

    cout << "Server listening on port 54321..." << endl;

    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            perror("Accept failed");
            close(serverSocket);
            return 1;
        }
        char buffer[1024];
        recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << "Received request:\n" << buffer << endl;
        const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from CPP server";
        send(clientSocket, response, strlen(response), 0);
        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}

