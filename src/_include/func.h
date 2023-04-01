#ifndef _FUNC_H
#define _FUNC_H
#include<vector>
#include<string>
typedef void *HANDLE;
void Rtrim(char *str);
void Ltrim(char *str);
bool InitSignal();
bool LogSignal();
void ClearWork();

int ftp_daemon();
int ftp_init(const char* conf_path = "conf.conf");
HANDLE GetHandleFromProcessName(const char *process_name);
void split(const std::string& s, std::vector<std::string>& sv,const char flag = ' ');
#endif