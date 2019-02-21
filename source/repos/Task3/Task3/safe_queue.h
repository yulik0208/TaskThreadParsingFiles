#ifndef SAFE_QUEUE
#define SAFE_QUEUE

#include <queue>
#include <mutex>
#include <condition_variable>

// A threadsafe-queue.

class SafeQueue
{
public:
	SafeQueue(void)
		: m_queue()
		, m_mutex()
		, m_condition()
	{}

	~SafeQueue(void)
	{}

	// Add an element to the queue.

	void enqueue(std::string t)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_queue.push(t);
		//std::cout << "added" << std::endl;
		m_condition.notify_one();

	}
	

	// Get the "front"-element.
	// If the queue is empty, wait till a element is avaiable.
	
	std::string dequeue(void)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		while (m_queue.empty())
		{
			//std::cout << " WAITNIG!!" << std::endl;
			// release lock as long as the wait and reaquire it afterwards.
			m_condition.wait(lock);
		}
		std::string val = m_queue.front();
		m_queue.pop();
		return val;
	}
	

private:
	std::queue<std::string> m_queue;
	mutable std::mutex m_mutex;
	std::condition_variable m_condition;
};
#endif


