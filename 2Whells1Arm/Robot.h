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

	int							getScore() const noexcept;
	float						getDistance() const noexcept;
	bool						isSelected() const noexcept;
	const std::pair<simxInt, simxInt> &getWrist() const noexcept;
	const std::pair<simxInt, simxInt> &getElbow() const noexcept;
	const std::pair<simxInt, simxInt> &getShoulder() const noexcept;

	void						setScore(int);
	void						setDistance(float);
	void						select();
	void						resetSelection();
	void						setWrist(const std::pair<simxInt, simxInt> &);
	void						setElbow(const std::pair<simxInt, simxInt> &);
	void						setShoulder(const std::pair<simxInt, simxInt> &);
};

