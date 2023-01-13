#include <stdio.h>
#include <stdlib.h>
#include "./../inc/Format.h"
#include "./../inc/SocketFormat.h"
#include "./../inc/cJSON.h"

SOCKET_t sock;
int port;

void read(void)
{
    char *buf=malloc(4096);
    FILE *f=fopen("./config.json","r");
    fread(buf,4096,1,f);
    fclose(f);
    cJSON *cjson=cJSON_Parse(buf);
    cJSON *jport=cJSON_GetObjectItem(cjson,"port");
    port=jport->valueint;
}

int main(int argc,char *argv[])
{
    InitSocket();
    sock=CreateSocket(PF_INET,SOCK_DGRAM,0);
    
    return 0;
}