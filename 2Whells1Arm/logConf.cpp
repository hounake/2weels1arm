#include "stdafx.h"
#include "logConf.h"
#include "ToolBox.h"

#include <utility>
#include <fstream>
#include <vector>

void LogConf::m_robotBuilder(const std::string &record) {
	std::stringstream ss(record);
	std::vector<std::string> actions;

	while (ss.good())
	{
		std::string substr;
		std::getline(ss, substr, ';');
		if (substr != "")
			actions.push_back(substr);
	}

	for each (auto actionString  in actions)
	{
		std::stringstream ss(actionString);
		std::vector<std::string> actionVector;

		while (ss.good())
		{
			std::string substr;
			std::getline(ss, substr, ',');
			actionVector.push_back(substr);
		}

		Action a;
		a.elbow.first = std::atof(actionVector[0].c_str());
		a.elbow.second = std::atof(actionVector[1].c_str());
		a.shoulder.first = std::atof(actionVector[2].c_str());
		a.shoulder.second = std::atof(actionVector[3].c_str());
		a.wrist.first = std::atof(actionVector[4].c_str());
		a.wrist.second = std::atof(actionVector[5].c_str());
		m_actions.push_back(a);
	}
}

void LogConf::init(const std::string &fileName) {
	std::ifstream file;
	file.open(fileName);

	// Error checking
	if (file.fail()) {
		throw std::string("Error: failed to open " + fileName);
	}

	// Read the config file
	std::string record;
	std::string dataName;
	while (std::getline(file, record))
	{
		if (record.front() == '#')
		{ // Do nothing
		}
		else if (record.back() == ':')
		{ // Enable the dataName
			record.pop_back();
			dataName = record;
		}
		else // push the value to the apropriate data
		{
			if (dataName == "finalGeneration")
			{
				m_finalGeneration = Convert::toInt(record);
			}
			else if (dataName == "generationSize")
			{
				m_generationSize = Convert::toInt(record);
			}
			else if (dataName == "robotActionNumber")
			{
				m_robotActionNumber = Convert::toInt(record);
			}
			else if (dataName == "robotSequenceNumber")
			{
				m_robotSequenceNumber = Convert::toInt(record);
			}
			else if (dataName == "robot") {
				m_robotBuilder(record);
				m_robotExist = true;
			}
		}
	}
	file.close();
}