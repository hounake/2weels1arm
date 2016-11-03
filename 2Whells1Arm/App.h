#pragma once

#include <map>
#include <vector>
#include "Robot.h"
#include "FileManager.h"
#include "AlgoGen.h"
#include "Vrep.h"

extern "C" {
#include "extApi.h"
}

class App
{
	//FileManager m_fileManager;
	AlgoGen m_algoGen;
	//Vrep m_vrepManager;

	std::map<int, std::vector<Robot>> m_robots;
	int m_currentGen;
	simxInt RoboHandle;

	void m_initFromNothing();
public:
	App();
	~App();

	void init();

	void run();
};
