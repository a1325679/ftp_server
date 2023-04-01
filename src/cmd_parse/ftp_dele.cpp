#include "ftp_dele.h"
#include "macor.h"
#include "log.h"
#include <string>
#ifdef _WIN32
#include <direct.h>
#include <io.h>
#else
#include <unistd.h>
#endif
#include <iostream>
// Dele text.txt\r\n
void FtpDele::Parse(std::string type, std::string msg)
{
  if (msg.find("\r\n") != std::string::npos)
  {
    msg.pop_back();
    msg.pop_back();
  }
  log(NOTICE, "%s:%d -> 解析命令%s,命令内容为%s", ipaddr.c_str(), portFrom, type.c_str(), msg.c_str());

  int pos = msg.find(" ");
  std::string file_name = rootDir + cmdTask->curDir+"/"+ msg.substr(pos + 1);

  if (remove(file_name.c_str()) != 0)
  {
    log(NOTICE, "%s:%d -> 删除文件 %s 失败 : %s:%d ", ipaddr.c_str(), portFrom,file_name.c_str(),__FILE__, __LINE__);
    ResCMD("220" + file_name + "delete failed. \r\n");
    return;
  }
  ResCMD("250 " + file_name + " success delete." + "\r\n");
  return;
}