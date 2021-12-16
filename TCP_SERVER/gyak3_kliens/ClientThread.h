#pragma once

#include "SysThread.h"
#include <iostream>
#include <vector>
#include <string.h>
#include<list>

class ClientThread : public SysThread {
public:
	ClientThread(SOCKET socket, list<ClientThread*>* threadList, CRITICAL_SECTION* criticalSection);
	virtual void run();

private:
	SOCKET ClientSocket;
	list<ClientThread*> *threadList;
	void tokenize(std::string const&, const char, vector<std::string>&);
	CRITICAL_SECTION *criticalSection;
	char Puffer[1024];
	int PufferHossz;
};