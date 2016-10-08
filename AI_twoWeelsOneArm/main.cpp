#include "AlgoGen.h"


void mainFrame(int clientID, simxInt& opmode, simxInt& wristHandle, simxInt& elbowHandle, simxInt& shoulderHandle, simxInt& robotHandle)
{
	simxInt errorcode;
	simxInt next;
	cout << "('Roger is ready to seek and destroy')" << endl;
	simxFloat position[3];
	simxFloat orientation[3];
	simxFloat end_position[3];
	simxFloat end_orientation[3];
	errorcode = simxGetObjectPosition(clientID, robotHandle, -1, &position[0], simx_opmode_streaming);
	errorcode = simxGetObjectOrientation(clientID, robotHandle, -1, &orientation[0], simx_opmode_streaming);
	extApi_sleepMs(5000);
	while (42)
	{
		errorcode = simxGetObjectPosition(clientID, robotHandle, -1, &position[0], simx_opmode_streaming);
		errorcode = simxGetObjectOrientation(clientID, robotHandle, -1, &orientation[0], simx_opmode_streaming);
		if (errorcode == 0 || errorcode == 1)
		{
			cout << "('Roger's conquer module found')" << "2w1a position is: (x = " << position[0] << ", y = " << position[1] << ", z= " << position[2] << ")" << endl;
			cout << "('Roger's watching in the future')" << "2w1a rotation is: (x = " << orientation[0] << ", y = " << orientation[1] << ", z= " << orientation[2] << ")" << endl;

			for (int i = 0; i < 5; i++)
			{
				srand(time(NULL));
				simxFloat pwrist, pelbow, pshoulder;
				simxFloat awrist = (rand() % 360) * PI / 180;
				simxFloat aelbow = (rand() % 360) * PI / 180;
				simxFloat ashoulder = (rand() % 360) * PI / 180;

				cout << "Motors target positions: " << ashoulder << " " << aelbow << " " << awrist << endl;
				simxSetJointTargetPosition(clientID, wristHandle, awrist, opmode);
				simxSetJointTargetPosition(clientID, elbowHandle, aelbow, opmode);
				simxSetJointTargetPosition(clientID, shoulderHandle, ashoulder, opmode);
				extApi_sleepMs(1000);

				//Get the motors effective positions after the movement sequence
				simxGetJointPosition(clientID, wristHandle, &pwrist, opmode);
				simxGetJointPosition(clientID, elbowHandle, &pelbow, opmode);
				simxGetJointPosition(clientID, shoulderHandle, &pshoulder, opmode);
				cout << "Motors reached positions: " << pwrist << " " << pelbow << " " << pshoulder << endl;

				//Get the robot position & orientation after the movement sequence
				simxGetObjectPosition(clientID, robotHandle, -1, &end_position[0], simx_opmode_buffer);
				simxGetObjectOrientation(clientID, robotHandle, -1, &end_orientation[0], simx_opmode_buffer);
				cout << "('Roger's conquer module found')" << "2w1a position is: (x = " << end_position[0] << ", y = " << end_position[1] << ", z= " << end_position[2] << ")" << endl;
				cout << "('Roger's watching in the future')" << "2w1a rotation is: (x = " << end_orientation[0] << ", y = " << end_orientation[1] << ", z= " << end_orientation[2] << ")" << endl;
			}
		}
		else
			cout << "('Roger's conquer module not found') error: " << errorcode << endl;
		extApi_sleepMs(2000);
	}
}

int main()
{
	simxInt wristHandle;
	simxInt elbowHandle;
	simxInt shoulderHandle;
	simxInt robotHandle;
	simxInt opmode = simx_opmode_oneshot_wait;
	simxFinish(-1);
	int clientID = simxStart((simxChar*)"127.0.0.1", 19997, true, true, 5000, 5);
	if (clientID != -1)
	{
		cout << "('Connected to remote API server')" << endl;



		simxInt wristHandleRet = simxGetObjectHandle(clientID, "WristMotor", &wristHandle, opmode);
		simxInt elbowHandleRet = simxGetObjectHandle(clientID, "ElbowMotor", &elbowHandle, opmode);
		simxInt shoulderHandleRet = simxGetObjectHandle(clientID, "ShoulderMotor", &shoulderHandle, opmode);
		simxInt robotHandleRet = simxGetObjectHandle(clientID, "2W1A", &robotHandle, opmode);
		if (wristHandleRet + elbowHandleRet + shoulderHandleRet + robotHandleRet == simx_return_ok)
		{
			cout << "('Got all handles')" << endl;
			if (simxStartSimulation(clientID, opmode) == simx_return_ok)
			{
				mainFrame(clientID, opmode, wristHandle, elbowHandle, shoulderHandle, robotHandle);
				simxStopSimulation(clientID, opmode);
			}

		}
	}



	while (simxGetConnectionId(clientID) != -1)
	{

	}
	simxStopSimulation(clientID, opmode);
	//need wait brfore
	simxFinish(clientID);
	return 0;
}
