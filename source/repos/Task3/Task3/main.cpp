#include <experimental/filesystem>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

#include "RoutingManager.h"
#include "CodeParser.h"

int main()
{
	RoutingManager rm;
	rm.GoThroughAll("C:\\Users\\Darrin DeYoung\\source\\repos\\Task2");
	system("pause");
	return 0;
}