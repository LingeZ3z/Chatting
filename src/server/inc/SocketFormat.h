#ifndef __SOCKETFORMAT_H__
#define __SOCKETFORMAT_H__

#include "Format.h"

#ifdef LINUX
typedef t_SOCKET int;
#endif

#ifdef WINDOWS
#include <windows.h>
#include <winsock2.h>
typedef t_SOCKET SOCKET;
#endif

void InitSocket(void);
t_SOCKET CreateSocket(void);

#endif