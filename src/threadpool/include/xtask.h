#ifndef __XTASK__
#define __XTASK__
#include<string>
class XTask
{
public:
	virtual bool Init() {
    return true;
  }

  int sock_ = 0;
	int thread_id_ = 0;
  std::string ipaddr_;
  int port_from_;
  // 初始化任务
  struct event_base* base_ = 0;
};
#endif
