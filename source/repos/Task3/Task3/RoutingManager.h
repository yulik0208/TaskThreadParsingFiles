#pragma once
#include <experimental/filesystem>
#include <string>
#include <iostream>
#include "TaskManager.h"

class RoutingManager
{
public:
	RoutingManager() = default;
	~RoutingManager();

	void GoThroughAll(const std::experimental::filesystem::path & dir_path);// in this directory
private:
	TaskManager m_Threads;

	std::string getExtension(std::string path);
};

