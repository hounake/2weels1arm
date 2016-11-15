#pragma once

#include <vector>

#include "LogConf.h"
#include "RobotAction.h"

extern "C" {
#include "extApi.h"
}

class Robot
{
	double						m_proba = 0;
	double						m_score = 0;
	double						m_distance = 0;
	std::vector<Action*>		m_actions;

public:
	Robot();
	~Robot();
	//Robot(const Robot&);

	void randomise(int actionNumber);

	double						getScore() const { return m_score; }
	double						getDistance() const { return m_distance; }
	double						getProbability() const { return m_proba; }
	const std::vector<Action*>	getAction() const { return m_actions; }

	void						setScore(double score) { m_score = score; }
	void						setDistance(double dist) { m_distance = dist; }
	void						setProbability(double proba) { m_proba = proba; }
	void						addAction(Action action);
};


