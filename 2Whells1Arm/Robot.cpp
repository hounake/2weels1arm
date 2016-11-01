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

Robot::Robot()
{ // Empty
}

Robot::~Robot()
{
	for (size_t i = 0; i < m_actions.size(); i++)
	{
		delete m_actions[i];
	}
}

Robot::Robot(const Robot &obj)
//	: m_score(obj.m_score), m_distance(obj.m_distance), m_selected(obj.m_selected), m_wrist(obj.m_wrist), m_elbow(obj.m_elbow), m_shoulder(obj.m_shoulder)
{
}

Robot& Robot::operator=(const Robot &obj)
{
	this->m_score = obj.m_score;
	this->m_distance = obj.m_distance;
	this->m_selected = obj.m_selected;
	//this->m_wrist = obj.m_wrist;
	//this->m_elbow = obj.m_elbow;
	//this->m_shoulder = obj.m_shoulder;
	return (*this);
}

void Robot::randomise() {
	for (size_t i = 0; i < NBACTION; i++)
	{
		m_actions.emplace_back(new Action{});
		m_actions.back()->randomise();
	}
}

void						Robot::setScore(int newScore)
{
	m_score = newScore;
}

void						Robot::setDistance(float newDist)
{
	m_distance = newDist;
}

void						Robot::select()
{
	m_selected = true;
}

void						Robot::resetSelection()
{
	m_selected = false;
}
//
//void						Robot::setProba(float newProba)
//{
//	m_proba = newProba;
//}

void						Robot::setPosX(double newX)
{
	m_posX = newX;
}

void						Robot::setPosY(double newY)
{
	m_posY = newY;
}

//
//void						Robot::setWrist(const std::pair<simxInt, simxInt> &newWrist)
//{
//	m_wrist = newWrist;
//}
//
//void						Robot::setElbow(const std::pair<simxInt, simxInt> &newElbow)
//{
//	m_elbow = newElbow;
//}
//
//void						Robot::setShoulder(const std::pair<simxInt, simxInt> &newShoulder)
//{
//	m_shoulder = newShoulder;
//}
//
//void						Robot::setWristAmp(const simxInt &newElbowAmp)
//{
//	m_wrist.first = newElbowAmp;
//}
//
//void						Robot::setWristRot(const simxInt &newElbowRot)
//{
//	m_wrist.second = newElbowRot;
//}
//
//void						Robot::setElbowAmp(const simxInt &newElbowAmp)
//{
//	m_elbow.first = newElbowAmp;
//}
//
//void						Robot::setElbowRot(const simxInt &newElbowRot)
//{
//	m_elbow.second = newElbowRot;
//}
//
//void						Robot::setShoulderAmp(const simxInt &newShoulderAmp)
//{
//	m_shoulder.first = newShoulderAmp;
//}
//
//void						Robot::setShoulderRot(const simxInt &newShoulderRot)
//{
//	m_shoulder.second = newShoulderRot;
//}
