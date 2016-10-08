#pragma once

#include "AI.h"
#include "Robot.h"

#define QUOI_FAIRE 0
 // {0: Create; 1: Reload; 2: Replay, ReplayRange}
 // Create -> create from generation 0
 // Reload -> reload a given LOGNAME file starting from the START_GEN generation and continue until TOTAL_GENE generation
 // Replay -> replay all robot on the LOGNAME file from START_GENE to END_GENE
 // ReplayRange -> replay [START_RANK: END_RANK] robot 
#define LOGNAME "LOG_TEST"
#define TOTAL_GENE 500
//#define 

class AlgoGen {
	std::vector<Robot>	Robots;


public:
	AlgoGen();
	~AlgoGen();

	int	start();
	int handle();
	void loadGeneration();
	void play();
};