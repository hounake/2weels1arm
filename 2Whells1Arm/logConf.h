#pragma once

#include "RobotAction.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

static const std::string CONFNAME = "Conf.txt";

class LogConf {
	size_t m_finalGeneration = 0;
	size_t m_generationSize = 0;
	size_t m_robotActionNumber = 0;
	size_t m_robotSequenceNumber = 0;
	//Robot m_robot;
	std::vector<Action> m_actions;
	bool m_robotExist = false;

	void m_robotBuilder(const std::string &record);
public:
	LogConf() {}
	~LogConf() {}

	void init(const std::string &fileName);

	size_t	getFinalGeneration() const { return m_finalGeneration; }
	size_t	getGenerationSize() const { return m_generationSize; }
	size_t	getRobotActionNumber() const { return m_robotActionNumber; }
	size_t	getRobotSequenceNumber() const { return m_robotSequenceNumber; }
	bool	isRobotExist() const { return m_robotExist; }
	const std::vector<Action> &getAction() const { return m_actions; }
	
};