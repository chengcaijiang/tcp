#include <stdio.h>
#include <winsock2.h>
// #pragma comment(lib, "ws2_32.lib") // 链接到Winsock库

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, newConnection;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    // 初始化Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Winsock Initialization failed.\n");
        return 1;
    }

    // 创建套接字
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        printf("Socket creation failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // 设置服务器信息
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080); // 端口号

    // 绑定套接字
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Bind failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 监听连接
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("Waiting for connections...\n");

    // 接受连接
    newConnection = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (newConnection == INVALID_SOCKET) {
        printf("Accept failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    } else {
        char recvBuff[512];
        int bytesReceived = recv(newConnection, recvBuff, sizeof(recvBuff), 0);
        recvBuff[bytesReceived] = '\0';
        printf("Received: %s\n", recvBuff);
        closesocket(newConnection);
    }

    // 清理
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}