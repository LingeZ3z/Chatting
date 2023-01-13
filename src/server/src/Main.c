#include <stdio.h>
#include <stdlib.h>
#include "./../inc/Format.h"
#include "./../inc/SocketFormat.h"
#include "./../inc/cJSON.h"

SOCKET_t sock;


void read(int *port)
{
    char *buf=malloc(4096);
    FILE *f=fopen("./config.json","r");
    fread(buf,4096,1,f);
    fclose(f);
    cJSON *cjson=cJSON_Parse(buf);
    cJSON *jport=cJSON_GetObjectItem(cjson,"port");
    *port=jport->valueint;
    free(buf);
    free(cjson);
    free(jport);
}

void setaddr(void)
{
    int port;
    read(&port);
    SOCKADDR_IN saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family=PF_INET;
    saddr.sin_port=htons(port);
    saddr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    BindSocket(sock,saddr);
}

void server(void)
{
    char buf[256];
    SOCKADDR_IN cadr;
    while(1)
    {
        UDPRecv(sock,&cadr,buf,256);
        printf("%s\n",buf);
        memset(buf,0,256);
    }
}

int main(int argc,char *argv[])
{
    InitSocket();
    sock=CreateSocket(PF_INET,SOCK_DGRAM,0);
    setaddr();
    server();
    return 0;
}