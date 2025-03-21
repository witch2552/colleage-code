#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8082
int main() {
int server_fd, client1, client2, num, squared;
struct sockaddr_in server_addr;
socklen_t addr_len = sizeof(server_addr);
server_fd = socket(AF_INET, SOCK_STREAM, 0);
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(PORT);
bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
listen(server_fd, 2);
printf("Server waiting for Client1...\n");
client1 = accept(server_fd, (struct sockaddr*)&server_addr, &addr_len);
printf("Server waiting for Client2...\n");
client2 = accept(server_fd, (struct sockaddr*)&server_addr, &addr_len);
read(client1, &num, sizeof(num));
squared = num * num;
printf("Received %d from Client1, Squared: %d\n", num, squared);
write(client2, &squared, sizeof(squared));
close(client1);
close(client2);
close(server_fd);
return 0;
}