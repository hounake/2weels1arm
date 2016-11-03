#pragma once

#include "stdafx.h"
#include <utility>
#include <functional>
#include <vector>

extern "C" {
#include "extApi.h"
}

#define MIN_CYCLE 4
#define MAX_CYCLE 10

class Robot
{
	simxFloat						m_x;
	simxFloat						m_y;
	simxFloat						m_distance;
	int								m_score;
	float							m_proba;
	bool							m_selected;
	int								m_repetition;
	std::vector<std::vector<std::pair<simxInt, simxInt>>> m_cycle;

	Robot();
public:
	Robot(int);
	Robot(simxFloat, simxFloat);
	Robot(simxFloat _x, simxFloat _y, int _repetition);
	~Robot();
	Robot(const Robot&);
	Robot& operator=(const Robot&);

	// Getter
	simxFloat						getX() const { return m_x; }
	simxFloat						getY() const { return m_y; }
	simxFloat						getDistance() const { return m_distance; }
	int								getScore() const { return m_score; }
	float							getProba() const { return m_proba; }
	bool							isSelected() const { return m_selected; }
	int								getRepetition() const { return m_repetition; }
	std::vector<std::vector<std::pair<simxInt, simxInt>>> getCycle() const { return m_cycle; }
	int								getCycleLength() const { return m_cycle.size(); }

	// Setter
	void							setX(simxFloat);
	void							setY(simxFloat);
	void							setDistance(simxFloat);
	void							setScore(int);
	void							setProba(float);
	void							setSelect(bool);
	void							setRepetition(int);
	bool							setStateCycle(unsigned int, unsigned int, const std::pair<simxInt, simxInt>&);
	void							setCycle(const std::vector<std::vector<std::pair<simxInt, simxInt>>>&);

	// Other
	void							randomise();
};
