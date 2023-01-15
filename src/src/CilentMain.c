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

void setaddr(void)
{
    int port;
    char ip[256];
    SOCKADDR_IN saddr;
    read(&port,ip);
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(port);
    saddr.sin_addr.S_un.S_addr=inet_addr(ip);
    ConnectSocket(sock,saddr);
}

int main(int argc,char *argv[])
{
    InitSocket();
    sock=CreateSocket(PF_INET,SOCK_DGRAM,0);
    return 0;
}