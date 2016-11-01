#pragma once

#include <utility>
#include <vector>

extern "C" {
#include "extApi.h"
}

const int NBACTION = 4; // TODO : add it to conf fille

class Action
{
public:
	std::pair<simxInt, simxInt>	wrist;
	std::pair<simxInt, simxInt>	elbow;
	std::pair<simxInt, simxInt>	shoulder;

	void randomise();
};

class Robot
{
	//int							m_score;
	//float						m_distance;
	//bool						m_selected;
	//float						m_proba;
	double						m_posX;
	double						m_posY;
	//std::pair<simxInt, simxInt>	m_wrist;
	//std::pair<simxInt, simxInt>	m_elbow;
	//std::pair<simxInt, simxInt>	m_shoulder;

	int							m_score = 0;
	float						m_distance = 0;
	bool						m_selected = false;
	std::vector<Action*>		m_actions;

public:
	Robot();
	~Robot();
	Robot(const Robot&);
	Robot& operator=(const Robot&);

	void randomise();

	int							getScore() const { return m_score; }
	float						getDistance() const { return m_distance; }
	bool						isSelected() const { return m_selected; }
	//float						getProba() const noexcept{ return m_proba; }
	double						getPosX() const { return m_posX; }
	double						getPosY() const { return m_posY; }

	const std::vector<Action*>	&getAction() const { return m_actions; };

	//const std::pair<simxInt, simxInt> &getWrist() const noexcept{ return m_wrist; }
	//const std::pair<simxInt, simxInt> &getElbow() const noexcept{ return m_elbow; }
	//const std::pair<simxInt, simxInt> &getShoulder() const  { return m_shoulder; }
	//const simxInt&				getWristAmp() const noexcept{ return m_wrist.first; }
	//const simxInt&				getWristRot() const noexcept { return m_wrist.second; }
	//const simxInt&				getElbowAmp() const noexcept { return m_elbow.first; }
	//const simxInt&				getElbowRot() const noexcept { return m_elbow.second; }
	//const simxInt&				getShoulderAmp() const noexcept { return m_shoulder.first; }
	//const simxInt&				getShoulderRot() const noexcept { return m_shoulder.second; }

	void						setScore(int);
	void						setDistance(float);
	void						select();
	void						resetSelection();
	//void						setProba(float);
	void						setPosX(double);
	void						setPosY(double);
	//void						setWrist(const std::pair<simxInt, simxInt> &);
	//void						setElbow(const std::pair<simxInt, simxInt> &);
	//void						setShoulder(const std::pair<simxInt, simxInt> &);
	//void						setWristAmp(simxInt);
	//void						setWristRot(simxInt);
	//void						setElbowAmp(simxInt);
	//void						setElbowRot(simxInt);
	//void						setShoulderAmp(simxInt);
	//void						setShoulderRot(simxInt);
};

