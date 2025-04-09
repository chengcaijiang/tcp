/*
 ======================
 客户端代码 (client.c) - Windows版本
 ======================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

void error_handler(const char *message) {
    fprintf(stderr, "错误: %s (错误代码: %d)\n", message, WSAGetLastError());
    exit(EXIT_FAILURE);
}

int main() {
    WSADATA wsaData;
    SOCKET sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // 初始化Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        error_handler("Winsock初始化失败");
    }

    // 创建TCP socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        error_handler("socket创建失败");
    }

    // 配置服务器地址
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // 连接服务器
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        error_handler("连接失败");
    }
    printf("已连接到服务器 %s:%d\n", SERVER_IP, PORT);

    while (1) {
        printf("请输入要发送的消息（输入'quit'退出）: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // 退出条件判断
        if (strncmp(buffer, "quit", 4) == 0) break;

        // 发送数据
        if (send(sock_fd, buffer, strlen(buffer), 0) == SOCKET_ERROR) {
            error_handler("发送失败");
        }

        // 接收响应
        int bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == SOCKET_ERROR) {
            error_handler("接收失败");
        } else if (bytes_received == 0) {
            printf("服务器关闭连接\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("收到服务器响应: %s", buffer);
    }

    closesocket(sock_fd);
    WSACleanup();
    printf("连接已关闭\n");
    return 0;
}