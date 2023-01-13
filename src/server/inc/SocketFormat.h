#ifndef __SOCKETFORMAT_H__
#define __SOCKETFORMAT_H__

#include "Format.h"

    #ifdef LINUX
    #include <sys/socket.h>
    #include <arpa/inet.h>
    typedef int SOCKET_t;
    #endif

    #ifdef WINDOWS
    #include <windows.h>
    #include <winsock2.h>
    typedef SOCKET SOCKET_t;
    #endif

void InitSocket(void);
SOCKET_t CreateSocket(int af,int type,int protocol);
int BindSocket(SOCKET_t,SOCKADDR_IN);
int UDPSend(SOCKET_t,SOCKADDR_IN,void *,size_t);
int UDPRecv(SOCKET_t,SOCKADDR_IN *,void *,size_t);

#endif