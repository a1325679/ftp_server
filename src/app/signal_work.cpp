#include <signal.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <signal.h>
#include <process.h>
#include <thread>
#endif
#include <iostream>
#include "macor.h"
#include "log.h"
#include "func.h"
using namespace std;
void SignalHandler(int signo)
{
#ifndef _WIN32
  switch (signo)
  {
  case SIGHUP:
    log(NOTICE, "%d 接收到 SIGHUP 信号,FTP服务已终止！", getpid());
    ClearWork();
    exit(0);
    break;
  case SIGQUIT:
    log(NOTICE, "%d 接收到 SIGQUIT 信号,FTP服务已终止！", getpid());
    ClearWork();
    exit(0);
    break;

  case SIGINT:
    log(NOTICE, "%d 接收到 SIGINT 信号,FTP服务已终止！", getpid());
    ClearWork();
    exit(0);
  }
#else
  log(NOTICE, "%d 接收到 SIGINT 信号,FTP服务已终止！", getpid());
  ClearWork();
  exit(0);
#endif
}

bool InitSignal()
{
#ifdef _WIN32
  signal(SIGINT, SignalHandler);
#else
  signal(SIGHUP, sigcb);
  signal(SIGINT, sigcb);
  signal(SIGQUIT, sigcb);
#endif
  return true;
}