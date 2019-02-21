#include "TaskManager.h"
#include <chrono>
#include <iostream>


void TaskManager::JoinThreads()
{
	for (size_t i = 0; i < m_ThreadsCounter; ++i)
	{
		if (m_Threads[i].joinable())
		{
			m_Threads[i].join();
		}
	}
}

void TaskManager::EndThreads()
{
	for (size_t i = 0; i < m_ThreadsCounter; ++i)
	{
		m_ThreadsQueue[i].enqueue("End parsing");
	}
}

void TaskManager::runThread(unsigned int queueNum)
{
	while (true)
	{
		
		std::string data = m_ThreadsQueue[queueNum].dequeue();
		if ("End parsing" == data)
		{
			break;
		}
		else 
		{
			m_CodeOfFiles.push_back(CodeParser());
			m_CodeOfFiles[m_CodeOfFiles.size() - 1].DivideOnLines(data);
			m_CodeOfFiles[m_CodeOfFiles.size() - 1].PrintFile();
		}
	}
}

TaskManager::TaskManager()
{
	m_ThreadsCounter = 0;
	m_ThreadsIterator = 0;
	m_ThreadsCount = std::thread::hardware_concurrency();
	m_Threads = new std::thread[m_ThreadsCount];
	m_ThreadsQueue = new SafeQueue[m_ThreadsCount];
}

void TaskManager::RunThread(std::string path)
{
	
	if (m_ThreadsIterator == m_ThreadsCount)
	{
		m_ThreadsIterator = 0;
	}
	if (m_ThreadsCounter < m_ThreadsCount)
	{
		m_Threads[m_ThreadsCounter] = std::thread(&TaskManager::runThread, this, m_ThreadsCounter++);
	}
	m_ThreadsQueue[m_ThreadsIterator++].enqueue(path);
	
}


TaskManager::~TaskManager()
{
	m_CodeOfFiles.clear();
	delete[] m_Threads;
	delete[] m_ThreadsQueue; 
}
