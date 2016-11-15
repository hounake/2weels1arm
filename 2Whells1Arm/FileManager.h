//#pragma once
//
//#include <vector>
//#include "Robot.h"
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
//	void init(std::string &file);
//
//};

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <atltime.h>
#include <fstream>

class Time
{
public:
	static const std::string getTime()
	{
		std::ostringstream oss;

		CTime time = CTime::GetCurrentTime();
		oss << time.GetHour()
			<< ":"
			<< time.GetMinute()
			<< ":"
			<< time.GetSecond();

		return oss.str();
	}

	static const std::string getFileTime()
	{
		std::ostringstream oss;

		CTime time = CTime::GetCurrentTime();
		oss << "_"
			<< time.GetHour()
			<< "_"
			<< time.GetMinute()
			<< "_"
			<< time.GetSecond();

		return oss.str();
	}

	static const std::string getDate()
	{
		std::ostringstream oss;

		CTime time = CTime::GetCurrentTime();
		oss << time.GetDay()
			<< "/"
			<< time.GetMonth()
			<< "/"
			<< time.GetYear();

		return oss.str();
	}
};

class Logger
{
public:
	Logger()
	{// Empty
	}

	~Logger()
	{
		if (m_file.good())
			m_file.close();
		if (m_fileCsv.good())
			m_fileCsv.close();

		//m_file << "\n  ===============================================\n"
		//	<< "    End   Output log ( "
		//	<< Time::getDate()
		//	<< " at "
		//	<< Time::getTime()
		//	<< " ): "
		//	<< "\n  ===============================================\n\n";
		//m_file.flush();
	}

	void init() {
		std::string loggFileName = "logg" + Time::getFileTime() + ".txt";
		m_file.open(loggFileName.c_str(), std::ios::app);
		m_file.seekp(std::ios::beg);

		if (m_file.bad())
			throw "logg file error.";

		loggFileName = "loggCsv" + Time::getFileTime() + ".csv";
		m_fileCsv.open(loggFileName.c_str(), std::ios::app);
		m_fileCsv.seekp(std::ios::beg);

		if (m_file.bad())
			throw "loggCsv file error.";

		//m_file << "  ===============================================\n"
		//	<< "    Begin Output log ( "
		//	<< Time::getDate()
		//	<< " at "
		//	<< Time::getTime()
		//	<< " ): "
		//	<< "\n  ===============================================\n\n";
		//m_file.flush();
	}

	void writeLine(const std::string& msg)
	{
		m_file << msg << std::endl;
		m_file.flush();
	}

	void writeCsvLine(const std::string& msg)
	{
		m_fileCsv << msg << std::endl;
		m_fileCsv.flush();
	}

private:
	std::ofstream m_file;
	std::ofstream m_fileCsv;
};