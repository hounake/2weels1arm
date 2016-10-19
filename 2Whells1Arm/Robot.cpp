#include "stdafx.h"
#include "Robot.h"

Robot::Robot()
	: m_score(0), m_distance(0.0), m_selected(false), m_wrist(std::pair<simxInt, simxInt>(0, 0)), m_elbow(std::pair<simxInt, simxInt>(0, 0)), m_shoulder(std::pair<simxInt, simxInt>(0, 0))
{
}

Robot::~Robot()
{
}

int							Robot::getScore() const noexcept
{
	return m_score;
}

float						Robot::getDistance() const noexcept
{
	return m_distance;
}

bool						Robot::isSelected() const noexcept
{
	return m_selected;
}

const std::pair<simxInt, simxInt> &Robot::getWrist() const noexcept
{
	return m_wrist;
}

const std::pair<simxInt, simxInt> &Robot::getElbow() const noexcept
{
	return m_elbow;
}

const std::pair<simxInt, simxInt> &Robot::getShoulder() const noexcept
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
