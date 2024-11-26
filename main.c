#pragma comment(lib, "Ws2_32.lib")

#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>


#define _UNISTD_H    1

int main(int argc, char* argv[])
{
    int sock;
    
    char strIP[16] = "192.168.1.21"; 

    for (int sec = 1; sec <= 2024; sec++) 
    {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        if (inet_pton(AF_INET, strIP, &addr.sin_addr) <= 0)

        {
            perror("Invalid IP address");
            return 1;
        }
        addr.sin_port = htons(sec);
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock < 0)
        {
            perror("Socket creation failed");
            continue;
        }
        if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == 0)
        {
            printf("Open port: %d at IP: %s\n", sec, strIP);
        }
        closesocket(sock);

    }

    return 0;
}
