#include "stdafx.h"
#include "AlgoGen.h"

#include <random>

AlgoGen::AlgoGen()
{
}

AlgoGen::~AlgoGen()
{
}

void AlgoGen::selection(std::vector<Robot*> &robots)
{
	for each (Robot* robot in robots)
	{
		robot->setScore(robot->getDistance()*100); // TODO : better fitness ??
	}
	std::sort(robots.begin(), robots.end(), [](Robot* a, Robot* b) { return (a->getScore() < b->getScore()); });

	double sum = 0;
	for each (Robot* robot in robots)
		sum += robot->getScore();

	double probabilitySum = 0;
	for each (Robot* robot in robots)
	{
		double proba = (robot->getScore() / sum);
		robot->setProbability(proba + probabilitySum);
		probabilitySum += proba;
	}

	std::sort(robots.begin(), robots.end(), [](Robot* a, Robot* b) { return (a->getScore() > b->getScore()); });
}

void AlgoGen::mating(std::vector<Robot*> &robots, int elitismNumber)
{
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<double> randX(0.0f, 1.0f);
	m_newRobots.clear();

	for (size_t i = 0; i < robots.size() - 1 - elitismNumber; i++)
	{
		Robot *Parent1 = nullptr;
		Robot *Parent2 = nullptr;

		double number = randX(randomEngine);//Random between 0 and 1 for parent1
		size_t j = 1;
		for (; j < robots.size(); j++)
		{
			if (number > robots[j]->getProbability())
			{
				Parent1 = robots[j-1];
				break;
			}
		}

		number = randX(randomEngine);//Random between 0 and 1 for parent2
		for (size_t s = 1; s < robots.size(); s++)
		{
			if (number > robots[s]->getProbability() && s != j)
			{
				Parent2 = robots[s - 1];
				break;
			}
		}
		if (Parent1 == nullptr)
			Parent1 = robots[robots.size() - 1];
		if (Parent2 == nullptr)
			Parent2 = robots[robots.size() - 1];

		createOffspring(*Parent1, *Parent2);
	}
}

void AlgoGen::mutate(std::vector<Robot*> &robots, int elitismNumber)
{
	for (size_t i = 0; i < elitismNumber; i++)
	{
		m_newRobots.emplace_back(robots[i]);
	}

	m_newRobots.emplace_back(new Robot{});
	m_newRobots.back()->randomise(m_newRobots[0]->getAction().size());
}

std::vector<Robot*> &AlgoGen::getNewGene()
{
	return m_newRobots;
}

void AlgoGen::createOffspring(const Robot &Parent1,const Robot &Parent2) {
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<double> randX(0.0f, 1.0f);

	Robot *offspring = new Robot {};
	
	std::vector<Action*> offspringActions;// = new std::vector<Action*>{};

	for (size_t i = 0; i < Parent1.getAction().size(); i++)
	{
		double random = randX(randomEngine); // random 0/1
		if (random >= 0.5)
			offspring->addAction(*Parent1.getAction()[i]);
		else
			offspring->addAction(*Parent2.getAction()[i]);
	}

	m_newRobots.push_back(offspring);
}
