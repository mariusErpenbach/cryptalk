#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>

int main(){
    
    int server_fd, client_fd;
    sockaddr_in address;
    char buffer[1024] = {0};
    
    // 1. Create Socket
    server_fd = socket(AF_INET, SOCK_STREAM,0);
    if(server_fd==0){
    perror("socket failed");
    return 1;
    }
     
    // 2. configure address
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // localhost
    address.sin_port = htons(8080); // port 8080
    
    // 3. Bind socket
    if(bind(server_fd,(struct sockaddr*) &address, sizeof(address)) < 0 ){
        perror("Bind failed");
        return 1;
    }

    // 4. Listen 
    listen(server_fd,3);
    std::cout << "Cryptalk server is listening on port 8080 \n";

    // 5. Accept Connection
    socklen_t addrlen = sizeof(address);
    client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if(client_fd < 0){
        perror("Accept failed");
        return 1;
    }

    // 6. Receive Data and send back 
    int valread = read(client_fd, buffer, 1024);
    std::cout << "Received: " << buffer << "\n";

    send(client_fd, buffer, strlen(buffer),0);
    std::cout << "Send Back.";

    // 7. Clean Up
    close(client_fd);
    close(server_fd);
    return 0;
}