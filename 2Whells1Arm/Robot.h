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
	double						m_x;
	double						m_y;
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
	double						getPosX() const { return m_x; }
	double						getPosY() const { return m_y; }
	const std::pair<simxInt, simxInt> &getWrist() const  { return m_wrist; }
	const std::pair<simxInt, simxInt> &getElbow() const  { return m_elbow; }
	const std::pair<simxInt, simxInt> &getShoulder() const  { return m_shoulder; }
	const simxInt&				getWristAmp() const { return m_wrist.first; }
	const simxInt&				getWristRot() const { return m_wrist.second; }
	const simxInt&				getElbowAmp() const { return m_elbow.first; }
	const simxInt&				getElbowRot() const { return m_elbow.second; }
	const simxInt&				getShoulderAmp() const { return m_shoulder.first; }
	const simxInt&				getShoulderRot() const { return m_shoulder.second; }

	void						setScore(int);
	void						setDistance(float);
	void						select();
	void						resetSelection();
	void						setProba(float);
	void						setPosX(double);
	void						setPosY(double);
	void						setWrist(const std::pair<simxInt, simxInt> &);
	void						setElbow(const std::pair<simxInt, simxInt> &);
	void						setShoulder(const std::pair<simxInt, simxInt> &);
	void						setWristAmp(const simxInt &);
	void						setWristRot(const simxInt &);
	void						setElbowAmp(const simxInt &);
	void						setElbowRot(const simxInt &);
	void						setShoulderAmp(const simxInt &);
	void						setShoulderRot(const simxInt &);
};

