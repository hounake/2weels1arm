#include "stdafx.h"
#include "Robot.h"
#include <random>

void Action::randomise() {
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<float> randX(-360.0f, 360.0f);

	wrist.first = randX(randomEngine);
	elbow.first = randX(randomEngine);
	shoulder.first = randX(randomEngine);

	wrist.second = randX(randomEngine);
	elbow.second = randX(randomEngine);
	shoulder.second = randX(randomEngine);
}

Action::Action(const Action &toCopy) {
	wrist.first = toCopy.wrist.first;
	elbow.first = toCopy.elbow.first;
	shoulder.first = toCopy.shoulder.first;

	wrist.second = toCopy.wrist.second;
	elbow.second = toCopy.elbow.second;
	shoulder.second = toCopy.shoulder.second;
}

Robot::Robot()
{
}

Robot::~Robot()
{
	for (size_t i = 0; i < m_actions.size(); i++)
	{
		delete m_actions.at(i);
	}
	//delete m_actions;
}

Robot::Robot(const Robot &obj)
//	: m_score(obj.m_score), m_distance(obj.m_distance), m_selected(obj.m_selected), m_wrist(obj.m_wrist), m_elbow(obj.m_elbow), m_shoulder(obj.m_shoulder)
{
}
//
//Robot& Robot::operator=(const Robot &obj)
//{
//	this->m_score = obj.m_score;
//	this->m_distance = obj.m_distance;
//	//this->m_selected = obj.m_selected;
//	//this->m_wrist = obj.m_wrist;
//	//this->m_elbow = obj.m_elbow;
//	//this->m_shoulder = obj.m_shoulder;
//	return (*this);
//}

void Robot::randomise(int actionNumber) {
	for (size_t i = 0; i < actionNumber; i++)
	{
		m_actions.emplace_back(new Action{});
		m_actions.back()->randomise();
	}
}

void Robot::addAction(Action action) {
	m_actions.emplace_back(new Action{action});
}