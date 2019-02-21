#pragma once
#include <thread>
#include <string>
#include "safe_queue.h"
#include "CodeParser.h"
class TaskManager
{
public:
	TaskManager();
	void RunThread(std::string path);
	void JoinThreads();
	void EndThreads();
	~TaskManager();
private:
	unsigned int			m_ThreadsCounter; 
	unsigned int			m_ThreadsCount;
	unsigned int			m_ThreadsIterator;
	std::thread*			m_Threads;
	SafeQueue*				m_ThreadsQueue;
	std::vector<CodeParser>	m_CodeOfFiles;

	void runThread(unsigned int queueNum);
};

