#include "stdafx.h"
#include "Robot.h"
#include <random>

Robot::Robot()
	: m_score(0), m_distance(0.0), m_selected(false), m_wrist(std::pair<simxInt, simxInt>(0, 0)), m_elbow(std::pair<simxInt, simxInt>(0, 0)), m_shoulder(std::pair<simxInt, simxInt>(0, 0))
{
}

Robot::~Robot()
{
}

void Robot::randomise() {
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<float> randX(-360.0f, 360.0f);

	m_wrist.first = randX(randomEngine);
	m_elbow.first  = randX(randomEngine);
	m_shoulder.first = randX(randomEngine);

	m_wrist.second = randX(randomEngine);
	m_elbow.second = randX(randomEngine);
	m_shoulder.second = randX(randomEngine);
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

void						Robot::setWrist(const std::pair<simxInt, simxInt> &newWrist)
{
	m_wrist = newWrist;
}

void						Robot::setElbow(const std::pair<simxInt, simxInt> &newElbow)
{
	m_elbow = newElbow;
}

void						Robot::setShoulder(const std::pair<simxInt, simxInt> &newShoulder)
{
	m_shoulder = newShoulder;
}
