#ifndef _GLOBAL_H
#define _GLOBAL_H
#include "threadpool.h"
typedef struct{
	char ItemName[50];
	char ItemContent[500];
}ConfItem,*LPConfItem;

extern ThreadPool *g_pool_;
extern int thread_count_;
extern unsigned short port_;
extern const char *root_path_;

#endif