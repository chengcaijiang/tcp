/*
 ======================
 服务端代码 (server.c) - Windows版本
 ======================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <winsock2.h>  // Windows专用头文件

#pragma comment(lib, "ws2_32.lib") // 链接Winsock库

#define PORT 12345
#define BUFFER_SIZE 1024

void error_handler(const char *message) {
    fprintf(stderr, "错误: %s (错误代码: %d)\n", message, WSAGetLastError());
    exit(EXIT_FAILURE);
}

int main() {
    WSADATA wsaData;
    SOCKET server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // 初始化Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        error_handler("Winsock初始化失败");
    }

    // 创建TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        error_handler("socket创建失败");
    }

    // 绑定地址配置
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 绑定socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        error_handler("绑定失败");
    }

    // 开始监听
    if (listen(server_fd, 5) == SOCKET_ERROR) {
        error_handler("监听失败");
    }
    printf("服务器已启动，正在监听端口 %d...\n", PORT);

    while (1) {
        // 接受客户端连接
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len)) == INVALID_SOCKET) {
            fprintf(stderr, "接受连接失败 (错误代码: %d)\n", WSAGetLastError());
            continue;
        }
        printf("接收到来自 %s 的连接\n", inet_ntoa(client_addr.sin_addr));

        // 处理客户端请求
        while (1) {
            int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (bytes_received == SOCKET_ERROR) {
                fprintf(stderr, "接收错误 (错误代码: %d)\n", WSAGetLastError());
                break;
            } else if (bytes_received == 0) {
                printf("客户端关闭连接\n");
                break;
            }

            // 处理数据：转换为大写
            buffer[bytes_received] = '\0';
            printf("收到数据: %s", buffer);
            for (int i = 0; i < bytes_received; i++) {
                buffer[i] = toupper(buffer[i]);
            }

            // 发送响应
            if (send(client_fd, buffer, bytes_received, 0) == SOCKET_ERROR) {
                fprintf(stderr, "发送失败 (错误代码: %d)\n", WSAGetLastError());
                break;
            }
            printf("已发送响应: %s", buffer);
        }

        closesocket(client_fd);
        printf("连接已关闭\n\n");
    }

    closesocket(server_fd);
    WSACleanup();
    return 0;
}

