#pragma once

#include <map>
#include <vector>
#include <sstream>
#include <boost/filesystem.hpp>
#include "Robot.h"
#include "LogConf.h"

//TODO : Change RobotGeneContainer map to vector
//TODO : Adapt input file reading to multiple gene file ?

typedef std::map<int, std::vector<Robot>> RobotGeneContainer;

class FileManager
{
private:
	std::string _fileName;
	LogConf	_conf;
	std::map<int, std::vector<Robot>> _lastReadGene;
	std::stringstream outstream;//gene log stored here to be written afterwards
	std::stringstream instream;//gene log stored here to be parsed afterwards

public:
	FileManager();
	~FileManager();

	//void geneToLog();
	//void init(std::string &file);
	//void createCSV();

	void	createConf();
	void	createDir();

	void	logAGene(RobotGeneContainer &robots, int nbGene);
	void	logAllGenesInMultipleFiles(std::vector<RobotGeneContainer> &robotGenes);
	void	logAllGenesInOneFile(std::vector<RobotGeneContainer> &robotGenes);

	RobotGeneContainer &	initAGene(int nbGene);

private:
	bool	initRobotFromString(Robot& robot, std::string const& datas);
	void	getFileGenePath(boost::filesystem::path & file_path, int nbGene);

	void	createGeneLog(RobotGeneContainer &robots, int nbGene);
	void	writeTheLog(int nbGene);

	RobotGeneContainer &	initGeneFromLog(int nbGene);
	void	readTheLog(int nbGene);
};

