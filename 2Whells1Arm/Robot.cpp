#include "stdafx.h"
#include "Robot.h"

Robot::Robot()
	: m_score(0), m_distance(0.0), m_selected(false), m_wrist(std::pair<simxInt, simxInt>(0, 0)), m_elbow(std::pair<simxInt, simxInt>(0, 0)), m_shoulder(std::pair<simxInt, simxInt>(0, 0))
{
}

Robot::~Robot()
{
}

int							Robot::getScore()
{
	return m_score;
}

float						Robot::getDistance()
{
	return m_distance;
}

bool						Robot::isSelected()
{
	return m_selected;
}

std::pair<simxInt, simxInt> &Robot::getWrist()
{
	return m_wrist;
}

std::pair<simxInt, simxInt> &Robot::getElbow()
{
	return m_elbow;
}

std::pair<simxInt, simxInt> &Robot::getShoulder()
{
	return m_shoulder;
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

void						Robot::setWrist(std::pair<simxInt, simxInt> &newWrist)
{
	m_wrist = newWrist;
}

void						Robot::setElbow(std::pair<simxInt, simxInt> &newElbow)
{
	m_elbow = newElbow;
}

void						Robot::setShoulder(std::pair<simxInt, simxInt> &newShoulder)
{
	m_shoulder = newShoulder;
}
