#pragma once

#include <utility>

class Action
{
public:
	std::pair<double, double>	wrist = std::pair<double, double>(0, 0);
	std::pair<double, double>	elbow = std::pair<double, double>(0, 0);
	std::pair<double, double>	shoulder = std::pair<double, double>(0, 0);

	Action() {};
	Action(const Action &toCopy);

	void randomise();
};
