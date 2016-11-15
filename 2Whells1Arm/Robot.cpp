#include "stdafx.h"
#include "Robot.h"

Robot::Robot()
{
}

Robot::~Robot()
{
	for (size_t i = 0; i < m_actions.size(); i++)
	{
		delete m_actions.at(i);
	}
}

void Robot::randomise(int actionNumber) {
	for (int i = 0; i < actionNumber; i++)
	{
		m_actions.emplace_back(new Action{});
		m_actions.back()->randomise();
	}
}

void Robot::addAction(Action action) {
	m_actions.emplace_back(new Action{action});
}
