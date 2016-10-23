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
	float						m_proba;
	std::pair<simxInt, simxInt>	m_wrist;
	std::pair<simxInt, simxInt>	m_elbow;
	std::pair<simxInt, simxInt>	m_shoulder;

public:
	Robot();
	~Robot();
	Robot(const Robot&);
	Robot& operator=(const Robot&);

	void randomise();

	int							getScore() const noexcept { return m_score; }
	float						getDistance() const noexcept { return m_distance; }
	bool						isSelected() const noexcept { return m_selected; }
	float						getProba() const noexcept { return m_proba; }
	const std::pair<simxInt, simxInt> &getWrist() const noexcept { return m_wrist; }
	const std::pair<simxInt, simxInt> &getElbow() const noexcept { return m_elbow; }
	const std::pair<simxInt, simxInt> &getShoulder() const noexcept { return m_shoulder; }

	void						setScore(int);
	void						setDistance(float);
	void						select();
	void						resetSelection();
	void						setProba(float);
	void						setWrist(const std::pair<simxInt, simxInt> &);
	void						setElbow(const std::pair<simxInt, simxInt> &);
	void						setShoulder(const std::pair<simxInt, simxInt> &);
};

