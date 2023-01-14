#include <stdio.h>
#include <stdlib.h>
#include "./../inc/Format.h"
#include "./../inc/SocketFormat.h"
#include "./../inc/cJSON.h"

SOCKET_t sock;
SOCKADDR_IN *clnts;
int cnt;

void read(int *port)
{
    char *buf=malloc(4096);
    FILE *f=fopen("./config.json","r");
    fread(buf,4096,1,f);
    fclose(f);
    cJSON *cjson=cJSON_Parse(buf);
    cJSON *jport=cJSON_GetObjectItem(cjson,"port");
    *port=jport->valueint;
    cJSON *maxconn=cJSON_GetObjectItem(cjson,"max-connection");
    int t=maxconn->valueint;
    clnts=malloc(sizeof(SOCKADDR_IN)*t);
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
    SOCKADDR_IN saddr;
    char buf[1024];
    int len=1024;
    while(1)
    {
        INETMSG inetmsg;
        UDPRecv(sock,&inetmsg.addr,inetmsg.buf,BUF_SIZE);
        if(memcmp(buf,"__$$$__add",11))
        {
            clnts[cnt++]=saddr;
        }
        else
        {
            for(int i=0;i<cnt;i++)
            {
                UDPSend(sock,clnts[i],&inetmsg,sizeof(inetmsg));
            }
        }
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