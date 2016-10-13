#pragma once

#include <iostream>
#include <string>
#include <sstream>

class LogConf {
	int maxGene;
	int sizeGene;
	int nbAction;

public:
	LogConf();
	~LogConf();

	int	getMaxGene() const;
	int	getSizeGene() const;
	int	getNbAction() const;

	void setMaxGene(const int);
	void setSizeGene(const int);
	void setNbAction(const int);
	std::ostream& LogConf::operator<<(std::ostream&, const LogConf&)
	//std::istream operator>>(std::istream&, LogConf&);
};