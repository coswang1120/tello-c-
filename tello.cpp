#include "tello.h"
void tello::connect() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0)
	{
		return ;
	}

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return ;
	}

	sockClient = socket(AF_INET, SOCK_DGRAM, 0);


	addrServer.sin_addr.S_un.S_addr = inet_addr("192.168.10.1");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(8889);

	int len = sizeof(SOCKADDR);
}
void tello::takeoff() {
	strcpy(sendBuff, "command");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
	strcpy(sendBuff, "takeoff");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
	printf("takeoff");
}
void tello::forward() {
	cout << "forward" << endl;
	strcpy(sendBuff, "forward 20");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
}
void tello::back() {
	cout << "back" << endl;
	strcpy(sendBuff, "back 20");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
}
void tello::left() {
	cout << "left" << endl;
	strcpy(sendBuff, "left 20");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));

}
void tello::right() {
	strcpy(sendBuff, "right 20");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
	cout << "right" << endl;

}
void tello::close() {
	closesocket(sockClient);
	WSACleanup();
}
void tello::land() {
	strcpy(sendBuff, "land");
	sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
}