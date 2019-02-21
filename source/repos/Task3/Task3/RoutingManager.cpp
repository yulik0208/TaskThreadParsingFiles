#include "RoutingManager.h"



void RoutingManager::GoThroughAll(const std::experimental::filesystem::path & dir_path)
{
	if (!exists(dir_path)) return;

	std::experimental::filesystem::directory_iterator end_itr; // default construction yields past-the-end
	for (std::experimental::filesystem::directory_iterator itr(dir_path);
		itr != end_itr;
		++itr)
	{
		//std::cout << itr->path() << std::endl;

		if (is_directory(itr->status()))
		{
			GoThroughAll(itr->path());
		}
		else
		{
			std::string extension = getExtension(itr->path().generic_string());
			if ("h" == extension || "hpp" == extension || "c" == extension || "cpp" == extension)
			{
				m_Threads.RunThread(itr->path().generic_string());
			}
		}
	}

}
RoutingManager::~RoutingManager()
{
	m_Threads.EndThreads();
	m_Threads.JoinThreads();
	m_Threads.~TaskManager();
}


std::string RoutingManager::getExtension(std::string path)
{	
	std::string::iterator itr = path.end();
	--itr;
	std::string str = "";
	while (*itr != '.')
	{
		--itr;
	}
	++itr;
	while (itr != path.end())
	{
		str += *itr;
		++itr;
	}

	return str;
}
