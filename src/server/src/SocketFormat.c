#include "./../inc/SocketFormat.h"

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
    bind(sock,&saddr,sizeof(saddr));
}

int UDPSend(SOCKET_t sock,SOCKADDR_IN saddr,void *msg,size_t len)
{
    sendto(sock,msg,len,0,&saddr,sizeof(saddr));
}

int UDPRecv(SOCKET_t sock,SOCKADDR_IN* saddr,void *msg,size_t len)
{
    recvfrom(sock,msg,len,0,saddr,sizeof((*saddr)));
}
