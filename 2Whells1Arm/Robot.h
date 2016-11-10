#pragma once

#include <utility>
#include <vector>

#include "LogConf.h"

extern "C" {
#include "extApi.h"
}

//const int NBACTION = 4; // TODO : add it to conf fille

class Action
{
public:
	std::pair<simxInt, simxInt>	wrist = std::pair<simxInt, simxInt>(0, 0);
	std::pair<simxInt, simxInt>	elbow = std::pair<simxInt, simxInt>(0, 0);
	std::pair<simxInt, simxInt>	shoulder = std::pair<simxInt, simxInt>(0, 0);

	Action() {};
	Action(const Action &toCopy);

	void randomise();
};

class Robot
{
	double						m_proba = 0;
	double						m_score = 0;
	double						m_distance = 0;
	std::vector<Action*>		m_actions;

public:
	Robot();
	~Robot();
	Robot(const Robot&);

	void randomise(int actionNumber);

	double						getScore() const { return m_score; }
	double						getDistance() const { return m_distance; }
	double						getProbability() const { return m_proba; }
	const std::vector<Action*>	getAction() const { return m_actions; }

	void						setScore(double score) { m_score = score; }
	void						setDistance(double dist) { m_distance = dist; }
	void						setProbability(double proba) { m_proba = proba; }
	void						addAction(Action action);
	//void						setActions(const std::vector<Action*> &actions) const { *m_actions = actions; }


	//bool operator==(const Robot& rob) {
	//	if (getScore() != rob.getScore())
	//		return false;
	//	if (getDistance() != rob.getDistance())
	//		return false;
	//	if (getProbability() != rob.getProbability())
	//		return false;
	//	return true;
	//}

	//bool operator!=(const Robot& rob) {
	//	return !(*this == rob);
	//}
};

