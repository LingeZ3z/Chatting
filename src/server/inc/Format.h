#ifndef __FORMAT_H__
#define __FORMAT_H__

#define WINDOWS

#define BUF_SIZE 1024
typedef struct
{
    SOCKADDR_IN addr;
    char buf[BUF_SIZE];
}INETMSG;

#endif