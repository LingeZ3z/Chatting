#ifndef __SOCKETFORMAT_H__
#define __SOCKETFORMAT_H__

#include "Format.h"

#ifdef LINUX
#include <sys/socket.h>
#include <arpa/inet.h>
typedef int t_SOCKET;
#endif

#ifdef WINDOWS
#include <windows.h>
#include <winsock2.h>
typedef SOCKET t_SOCKET;
#endif

void InitSocket(void);
t_SOCKET CreateSocket(void);


#endif