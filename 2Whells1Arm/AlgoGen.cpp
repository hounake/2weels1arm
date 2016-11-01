#include "stdafx.h"
#include "AlgoGen.h"


AlgoGen::AlgoGen()
{
	m_populationSize = 1000;
	m_elitismRate = 10;
	m_mutationRate = 0.05f;
	m_distance_x = 10;
	m_distance_y = 10;
	m_distance = 200;
}

AlgoGen::AlgoGen(int populationSize, float elitismRate, int mutationRate, simxFloat distance_x, simxFloat distance_y, simxFloat distance)
	: m_populationSize(1000), m_elitismRate(0.1f), m_mutationRate(5), m_distance_x(10), m_distance_y(10), m_distance(200)
{
	m_populationSize = populationSize;
	m_elitismRate = elitismRate;
	m_mutationRate = mutationRate;
	m_distance_x = distance_x;
	m_distance_y = distance_y;
	m_distance = distance;
	if (mutationRate <= 0)
		m_mutationRate = 5;
}

AlgoGen::~AlgoGen()
{
	for (Robot *rob : m_newRobots)
		delete(rob);
	m_newRobots.clear();
	
}

void AlgoGen::selection(std::vector<Robot> &robots)
{
	int choiceRank;
	int fatherScore;
	float choiceCumul = 0;
	Robot *ptrFather = NULL;
	srand(time(NULL));

	choiceRank = rand() % 100;
	if (m_generatonScore == 0)
		m_generatonScore = 1;

	//look for father
	//xprob = (xscore * 100) totalscore;
	for (Robot rob : robots)
	{
		choiceCumul += rob.getScore() * 100.0f / m_generatonScore;
		if (choiceCumul >= choiceRank + 0.0f)
		{
			rob.select();
			m_father = rob;
			ptrFather = &rob;
			fatherScore = m_father.getScore();
		}
	}
	choiceRank = rand() % 100;
	//look for mother
	//xprob = (xscore * 100) (totalscore - fatherScore;
	for (Robot rob : robots)
	{
		if (!rob.isSelected())
		{
			if (m_generatonScore - fatherScore == 0)
				choiceCumul += rob.getScore() * 100.0f / 1;
			else
				choiceCumul += rob.getScore() * 100.0f / (m_generatonScore - fatherScore);
		}
		if (choiceCumul >= choiceRank + 0.0f)
			m_mother = rob;
	}
	/// or do it at the reseting of next selection
	if (ptrFather)
		ptrFather->resetSelection();
	mating();
	m_newRobots.push_back(new Robot(m_child));
}

void AlgoGen::mating()
{
	srand(time(NULL));
	int sex = rand() % 3;
	int heritage = rand() % 3;
	if (sex == 0)
	{
		m_child = m_father;
		//if (heritage == 0)
		//	m_child.setElbow(m_mother.getElbow());
		//else if (heritage == 1)
		//	m_child.setShoulder(m_mother.getShoulder());
		//else
		//	m_child.setWrist(m_mother.getWrist());

	}
	else if (sex == 1)
	{
		m_child = m_mother;
		//if (heritage == 0)
		//	m_child.setElbow(m_father.getElbow());
		//else if (heritage == 1)
		//	m_child.setShoulder(m_father.getShoulder());
		//else
		//	m_child.setWrist(m_father.getWrist());
	}
	else
	{
		//m_child.setElbow(std::pair<simxFloat, simxFloat>(((m_mother.getElbow().first + m_mother.getElbow().first) / 2.0f), ((m_mother.getElbow().second + m_mother.getElbow().second) / 2.0f)));
		//m_child.setShoulder(std::pair<simxFloat, simxFloat>(((m_mother.getShoulder().first + m_mother.getShoulder().first) / 2.0f), ((m_mother.getShoulder().second + m_mother.getShoulder().second) / 2.0f)));
		//m_child.setWrist(std::pair<simxFloat, simxFloat>(((m_mother.getWrist().first + m_mother.getWrist().first) / 2.0f), ((m_mother.getWrist().second + m_mother.getWrist().second) / 2.0f)));
	}
	mutate();
}

void AlgoGen::mutate()
{
	int mutationRand;

	srand(time(NULL));
	mutationRand = rand() % (100 / m_mutationRate);
	if (mutationRand = 1)
	{
		m_child = Robot();
		//do mutation
	}
}

void AlgoGen::repopulate(std::vector<Robot> &robots)
{
	for (Robot * rob : m_newRobots)
	{
		robots.push_back(Robot(*rob));
	}
}

void AlgoGen::getNewGene(std::vector<Robot> &robots)
{
	
}


void AlgoGen::scoreSetting(std::vector<Robot> &robots)
{
	for (auto &rob : robots)
	{
		rob.setDistance(pow(rob.getPosX() - m_distance_x, 2.0) + pow(rob.getPosY() - m_distance_y, 2.0));
		if (rob.getDistance() > m_distance * 2)
		{
			rob.setScore(0);
			//rob.setProba(0.0f);
		}
		else
		{
			rob.setScore((100.0f - (rob.getDistance() * 100.0f) / (m_distance * 2)));
			m_generatonScore += rob.getScore();
		}
	}
	std::sort(robots.begin(), robots.end(), [](Robot a, Robot b){ return (a.getScore() > b.getScore());});
	m_elitesNbr = m_elitismRate * m_populationSize;
	m_childNbr = m_populationSize - m_elitesNbr;

	for (int i = 0; i < m_elitesNbr; i++)
		m_newRobots.push_back(new Robot(robots[i]));
	for (int i = 0; i < m_childNbr; i++)
		selection(robots);
}