#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[256]="114514!!!";
    SOCKADDR_IN saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family=PF_INET;
    saddr.sin_port=htons(8848);
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    SOCKET sock=socket(PF_INET,SOCK_DGRAM,0);
    printf("%d",sendto(sock,buf,strlen(buf),0,(SOCKADDR*)&saddr,sizeof(saddr)));
    printf("\n%s",buf);
    return 0;
}