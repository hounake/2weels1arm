#include "stdafx.h"
#include "RobotAction.h"

#include <random>

void Action::randomise() {
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<float> randX(-360.0f, 360.0f);

	wrist.first = randX(randomEngine);
	elbow.first = randX(randomEngine);
	shoulder.first = randX(randomEngine);

	wrist.second = randX(randomEngine);
	elbow.second = randX(randomEngine);
	shoulder.second = randX(randomEngine);
}

Action::Action(const Action &toCopy) {
	wrist.first = toCopy.wrist.first;
	elbow.first = toCopy.elbow.first;
	shoulder.first = toCopy.shoulder.first;

	wrist.second = toCopy.wrist.second;
	elbow.second = toCopy.elbow.second;
	shoulder.second = toCopy.shoulder.second;
}