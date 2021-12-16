// TPC szerver Thread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h> 
#include <string.h> 
#include "winsock2.h"
#include "ClientThread.h"
#include <list>
#pragma comment(lib, "Ws2_32.lib") 
using namespace std;

void main()
{
    //1.lepes: WSAStartup elinditasa -> .dll konyvtarak beolvasasa
    WSADATA wsaData;

    int WSAStartup_ertek = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (WSAStartup_ertek != NO_ERROR) {
        //hiba lepett fel a WSAStartup soran
        cout << "Hiba lepett fel a WSAStartup soran!\n";
        return;
    }

    //2.Lepes: Létrehozok egy SOCKET-et amelyik a szerverhez kapcsolódik
    SOCKET TCP_Szerver_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (TCP_Szerver_Socket == INVALID_SOCKET) {
        //hogyha hibas a socket,akkor hibauzenetet irok ki
        //felszabaditom a WSAStartup-ot (cleanelem),majd kilepek a programbol

        cout << "Hiba lepett fel a TCP Kliens SOCKET-jenek a letrehozasa soran!\n";

        WSACleanup();

        return;
    }

    //3.lepes: A Szerver SOCKADDR letrehozasa es az adatok feltoltese,ezekkel az adatokkal tudok majd a szerverhez csatlakozni!
    int Port = 13000;
    char IP_cim[] = "127.0.0.1";

    sockaddr_in SockAddr_in;
    SockAddr_in.sin_family = AF_INET; //megadtam a Ping csaladot(cimet) protokolt a szervernek
    SockAddr_in.sin_addr.s_addr = inet_addr(IP_cim); //megadtam a szerver IP cimjet
    SockAddr_in.sin_port = htons(Port); //megadtam a szervehez kapcsolodo portot
    int SockAddr_hossz = sizeof(SockAddr_in); //lementem a SockAddr hosszat

    int bindValasz = bind(TCP_Szerver_Socket, (SOCKADDR*)&SockAddr_in, SockAddr_hossz);

    if (bindValasz == SOCKET_ERROR) {
        cout << "Hiba lepett fel a bind eseten a kovetkezo hibakoddal: " << WSAGetLastError() << "\n";

        closesocket(TCP_Szerver_Socket);

        WSACleanup();

        return;
    }

    int listenValasz = listen(TCP_Szerver_Socket, 0);

    if (listenValasz == SOCKET_ERROR) {
        cout << "Hiba lepett fel a listen eseten a kovetkezo hibakoddal: " << WSAGetLastError() << "\n";

        closesocket(TCP_Szerver_Socket);

        WSACleanup();

        return;
    }

    list<ClientThread*> threadList; //ebben lesznek eltarolva a pointer threadek

    CRITICAL_SECTION criticalSection; //kritikus szekciot hozok letre

    InitializeCriticalSection(&criticalSection);// inicializaljuk a letrehozott kritikus szekcio valtozot

    SOCKET korabbiSocket = 0;

    while (1) {
        //vannak klienseink,ki kell szolgalni oket!

        SOCKET acceptValasz = accept(TCP_Szerver_Socket, (SOCKADDR*)&SockAddr_in, &SockAddr_hossz);

        if (acceptValasz == INVALID_SOCKET) {
            cout << "Hiba lepett fel az accept-nel a kovetkezo hibakoddal: " << WSAGetLastError() << "\n";

            closesocket(TCP_Szerver_Socket);

            WSACleanup();

            return;
        }

        if (korabbiSocket != acceptValasz) {
            //uj kapcsolat jott be, ki kell szolgalni

            //itt letre fogok hozni egy szalat es atadom neki azt a Socketet,amit az Accept visszateritett nekunk
            ClientThread* thread = new ClientThread(acceptValasz, &threadList, &criticalSection);

            //belepek a kritikus szekcioba
            EnterCriticalSection(&criticalSection);

            threadList.push_back(thread); //beteszem a threadeket tarolo listaban a kurens threadet(hogy kesobb tudjunk majd hivatkozni annak socketjehez)

            //kilepek a kritikus szekciobol
            LeaveCriticalSection(&criticalSection);

            //majd elinditom a szalat
            thread->start();

            korabbiSocket = acceptValasz;
        }
    }

    shutdown(TCP_Szerver_Socket, 2);

    closesocket(TCP_Szerver_Socket);

    WSACleanup();
}