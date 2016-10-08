#include "stdafx.h"
#include "Robot.h"

Robot::Robot()
	: m_score(0), m_distance(0.0), m_selected(false) m_wrist(std::pair<simxInt, simxInt>(0, 0)), m_elbow(std::pair<simxInt, simxInt>(0, 0)), m_shoulder(std::pair<simxInt, simxInt>(0, 0))
{
}

Robot::~Robot()
{
}

int							getScore()
{
	return m_score;
}

float						getDistance()
{
	return m_distance;
}

bool						isSelected()
{
	return m_selected;
}

std::pair<simxInt, simxInt> &getWrist()
{
	return m_wrist;
}

std::pair<simxInt, simxInt> &getElbow()
{
	return m_elbow;
}

std::pair<simxInt, simxInt> &getShoulder()
{
	return m_shoulder;
}

void						setScore(int newScore)
{
	m_score = newScore;
}

void						setDistance(float newDist)
{
	m_distance = newDist;
}

void						select()
{
	m_select = true;
}

void						resetSelection()
{
	m_select = false;
}

void						setWrist(std::pair<simxInt, simxInt> &newWrist)
{
	m_wrist = newWrist;
}

void						setElbow(std::pair<simxInt, simxInt> &newElbow)
{
	m_elbow = newElbow;
}

void						setShoulder(std::pair<simxInt, simxInt> &newShoulder)
{
	m_shoulder = newShoulder;
}
