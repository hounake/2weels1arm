#include "stdafx.h"
#include "App.h"


App::App()
{
}


App::~App()
{
}

void App::init(){

}

void App::run(){
	init();
	// Vrep Init 
	while (42/*m_currentGen < m_fileManager*/) // while getconf
	{
		for each (auto it in m_robots)
		{
			//m_vrepManager.execRobot(it)
		}
		m_algoGen.selection(m_robots);
		m_algoGen.mating(m_robots);
		m_algoGen.mutate();
		m_robots.clear();
		m_robots = m_algoGen.getNewGene();
		// m_fileManager   write loggs
	}
}