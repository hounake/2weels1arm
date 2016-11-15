#include "stdafx.h"
#include "App.h"
#include "ToolBox.h"

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
		std::cout << "Logger initialisation." << std::endl;
		m_loggManager.init();
		std::cout << "Logger initialisation : done." << std::endl;

		std::cout << "Configuration initialisation." << std::endl;
		m_conf.init(CONFNAME);
		std::cout << "Configuration initialisation : done." << std::endl;

		std::cout << "Vrep initialisation." << std::endl;
		m_vrepManager.init();
		std::cout << "Vrep initialisation : done." << std::endl;

		std::cout << "Robots initialisation." << std::endl;
		if (!m_conf.isRobotExist()) {
			for (size_t i = 0; i < m_conf.getGenerationSize(); i++)
			{
				m_robots.emplace_back(new Robot{});
				m_robots.back()->randomise(m_conf.getRobotActionNumber());
			}
		}
		else
		{
			std::vector<Action> actions = m_conf.getAction();

			m_robots.emplace_back(new Robot{});
			for each (auto action in actions)
			{
				m_robots.back()->addAction(action);
			}
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
			m_vrepManager.execRobot(*robot, m_conf.getRobotSequenceNumber(), m_conf.isRobotExist());
		}
		m_algoGen.selection(m_robots);
		m_algoGen.mating(m_robots, m_conf.getElitismNumber());
		m_algoGen.mutate(m_robots, m_conf.getElitismNumber());
		m_loggManager.writeLine("Generation: " + std::to_string(m_currentGen));

		double ratio = 0;
		for each (auto robot in m_robots)
		{
			std::ostringstream loggline;
			for each (auto actions in robot->getAction())
			{
				loggline << actions->elbow.first << ","
					<< actions->elbow.second << ","
					<< actions->shoulder.first << ","
					<< actions->shoulder.second << ","
					<< actions->wrist.first << ","
					<< actions->wrist.second << ";";
			}
			m_loggManager.writeLine(loggline.str());
			ratio += robot->getScore();
			delete robot;
		}
		m_loggManager.writeCsvLine(std::to_string(m_currentGen) + ";" + std::to_string(m_robots[0]->getScore()) + ";" + std::to_string(ratio / m_conf.getGenerationSize()));

		m_robots.clear();
		m_robots = m_algoGen.getNewGene();
		std::cout << "Generation:" << m_currentGen << std::endl;
		m_currentGen++;
	}
}