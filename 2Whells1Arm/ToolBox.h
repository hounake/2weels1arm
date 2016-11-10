#pragma once

#include <sstream>

class Convert
{
public:
	static int toInt(const std::string &toConvert) {
		std::istringstream buffer(toConvert);
		int value;
		buffer >> value;
		return value;
	}
};