#pragma once

#include <utility>
#include "App.h"

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

	void						setScore();
	void						setDistance();
	void						select();
	void						resetSelection();
	void						setWrist();
	void						setElbow();
	void						setShoulder();
};

