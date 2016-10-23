#pragma once
#include <map>
#include <vector>
#include <math.h>
#include "Robot.h"
#include "logConf.h"
#include <algorithm>


class AlgoGen
{
private:
	int			elitismRate;
	int			populationize;
	simxFloat	distance_x;
	simxFloat	distance_y;
	simxFloat	distance;
	std::map<int, std::vector<Robot>> newRobots;//remplacer second by robot
public:
	AlgoGen();
	~AlgoGen();

	void loadConf(LogConf &conf);

	void selection(std::vector<Robot> &robots);

	void mating(std::vector<Robot> &robots);

	void scoreSetting(std::vector<Robot> &robots);

	void mutate();

	void getNewGene(std::vector<Robot> &robots); // insert
};

