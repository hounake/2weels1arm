#pragma once

#include <iostream>
#include <string>
#include <sstream>

static const std::string CONFNAME = "Conf.txt";

class LogConf {
	size_t m_finalGeneration;
	size_t m_generationSize;
	size_t m_robotActionNumber;
	size_t m_robotSequenceNumber;

public:
	LogConf() {}
	~LogConf() {}

	void init(const std::string &fileName);

	size_t	getFinalGeneration() const { return m_finalGeneration; }
	size_t	getGenerationSize() const { return m_generationSize; }
	size_t	getRobotActionNumber() const { return m_robotActionNumber; }
	size_t getRobotSequenceNumber() const { return m_robotSequenceNumber; }
};