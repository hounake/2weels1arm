#include "stdafx.h"
#include "App.h"

#include <string>
#include <iostream>

App::App()
{
}

App::~App()
{
	for each (auto robot in m_robots)
	{
		delete robot;
	}
}

void App::init(){
	try
	{
		std::cout << "Configuration initialisation." << std::endl;
		m_conf.init(CONFNAME);
		std::cout << "Configuration initialisation : done." << std::endl;

		std::cout << "Vrep initialisation." << std::endl;
		m_vrepManager.init();
		std::cout << "Vrep initialisation : done." << std::endl;

		std::cout << "Robots initialisation." << std::endl;

		for (size_t i = 0; i < m_conf.getGenerationSize(); i++)
		{
			m_robots.emplace_back(new Robot{});
			m_robots.back()->randomise(m_conf.getRobotActionNumber());
		}

		std::cout << "Robots initialisation : Done." << std::endl;
	}
	catch (const std::string & msg)
	{
		std::cerr << msg << std::endl;
	}
}

void App::run(){

	init();

	while (m_currentGen != m_conf.getFinalGeneration())
	{
		for each (auto robot in m_robots)
		{
			m_vrepManager.execRobot(*robot, m_conf.getRobotSequenceNumber());
		}
		m_algoGen.selection(m_robots);
		m_algoGen.mating(m_robots);
		m_algoGen.mutate();
		for each (auto robot in m_robots)
		{
			delete robot;
		}
		m_robots.clear();
		m_robots = m_algoGen.getNewGene();
		// m_fileManager   write loggs
		std::cout << "Generation:" << m_currentGen << std::endl;
		m_currentGen++;
	}
}