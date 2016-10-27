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

	int							getScore() const  { return m_score; }
	float						getDistance() const  { return m_distance; }
	bool						isSelected() const  { return m_selected; }
	float						getProba() const  { return m_proba; }
	const std::pair<simxInt, simxInt> &getWrist() const  { return m_wrist; }
	const std::pair<simxInt, simxInt> &getElbow() const  { return m_elbow; }
	const std::pair<simxInt, simxInt> &getShoulder() const  { return m_shoulder; }

	void						setScore(int);
	void						setDistance(float);
	void						select();
	void						resetSelection();
	void						setProba(float);
	void						setWrist(const std::pair<simxInt, simxInt> &);
	void						setElbow(const std::pair<simxInt, simxInt> &);
	void						setShoulder(const std::pair<simxInt, simxInt> &);
};

