#include "./../inc/SocketFormat.h"
#include <stdio.h>

void InitSocket(void)
{
#ifdef WINDOWS
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);
#endif
}

SOCKET_t CreateSocket(int af,int type,int protocol)
{
    SOCKET_t sock;
    sock=socket(af,type,protocol);
    return sock;
}

int BindSocket(SOCKET_t sock,SOCKADDR_IN saddr)
{
    int re=bind(sock,(SOCKADDR*)&saddr,sizeof(saddr));
    return re;
}

int ConnectSocket(SOCKET_t sock,SOCKADDR_IN saddr)
{
    int re=connect(sock,(SOCKADDR*)&saddr,sizeof(SOCKADDR));
    return re;
}

int UDPSend(SOCKET_t sock,SOCKADDR_IN saddr,void *msg,size_t len)
{
    int re=sendto(sock,msg,len,0,(SOCKADDR*)&saddr,sizeof(saddr));
    return re;
}

int UDPRecv(SOCKET_t sock,SOCKADDR_IN* saddr,void *msg,size_t len)
{
    int l=sizeof(SOCKADDR);
    int re=recvfrom(sock,msg,len,0,(SOCKADDR*)saddr,&l);
    return re;
}

int SetUDPRecvX(SOCKET_t sock)
{
    unsigned long on = 1;
    return ioctlsocket(sock, FIONBIO, &on);
}