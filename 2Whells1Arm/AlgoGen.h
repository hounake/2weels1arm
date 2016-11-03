#pragma once
#include <map>
#include <vector>
#include <math.h>
#include "Robot.h"
#include "logConf.h"
#include <algorithm>
#include <time.h>


class AlgoGen
{
private:
	float		m_elitismRate; // percent between 0.01 and 0.1
	int			m_populationSize;  // sef explanatory
	int			m_elitesNbr; // calculated
	int			m_childNbr; // calculeted
	int			m_generatonScore;  // cumil of all score for current generation
	int			m_mutationRate; // like "5" for 5 in 100
	int			m_heritageRate; // % of gen taken from the other parent

	simxFloat	m_distance_x;
	simxFloat	m_distance_y;
	simxFloat	m_distance;

	Robot		m_father;
	Robot		m_mother;
	Robot		m_child;

	std::vector<Robot *> m_newRobots;//remplacer second by robot
public:
	AlgoGen();
	~AlgoGen();

	AlgoGen(int populationSize, float elitismRate, int mutationRate, simxFloat distance_x, simxFloat distance_y, simxFloat distance);

	// void loadConf(LogConf &conf);

	void selection(std::vector<Robot> &robots);

	void mating();

	void scoreSetting(std::vector<Robot> &robots);

	void repopulate(std::vector<Robot> &robots);

	void mutate();

	void fuseGene();

	void fuseGene(Robot &parent);

	void getNewGene(std::vector<Robot> &robots); // insert
};

