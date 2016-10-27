#include "stdafx.h"
#include "AlgoGen.h"


AlgoGen::AlgoGen()
{
}


AlgoGen::~AlgoGen()
{
}

void AlgoGen::selection(std::vector<Robot> &robots)
{
	for (Robot rob : robots)
	{
		//if (rob.isSelected != selec)
	}
}

void AlgoGen::mating(std::vector<Robot> &robots)
{

}

void AlgoGen::mutate()
{

}

void AlgoGen::getNewGene(std::vector<Robot> &robots)
{
	
}


void AlgoGen::scoreSetting(std::vector<Robot> &robots)
{
	for (auto &rob : robots)
	{
		rob.m_distance = pow(rob.m_x - distance_x, 2.0) + pow(rob.m_y - distance_y, 2.0);
		if (rob.m_distance > distance * 2)
			rob.setScore(0);
		else
			rob.setScore((100.0f - (rob.m_distance * 100.0f) / (distance * 2)));
	}
	std::sort(robots.begin(), robots.end(), [](Robot a, Robot b){ return (a.getScore() > b.getScore());});
}