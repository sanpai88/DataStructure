#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define SERVER_IP "127.0.0.1" // Change this for your server
#define SERVER_PORT 8080
#define NUM_CLIENTS 50 // Number of concurrent connections

void *client_thread(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    struct sockaddr_in server_addr = {.sin_family = AF_INET, .sin_port = htons(SERVER_PORT)};
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed : %d \n",errno);
        close(sock);
        return NULL;
    }

    char *message = "Hello from client\n";
    int op = send(sock, message, strlen(message), 0);
    if(op < 0 )
    {
        printf("Send failed : %d\n",errno);
	close(sock);
	return NULL;
    }

    char buffer[1024] = {0};

    op = recv(sock, buffer, sizeof(buffer), 0);
    if(op < 0 )
    {
        printf("Recv failed :%d\n",errno);
	close(sock);
	return NULL;
    }

    if(op > 0)
        printf("Response: %s\n", buffer);

    close(sock);
    return NULL;
}

int main() {
    pthread_t clients[NUM_CLIENTS];

    // Creating multiple client connections
    for (int i = 0; i < NUM_CLIENTS; i++) {
        pthread_create(&clients[i], NULL, client_thread, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_CLIENTS; i++) {
        pthread_join(clients[i], NULL);
    }

    return 0;
}
