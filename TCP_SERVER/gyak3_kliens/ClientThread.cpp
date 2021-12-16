#include "ClientThread.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;



ClientThread::ClientThread(SOCKET socket, list<ClientThread*>* threadList, CRITICAL_SECTION* criticalSection)
{
    this->ClientSocket = socket;
    this->criticalSection = criticalSection;
    this->threadList = threadList;
    PufferHossz = 1024;
    const char* kezdetiErtek = "\0";
    
    memcpy(Puffer, kezdetiErtek, PufferHossz);
}

void ClientThread::run()
{
    int recvValasz = -1;
    int sendValasz = -1;
    const char delim = '~';
    ClientThread* temporalisThread = NULL;

    while (1) {
        std::vector<std::string> out;
        recvValasz = recv(this->ClientSocket, Puffer, PufferHossz, 0);
        bool isEveryoneMsg = false;
        bool isPM = false;
        bool isGetUsers = false;
        //cout << recvValasz << "\n";
       
        //cout << Puffer << endl;
        //Itt allitom be, hogy mi legyen a 
        
        
       
        if (recvValasz == SOCKET_ERROR) {
            cout << "Hiba lepett fel a recv-nel a kovetkezo hibakoddal: " << WSAGetLastError() << "\n";

            closesocket(this->ClientSocket);

            return;
        }
        tokenize(Puffer, delim, out);
        vector<int> header = { stoi(out[0]),stoi(out[1]), stoi(out[2]),stoi(out[3]) };
        string message = out[4];
        //cout << message;
        //Puffer[header[0]] = '\0';
        auto tempLista = *this->threadList;

        char users[] = "getUsers()";

        //a lenti for ciklust betesszuk kritikus szekcioba, hogy addig amig valamelyik thread ezzel a kodreszlettel dolgozik addig masok varakozzanak utana
        EnterCriticalSection(this->criticalSection);

        
       
        
        
        //itt jonne az a for ciklus, ami majd minden egyes kliensnek(socketjenek megfeleloen) visszakuldi ugyanazt az uzenetet, ergo mindenki ugyanazt fogja majd visszakapni
        for (auto kurensThread : tempLista) {
            //cout << sizeof(Puffer) << endl;
            
            unsigned long long finalLength = 0;
            vector<string> socketek;
            //hogyha a kurens thread nem lepett ki akkor elkuldi az uzenetet, ellenkezo esetben felszabaditjuk ot a memoriabol
            if (!kurensThread->isExited()) {
                //itt kuldom vissza a listat
                cout << "Current thread: " << kurensThread->ClientSocket << endl;
                //memcpy(Puffer, "\0", PufferHossz);

                if (!message.compare(users))
                {
                    //cout << "socketek lista elott" << to_string(kurensThread->ClientSocket) << endl;
                    //cout << "getUsers called" << endl;
                    for (auto const& i : tempLista) {

                        if (find(socketek.begin(), socketek.end(), to_string(i->ClientSocket)) == socketek.end()) {
                            socketek.push_back(to_string(i->ClientSocket));
                            //cout << i->ClientSocket << endl;
                        }
                        
                            
                        
                    }
                    cout << "A socketek lista merete: " << socketek.size() << endl;
                    
                    string str = "x~0~";
                    //cout << "socketek lista utan" << to_string(kurensThread->ClientSocket) << endl;
                    string kitol = to_string(this->ClientSocket);
                    //string kitol = to_string(header[1]);
                    str.append(kitol);//kitol megy
                    str.append("~");
                    string kinek = to_string(kurensThread->ClientSocket);
                    //string kinek = to_string(header[2]);
                    str.append(kinek);//kinek megy
                    str.append("~");
                    str.append(to_string(kurensThread->ClientSocket));
                    
                    
                    if (socketek.size() > 1)
                    {
                    
                        for (int i = 0; i < socketek.size(); ++i)
                        {
                            if (socketek[i].compare(to_string(this->ClientSocket)) != 0)
                            {
                                str.append("~");
                                str.append(socketek[i]);
                            }
                            
                        }
                    }
                    
                    //cout << str << endl;
                    //cout << kurensThread->ClientSocket;
                    //cout << str.length() << endl;
                    //memcpy(Puffer, "\0", PufferHossz);
                    //memcpy(Puffer, "\0", PufferHossz);
                    string str2 = str.substr(1, str.length()-1);
                    int tempsize = str2.length();
                    int finalsize = tempsize+ int(log10(tempsize) + 1);
                    string finalstring = to_string(finalsize) + str2;
                    char* char_arr;
                    char_arr = &finalstring[0];
                    //memcpy(Puffer, char_arr, strlen(char_arr));
                    memcpy(Puffer, finalstring.c_str(), finalstring.length());

                    Puffer[finalstring.length()] = '\0';
                    
                    //cout << str2.c_str() << endl;

                    Puffer[finalsize] = '\0';
                    //cout << Puffer << endl;
                    finalLength = strlen(char_arr);
                    //cout << finalLength << endl;
                    //cout << strlen(finalstring.c_str()) << " finalstring hossz = " << finalsize << "finalsize" << endl;
                    isGetUsers = true;
                }

                if (header[1] == 1)
                {
                    //cout << "Message type" << endl;
                    string str = "0~1~";

                    string kitol = to_string(this->ClientSocket);
                    //string kitol = to_string(header[1]);
                    str.append(kitol);//kitol megy
                    str.append("~");
                    string kinek = to_string(kurensThread->ClientSocket);
                    //string kinek = to_string(header[2]);
                    str.append(kinek);//kinek megy
                    str.append("~");
                    str.append(message);
                    string str2 = str.substr(1, str.length() - 1);
                    int tempsize = str2.length();
                    int finalsize = tempsize + int(log10(tempsize) + 1);
                    string finalstring = to_string(finalsize) + str2;
                    char* char_arr;
                    char_arr = &finalstring[0];
                    memcpy(Puffer, finalstring.c_str(), finalstring.length());
                    
                    Puffer[finalstring.length()] = '\0';
                    //Puffer[strlen(finalstring.c_str())] = '\0';
                    //cout << str2 << endl;
                    //Puffer[finalstring.length()] = '\0';
                    finalLength = strlen(char_arr);
                    //cout << strlen(Puffer) << endl;
                    //cout << finalLength << endl;
                    isEveryoneMsg = true;
                }

                if (header[1] == 2)
                {
                    //cout << "Message type" << endl;
                    string str = "x~2~";

                    string kitol = to_string(this->ClientSocket);
                    //string kitol = to_string(header[1]);
                    str.append(kitol);//kitol megy
                    str.append("~");
                    string kinek = to_string(header[3]);
                    //string kinek = to_string(header[2]);
                    str.append(kinek);//kinek megy
                    str.append("~");
                    str.append(message);
                    string str2 = str.substr(1, str.length() - 1);
                    int tempsize = str2.length();
                    int finalsize = tempsize + int(log10(tempsize) + 1);
                    string finalstring = to_string(finalsize) + str2;
                    char* char_arr;
                    char_arr = &finalstring[0];
                    memcpy(Puffer, finalstring.c_str(), finalstring.length());

                    Puffer[finalstring.length()] = '\0';
                    //Puffer[strlen(finalstring.c_str())] = '\0';
                    //cout << str2 << endl;
                    //Puffer[finalstring.length()] = '\0';
                    finalLength = strlen(char_arr);
                    //cout << strlen(Puffer) << endl;
                    //cout << finalLength << endl;
                    isPM = true;
                }
                //cout << Puffer << endl;
                //cout << kurensThread->ClientSocket << endl;
                
                cout << Puffer << endl;
                if (isEveryoneMsg || isGetUsers)
                {
                    sendValasz = send(kurensThread->ClientSocket, Puffer, PufferHossz, 0);
                    if (sendValasz == SOCKET_ERROR) {
                        cout << "Hiba lepett fel a send utasitasnal a kovetkezo hibakoddal: " << WSAGetLastError() << "\n";

                        closesocket(kurensThread->ClientSocket);
                    }
                    else {
                        //ha NEM lett elkuldve a teljes uzenet , akkor azt a reszet probalom ujra atkuldeni amit nem sikerult korabban

                        while (sendValasz != PufferHossz) {
                            sendValasz = send(this->ClientSocket, Puffer + sendValasz, PufferHossz - sendValasz, 0);
                        }

                    }
                    isEveryoneMsg = false;
                    isGetUsers = false;
                }
                if (isPM)
                {
                    isPM = false;
                    for (auto const& i : tempLista) {;
                        //cout << header[3] << endl;
                        if (to_string(i->ClientSocket).compare(to_string(header[3])) == 0) { 
                            
                            sendValasz = send(i->ClientSocket, Puffer, PufferHossz, 0);
                            if (sendValasz == SOCKET_ERROR) {
                                cout << "Hiba lepett fel a send utasitasnal a kovetkezo hibakoddal: " << WSAGetLastError() << "\n";

                                closesocket(i->ClientSocket);
                            }
                            else {
                                //ha NEM lett elkuldve a teljes uzenet , akkor azt a reszet probalom ujra atkuldeni amit nem sikerult korabban

                                while (sendValasz != PufferHossz) {
                                    sendValasz = send(i->ClientSocket, Puffer + sendValasz, PufferHossz - sendValasz, 0);
                                }

                            }
                            break;
                        }



                    }
                    

                }
                
            }
            else {
                //a kurens thread mar kilepet,ezert ot fel kell szabaditani a memoriabol
                temporalisThread = kurensThread;

                threadList->remove(kurensThread);
                
                delete temporalisThread;

                temporalisThread = NULL;
            }
        }

        LeaveCriticalSection(this->criticalSection);
        
    }

    //shutdown(this->ClientSocket, 2);

    //closesocket(this->ClientSocket);

}

void ClientThread::tokenize(std::string const& str, const char delim,
    std::vector<std::string>& out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
