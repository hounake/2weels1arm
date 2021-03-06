//#include "stdafx.h"
//#include "Vrep.h"
//
//#include <string>
//
//Vrep::Vrep()
//{ // Empty
//}
//
//
//Vrep::~Vrep()
//{
//	simxFinish(m_client);
//}
//
//void Vrep::start(){
//	simxStartSimulation(m_client, simx_opmode_oneshot_wait);
//	simxGetObjectPosition(m_client, m_robotHandle, -1, &m_startPos[0], simx_opmode_streaming);
//}
//
//void Vrep::stop(){
//	simxGetObjectPosition(m_client, m_robotHandle, -1, &m_endPos[0], simx_opmode_streaming);
//	simxStopSimulation(m_client, simx_opmode_oneshot_wait);
//	extApi_sleepMs(200);
//}
//
//
//void Vrep::init(){
//	m_client = simxStart((simxChar*)"127.0.0.1", m_port, true, true, 2000, 5);
//	if (m_client == -1)
//	{
//		throw std::string("simxStart Error.");
//	}
//
//	auto opmode = simx_opmode_oneshot_wait;
//
//	simxGetObjectHandle(m_client, "WristMotor", &m_wristHandle, simx_opmode_oneshot_wait);
//	simxGetObjectHandle(m_client, "ElbowMotor", &m_elbowHandle, simx_opmode_oneshot_wait);
//	simxGetObjectHandle(m_client, "ShoulderMotor", &m_shoulderHandle, simx_opmode_oneshot_wait);
//	simxGetObjectHandle(m_client, "2W1A", &m_robotHandle, simx_opmode_oneshot_wait);
//	
//}
//
//float Vrep::calculDistance(){
//
//	float distance = 0;
//
//
//
//	return distance;
//}
//
//void Vrep::execRobot(Robot &robot){
//
//	auto opmode = simx_opmode_oneshot_wait;
//
//	start();
//
//	for (size_t i = 0; i < length; i++)
//	{
//		simxSetJointTargetPosition(m_client, m_wristHandle, (180 / PI) * robot.getWrist().first, opmode);
//		simxSetJointTargetPosition(m_client, m_elbowHandle, (180 / PI) * robot.getElbow().first, opmode);
//		simxSetJointTargetPosition(m_client, m_shoulderHandle, (180 / PI) * robot.getShoulder().first, opmode);
//
//		simxSetJointTargetVelocity(m_client, m_wristHandle, (180 / PI) * robot.getWrist().second, opmode);
//		simxSetJointTargetVelocity(m_client, m_elbowHandle, (180 / PI) * robot.getElbow().second, opmode);
//		simxSetJointTargetVelocity(m_client, m_shoulderHandle, (180 / PI) * robot.getShoulder().second, opmode);
//
//		extApi_sleepMs(10);
//	}
//
//	stop();
//
//	robot.setDistance(calculDistance());
//}