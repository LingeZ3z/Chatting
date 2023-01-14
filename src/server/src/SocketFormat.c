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
    printf("%d\n",re);
}

int UDPSend(SOCKET_t sock,SOCKADDR_IN saddr,void *msg,size_t len)
{
    sendto(sock,msg,len,0,(SOCKADDR*)&saddr,sizeof(saddr));
}

int UDPRecv(SOCKET_t sock,SOCKADDR_IN* saddr,void *msg,size_t len)
{
    int l=sizeof(SOCKADDR);
    recvfrom(sock,msg,len,0,(SOCKADDR*)saddr,&l);
}
