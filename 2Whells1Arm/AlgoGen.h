#pragma once

#include <math.h>
#include "Robot.h"
#include <algorithm>

class AlgoGen
{
private:
	//float		m_elitismRate; // percent between 0.01 and 0.1
	//int			m_populationSize;  // sef explanatory
	//int			m_elitesNbr; // calculated
	//int			m_childNbr; // calculeted
	//int			m_generatonScore;  // cumil of all score for current generation
	//int			m_mutationRate; // like "5" for 5 in 100

	//Robot		m_father;
	//Robot		m_mother;
	//Robot		m_child;

	std::vector<Robot *> m_newRobots;

	void createOffspring(const Robot &Parent1, const Robot &Parent2);

public:
	AlgoGen();
	~AlgoGen();

	//AlgoGen(int populationSize, float elitismRate, int mutationRate, simxFloat distance_x, simxFloat distance_y, simxFloat distance);

	void selection(std::vector<Robot*> &robots);

	void mating(std::vector<Robot*> &robots);

	void mutate();

	std::vector<Robot*> &getNewGene(); // insert
};

