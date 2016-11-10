#include "stdafx.h"
#include "logConf.h"
#include "ToolBox.h"

#include <fstream>

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

		}
	}
	file.close();
}