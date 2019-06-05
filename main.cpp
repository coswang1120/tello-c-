#include<WinSock2.h>
#include<stdio.h>
#include<iostream>
#include <conio.h>
#include"tello.h"
using namespace std;
int main()
{
	tello te;
	te.connect();

	
	/*while (1) {
		printf("intput:");
		cin.getline(sendBuff, 20);
		sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
	}*/
	char key = ' ';
	while (1) {
		key = getch();
		switch (key) {
		case 27:
		case 'q':
			//closesocket(sockClient);
			//WSACleanup();
			te.close();
			exit(0);
		case ' ':
			te.takeoff();
			break;
		case 'w':
			te.forward();
			break;
		case 's':
			te.back();
			break;
		case 'a':
			te.left();
			break;
		case 'd':
			te.right();
			break;
		case 'p':
			//strcpy(sendBuff, "land");
			//sendto(sockClient, sendBuff, strlen(sendBuff) + 1, 0, (SOCKADDR*)& addrServer, sizeof(SOCKADDR));
			te.land();
			break;
		default:
			;
		}
	}

	return 0;
}