#include "stdafx.h"
#include "FileManager.h"
#include <iostream>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;
using namespace boost::filesystem;

FileManager::FileManager()
	: _fileName("toto")
{
}
FileManager::~FileManager()
{
}


void FileManager::createConf()
{
}

void FileManager::createDir()
{
	std::cout << "FileManager creation: " << _fileName << std::endl;

	path p(_fileName);  // avoid repeated path construction below

	if (exists(p))
	{
		if (is_directory(p)) {
			cout << p << " is a directory\n";
		}
		else if (is_regular_file(p)) {
			cout << p << " size is " << file_size(p) << '\n';
			return;
		}
		else {
			cout << p << " exists, but is not a regular file or directory\n";
			return;
		}
	}
	else {
		cout << p << " does not exist\n";
		create_directory(p);
	}
}

void FileManager::createGeneLog(std::map<int, std::vector<Robot>>& robots, int nbGene)
{
	path file_path(_fileName);
	getFileGenePath(file_path, nbGene);
	std::ofstream outfile(file_path.c_str());

	//outfile << "on va manger des chips!" << std::endl;
	outfile << "Gene " << nbGene
		<< "," << "score"
		<< "," << "distance"
		<< "," << "isSelected"
		<< "," << "wrist"
		<< "," << "wrist"
		<< "," << "elbow"
		<< "," << "elbow"
		<< "," << "shoulder"
		<< "," << "shoulder"
		<< endl;

	int id = 0;
	for each (auto robotPair in robots)
	{
		//outfile << robotPair.first
		//	<< endl;
		for each (Robot robot in robotPair.second)
		{
			outfile << id++
				<< "," << robot.getScore()
				<< "," << robot.getDistance()
				<< "," << robot.isSelected()
				<< "," << robot.getWrist().first
				<< "," << robot.getWrist().second
				<< "," << robot.getElbow().first
				<< "," << robot.getElbow().second
				<< "," << robot.getShoulder().first
				<< "," << robot.getShoulder().second
				<< endl;
		}
	}

	outfile.close();
}

typedef tokenizer<escaped_list_separator<char> > boost_tok;

std::map<int, std::vector<Robot>> &		FileManager::initGeneFromFile(int nbGene)
{
	path file_path;
	getFileGenePath(file_path, nbGene);
	std::ifstream infile(file_path.c_str());

	string s;//= "score,distance,selected,wrist,elbow,shoulder";
	int totoScore = 0;//tmp, while we have a map instead of a vector
	getline(infile, s);//skip first line with column titles
	while (getline(infile, s))
	{
		Robot robot;
		if (!initRobotFromString(robot, s))
			break;
		vector<Robot> robot_friends;//tmp, while we have a map instead of a vector
		robot_friends.push_back(robot);
		_lastReadGene.emplace(totoScore++, robot_friends);

	}

	infile.close();

	return _lastReadGene;
}

bool	FileManager::initRobotFromString(Robot& robot, string const& datas)
{
	boost_tok tok(datas);
	vector<string> robot_datas;
	for (boost_tok::iterator it = tok.begin(); it != tok.end(); ++it) {
		cout << *it << "\t";
		robot_datas.push_back(*it);
	}
	if (robot_datas.size() < 10) {
		cout << "not enough datas to create a robot: " << datas << "\t";
		return false;
	}
	else {
		Robot robot;
		int score = stoi(robot_datas[1]);
		robot.setScore(score);
		robot.setDistance(stof(robot_datas[2]));
		if (robot_datas[3] == "1") {
			robot.select();
		}
		else {
			robot.resetSelection();
		}
		robot.setWrist(pair<simxInt, simxInt>(stoi(robot_datas[4]), stoi(robot_datas[5])));
		robot.setElbow(pair<simxInt, simxInt>(stoi(robot_datas[6]), stoi(robot_datas[7])));
		robot.setShoulder(pair<simxInt, simxInt>(stoi(robot_datas[8]), stoi(robot_datas[9])));
	}
	return true;
}

void FileManager::getFileGenePath(path & file_path, int nbGene)
{
	file_path = _fileName;
	file_path += "/" + _fileName + "_" + to_string(nbGene) + ".csv";
	std::ifstream infile(file_path.c_str());
}





//const char * say_what(bool b) { return b ? "true" : "false"; }

//	cout << "\ncomposed path:\n";
//	cout << "  operator<<()---------: " << p << "\n";
//	cout << "  make_preferred()-----: " << p.make_preferred() << "\n";
//
//	cout << "\nelements:\n";
//	for (auto element : p)
//		cout << "  " << element << '\n';
//
//	cout << "\nobservers, native format:" << endl;
//# ifdef BOOST_POSIX_API
//	cout << "  native()-------------: " << p.native() << endl;
//	cout << "  c_str()--------------: " << p.c_str() << endl;
//# else  // BOOST_WINDOWS_API
//	wcout << L"  native()-------------: " << p.native() << endl;
//	wcout << L"  c_str()--------------: " << p.c_str() << endl;
//# endif
//	cout << "  string()-------------: " << p.string() << endl;
//	wcout << L"  wstring()------------: " << p.wstring() << endl;
//
//	cout << "\nobservers, generic format:\n";
//	cout << "  generic_string()-----: " << p.generic_string() << endl;
//	wcout << L"  generic_wstring()----: " << p.generic_wstring() << endl;
//
//	cout << "\ndecomposition:\n";
//	cout << "  root_name()----------: " << p.root_name() << '\n';
//	cout << "  root_directory()-----: " << p.root_directory() << '\n';
//	cout << "  root_path()----------: " << p.root_path() << '\n';
//	cout << "  relative_path()------: " << p.relative_path() << '\n';
//	cout << "  parent_path()--------: " << p.parent_path() << '\n';
//	cout << "  filename()-----------: " << p.filename() << '\n';
//	cout << "  stem()---------------: " << p.stem() << '\n';
//	cout << "  extension()----------: " << p.extension() << '\n';
//
//	cout << "\nquery:\n";
//	cout << "  empty()--------------: " << say_what(p.empty()) << '\n';
//	cout << "  is_absolute()--------: " << say_what(p.is_absolute()) << '\n';
//	cout << "  has_root_name()------: " << say_what(p.has_root_name()) << '\n';
//	cout << "  has_root_directory()-: " << say_what(p.has_root_directory()) << '\n';
//	cout << "  has_root_path()------: " << say_what(p.has_root_path()) << '\n';
//	cout << "  has_relative_path()--: " << say_what(p.has_relative_path()) << '\n';
//	cout << "  has_parent_path()----: " << say_what(p.has_parent_path()) << '\n';
//	cout << "  has_filename()-------: " << say_what(p.has_filename()) << '\n';
//	cout << "  has_stem()-----------: " << say_what(p.has_stem()) << '\n';
//	cout << "  has_extension()------: " << say_what(p.has_extension()) << '\n';

