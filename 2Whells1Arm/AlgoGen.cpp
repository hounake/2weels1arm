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

void AlgoGen::mating(std::vector<Robot*> &robots)
{
	static std::random_device rd;
	static std::mt19937 randomEngine(rd());
	static std::uniform_real_distribution<double> randX(0.0f, 1.0f);
	m_newRobots.clear();

	for (size_t i = 0; i < robots.size(); i++)
	{
		Robot *Parent1 = nullptr;
		Robot *Parent2 = nullptr;

		double number = randX(randomEngine);//Random between 0 and 1 for parent1
		for (size_t j = 1; j < robots.size(); j++)
		{
			if (number > robots[j]->getProbability())
			{
				Parent1 = robots[j-1];
				break;
			}
		}

		number = randX(randomEngine);//Random between 0 and 1 for parent2
		for (size_t j = 1; j < robots.size(); j++)
		{
			if (number > robots[j]->getProbability())
			{
				Parent2 = robots[j - 1];
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

void AlgoGen::mutate()
{

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
