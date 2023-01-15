#include <stdio.h>
#include <stdlib.h>
#include "./../inc/Format.h"
#include "./../inc/SocketFormat.h"
#include "./../inc/cJSON.h"

SOCKET_t sock;

void read(int *port,char *ip)
{
    char *buf=malloc(4096);
    FILE *f=fopen("./cilent_config.json","r");
    fread(buf,4096,1,f);
    fclose(f);
    cJSON *cjson=cJSON_Parse(buf);
    cJSON *jport=cJSON_GetObjectItem(cjson,"port");
    *port=jport->valueint;
    cJSON *cip=cJSON_GetObjectItem(cjson,"ip");
    strcpy(ip,cip->valuestring);
    free(buf);
    free(cjson);
    free(cip);
}

SOCKADDR_IN setaddr(void)
{
    int port;
    char ip[256];
    SOCKADDR_IN saddr;
    read(&port,ip);
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(port);
    saddr.sin_addr.S_un.S_addr=inet_addr(ip);
    return saddr;
}

void cilent(void)
{
    INETMSG inetmsg;
    SOCKADDR_IN saddr=setaddr();
    UDPSend(sock,(SOCKADDR_IN)saddr,"__$$$__add",11);
    while(1)
    {
        // if(recvfrom())
    }
}

int main(int argc,char *argv[])
{
    InitSocket();
    sock=CreateSocket(PF_INET,SOCK_DGRAM,0);
    SetUDPRecvX(sock);
    return 0;
}