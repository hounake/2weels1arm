#include "stdafx.h"
#include "App.h"

#include <string>
#include <iostream>

App::App()
{
}


App::~App()
{
}

void App::init(){
	try
	{
		//m_vrepManager.init();
	}
	catch (const std::string & msg)
	{
		std::cerr << msg << std::endl;
	}
	//m_fileManager.createDir();

	/*std::vector<Robot> totoVec;
	totoVec.push_back(Robot());
	std::map<int, std::vector<Robot>> totoMap;
	totoMap.emplace(42, totoVec);*/

	//m_fileManager.createGeneLog(totoMap, 0);

	//auto gene = m_fileManager.initGeneFromFile(0);
	//m_fileManager.createGeneLog(gene, 0);//test by recreating file
}

void App::run(){
	init();
	// Vrep Init 
	//while (42/*m_currentGen < m_fileManager*/) // while getconf
	//{
		/*for each (auto it in m_robots)
		{
			m_vrepManager.execRobot(it)
		}
		m_algoGen.selection(m_robots);
		m_algoGen.mating(m_robots);
		m_algoGen.mutate();
		m_robots.clear();
		m_robots = m_algoGen.getNewGene();*/
		// m_fileManager   write loggs
	//}
}