#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__
#include<vector>
class XTask;
class XThread;
class XThreadPool
{
public:
	static XThreadPool* Get() {
		static XThreadPool pool;
		return &pool;
	}
	void Init(int thread_count);

	void Dispatch(XTask* task);
private:
	unsigned int thread_count_ = 0;
	unsigned int last_thread_ = -1;
	std::vector<XThread*> threads_;
	XThreadPool(){
	}
};
#endif
