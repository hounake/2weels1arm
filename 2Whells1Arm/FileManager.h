#pragma once

#include <map>
#include <vector>
#include "Robot.h"

class FileManager
{
public:
	FileManager();
	~FileManager();

	void geneToLog();
	void init(std::string &file);

	void createConf();
	void createDir();
	void createGeneLog(std::map<int, std::vector<Robot>> &robots, int nbGene);
	void CreateCSV();
};

