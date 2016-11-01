//#pragma once
//
//#include <map>
//#include <vector>
//#include <boost/filesystem.hpp>
//#include "Robot.h"
//#include "LogConf.h"
//
//class FileManager
//{
//	std::string _fileName;
//	LogConf	_conf;
//	std::map<int, std::vector<Robot>> _lastReadGene;
//
//public:
//	FileManager();
//	~FileManager();
//
//	//void geneToLog();
//	//void init(std::string &file);
//
//	void createConf();
//	void createDir();
//	void createGeneLog(std::map<int, std::vector<Robot>> &robots, int nbGene);
//	//void createCSV();
//
//	std::map<int, std::vector<Robot>> &		initGeneFromFile(int nbGene);
//
//private:
//	void	getFileGenePath(boost::filesystem::path & file_path, int nbGene);
//};
//
