#include "stdafx.h"
#include "Robot.h"
#include <random>

Robot::Robot(int _repetition)
	: m_x(0), m_y(0), m_distance(0), m_score(0), m_proba(0), m_selected(false), m_repetition(_repetition)
{
}

Robot::Robot(simxFloat _x, simxFloat _y)
	: m_x(_x), m_y(_y), m_distance(0), m_score(0), m_proba(0), m_selected(false), m_repetition(0)
{
}

Robot::Robot(simxFloat _x, simxFloat _y, int _repetition)
	: m_x(_x), m_y(_y), m_distance(0), m_score(0), m_proba(0), m_selected(false), m_repetition(_repetition)
{
}

Robot::~Robot()
{
}

Robot::Robot(const Robot &obj)
	: m_x(obj.getX()), m_y(obj.getY()), m_distance(obj.getDistance()), m_score(obj.getScore()), m_proba(obj.getProba()), m_selected(obj.isSelected()), m_repetition(obj.getRepetition()), m_cycle(obj.getCycle())
{
}

Robot& Robot::operator=(const Robot &obj)
{
	this->m_score = obj.m_score;
	this->m_distance = obj.m_distance;
	this->m_selected = obj.m_selected;
	this->m_cycle = obj.m_cycle;
	return (*this);
}

void						Robot::setX(simxFloat _x)
{
	m_x = _x;
}

void						Robot::setY(simxFloat _y)
{
	m_y = _y;
}

void						Robot::setDistance(simxFloat _dist)
{
	m_distance = _dist;
}

void						Robot::setScore(int _score)
{
	m_score = _score;
}

void						Robot::setProba(float _proba)
{
	m_proba = _proba;
}

void						Robot::setSelect(bool _selected)
{
	m_selected = _selected;
}

void						Robot::setRepetition(int _repetition)
{
	m_repetition = _repetition;
}

bool						Robot::setStateCycle(unsigned int _state, unsigned int _motor, const std::pair<simxInt, simxInt> &_pair)
{
	if (m_cycle.size() > _state && _motor > 0 && _motor)
	{
		(m_cycle[_state])[_motor] = _pair;
		return true;
	}
	return false;
}

void						Robot::setCycle(const std::vector<std::vector<std::pair<simxInt, simxInt>>> &_vector)
{
	m_cycle = _vector;
}

void Robot::randomise() {
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<float> randX(-360.0f, 360.0f);
	static std::uniform_real_distribution<unsigned int> randSize(MIN_CYCLE, MAX_CYCLE);

	std::vector<std::pair<simxInt, simxInt>> vect;
	int sizeVector = randSize(randomEngine) + 1;
	for (int i = 0; i < sizeVector; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			vect.push_back(std::make_pair(randX(randomEngine), randX(randomEngine)));
		}
		m_cycle.push_back(vect);
	}
}
