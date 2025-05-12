#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>

#define MAX_EVENTS 100
#define PORT 8080
#define THREAD_POOL_SIZE 10

int epoll_fd;
pthread_mutex_t queue_lock;
pthread_cond_t queue_cond;
pthread_mutex_t epoll_lock;
int task_queue[MAX_EVENTS] = {0}; // Queue to store client sockets
int queue_size = 0;

// Function to set socket to non-blocking mode
void set_nonblocking(int fd) {
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
}

// Worker thread function
void *worker_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&queue_lock);
        while (queue_size == 0) {
            pthread_cond_wait(&queue_cond, &queue_lock);
        }
        int client_sock = task_queue[--queue_size]; // Get task from queue
        pthread_mutex_unlock(&queue_lock);

        char buffer[1024] = {0};
        int bytes = read(client_sock, buffer, sizeof(buffer));
        if (bytes > 0) {
            printf("Received: %s \n", buffer);
            if(write(client_sock, "Hello from server\n", 19) < 0 )
            {
               printf("Write failure : %d sock:%d\n",errno,client_sock);
            }
        }

	close(client_sock);
    }
}

// Function to initialize thread pool
void init_thread_pool() {
    pthread_t threads[THREAD_POOL_SIZE];
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&threads[i], NULL, worker_thread, NULL);
        pthread_detach(threads[i]); // Allows threads to clean up automatically
    }
}

// Server setup using epoll
void start_server() {
    int total_connections = 0;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {.sin_family = AF_INET, .sin_addr.s_addr = INADDR_ANY, .sin_port = htons(PORT)};
    int yes = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, SOMAXCONN);
    set_nonblocking(server_fd);

    epoll_fd = epoll_create1(0);
    struct epoll_event event = {.events = EPOLLIN, .data.fd = server_fd};
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event);

    printf("Listening connections \n");
    struct epoll_event events[MAX_EVENTS];
    while (1) {
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
	total_connections+= num_events;
	//printf("Events received : %d Total events :%d \n",num_events,total_connections);
        for (int i = 0; i < num_events; i++) {
            if (events[i].data.fd == server_fd) {
                int client_sock = accept(server_fd, NULL, NULL);
		if( client_sock < 0 )
		{
		    printf("accept error :%d \n",errno);
		    continue;
		}
                set_nonblocking(client_sock);
                struct epoll_event client_event = {.events = EPOLLIN, .data.fd = client_sock};
                
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_sock, &client_event);

            } else {
                pthread_mutex_lock(&queue_lock);
                task_queue[queue_size++] = events[i].data.fd;
                pthread_cond_signal(&queue_cond);
                pthread_mutex_unlock(&queue_lock);
	        epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
            }
        }
    }
}

int main() {
    pthread_mutex_init(&queue_lock, NULL);
    pthread_cond_init(&queue_cond, NULL);
    init_thread_pool();
    start_server();
    return 0;
}
