#pragma once

#include <utility>

extern "C" {
#include "extApi.h"
}

class Robot
{
	int							m_score;
	float						m_distance;
	bool						m_selected;
	std::pair<simxInt, simxInt>	m_wrist;
	std::pair<simxInt, simxInt>	m_elbow;
	std::pair<simxInt, simxInt>	m_shoulder;

public:
	Robot();
	~Robot();

	int							getScore();
	float						getDistance();
	bool						isSelected();
	std::pair<simxInt, simxInt> &getWrist();
	std::pair<simxInt, simxInt> &getElbow();
	std::pair<simxInt, simxInt> &getShoulder();

	void						setScore(int);
	void						setDistance(float);
	void						select();
	void						resetSelection();
	void						setWrist(std::pair<simxInt, simxInt> &);
	void						setElbow(std::pair<simxInt, simxInt> &);
	void						setShoulder(std::pair<simxInt, simxInt> &);
};

