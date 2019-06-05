#pragma once
#include <WinSock2.h>
#include <stdio.h>
#include<iostream>
#include<string.h>
#pragma comment(lib,"WS2_32.lib")

using namespace std;
class tello
{
public:
	
	void connect();
	void left();
	void right();
	void forward();
	void back();
	void takeoff();
	void land();
	void close();
private:
	char sendBuff[20];
	SOCKET sockClient;
	SOCKADDR_IN addrServer;
};
