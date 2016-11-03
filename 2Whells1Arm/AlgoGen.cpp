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

//: m_populationSize(1000), m_elitismRate(0.1f), m_mutationRate(5), m_distance_x(10), m_distance_y(10), m_distance(200)
AlgoGen::AlgoGen(int populationSize, float elitismRate, int mutationRate, simxFloat distance_x, simxFloat distance_y, simxFloat distance)
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
			rob.setSelect(true);
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
		ptrFather->setSelect(false);
	mating();
	m_newRobots.push_back(new Robot(m_child));
}


void AlgoGen::fuseGene(Robot &parent)
{
	int myCycleSize = m_child.getCycleLength();
	int otherCycleSize = parent.getCycleLength();
	int toHerit = myCycleSize;
	if (myCycleSize > otherCycleSize)
		toHerit = otherCycleSize;
	toHerit = toHerit * m_heritageRate / 100;
	for (int i = 0; i < toHerit; i++)
		for (int j = 0; j < 3; j++)
			m_child.setStateCycle(i, j, parent.getStateCycle(i, j));
}

void AlgoGen::fuseGene()
{
	int myCycleSize = m_father.getCycleLength();
	int otherCycleSize = m_mother.getCycleLength();
	int toHerit = myCycleSize;
	if (myCycleSize > otherCycleSize)
		toHerit = otherCycleSize;
	for (int i = 0; i < toHerit; i++)
		for (int j = 0; j < 3; j++)
			m_child.setStateCycle(i, j, std::pair<simxFloat, simxFloat>(((m_mother.getStateCycle(i, j).first + m_mother.getStateCycle(i, j).first) / 2.0f), ((m_mother.getStateCycle(i, j).second + m_mother.getStateCycle(i, j).second) / 2.0f)));

}

void AlgoGen::mating()
{
	srand(time(NULL));
	int sex = rand() % 3;
	int heritage = rand() % 3;

	if (sex == 0)
	{
		m_child = m_father;
		fuseGene(m_mother);

	}
	else if (sex == 1)
	{
		m_child = m_mother;
		fuseGene(m_father);
	}
	else
		fuseGene();
	mutate();
}

void AlgoGen::mutate()
{
	int mutationRand;

	srand(time(NULL));
	mutationRand = rand() % (100 / m_mutationRate);
	if (mutationRand = 1)
	{
		m_child = Robot(); // /!\ Robot Constructor needs a nb of cycle repetition /!\;
		m_child.setRepetition(50);
		m_child.randomise();
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
		rob.setDistance(pow(rob.getX() - m_distance_x, 2.0f) + pow(rob.getY() - m_distance_y, 2.0f));
		if (rob.getDistance() > m_distance * 2)
		{
			rob.setScore(0);
			rob.setProba(0.0f);
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