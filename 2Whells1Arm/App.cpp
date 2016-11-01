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
		std::cout << "Vrep initialisation." << std::endl;
		m_vrepManager.init();
		std::cout << "Vrep initialisation : done." << std::endl;

		std::cout << "Robots initialisation." << std::endl;

		for (size_t i = 0; i < PPLPERGENERATION; i++)
		{
			m_robots.emplace_back(new Robot{});
			m_robots.back()->randomise();
		}

		std::cout << "Robots initialisation : Done." << std::endl;
	}
	catch (const std::string & msg)
	{
		std::cerr << msg << std::endl;
	}
	//m_fileManager.createDir();

	//std::vector<Robot> totoVec;
	//totoVec.push_back(Robot());
	//std::map<int, std::vector<Robot>> totoMap;
	//totoMap.emplace(42, totoVec);

	//m_fileManager.createGeneLog(totoMap, 0);

	//auto gene = m_fileManager.initGeneFromFile(0);
	//m_fileManager.createGeneLog(gene, 0);//test by recreating file
}

void App::run(){
	init();
	while (m_currentGen != 1) // while getconf
	{
		for each (auto robot in m_robots)
		{
			m_vrepManager.execRobot(*robot);
		}
		/*m_algoGen.selection(m_robots);
		m_algoGen.mating(m_robots);
		m_algoGen.mutate();
		m_robots.clear();
		m_robots = m_algoGen.getNewGene();*/
		// m_fileManager   write loggs
		std::cout << "Generation:" << m_currentGen << std::endl;
		m_currentGen++;
	}
}