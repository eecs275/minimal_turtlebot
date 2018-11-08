#include "minimal_turtlebot/turtlebot_controller.h"


void turtlebot_controller(turtlebotInputs turtlebot_inputs, uint8_t *soundValue, float *vel, float *ang_vel)
 {
	//turtlebot_inputs.centerBumperPressed;
	//turtlebot_inputs.rightBumperPressed;
	//turtlebot_inputs.leftBumperPressed;
	//turtlebot_inputs.nanoSecs;

	bool bumper_flag=false;
	if (turtlebot_inputs.centerBumperPressed && bumper_flag==false){
		uint64_t time = turtlebot_inputs.nanoSecs;
		bumper_flag = true;
	}
	if (bumper_flag){
		if (turtlebot_inputs.nanoSecs -time <   10000000000.0){
			*vel = -0.2;}
		else if (turtlebot_inputs.nanoSecs -time <   20000000000.0){
			*vel = 0;		
			*ang_vel = 0.2;}
		else bumper_flag = false;
			
	}
	/*if (turtlebot_inputs.leftBumperPressed){
		float time = turtlebot_inputs.nanoSecs;
		*vel = -*vel;
		if (turtlebot_inputs.nanoSecs == time + 1){
			*vel = 0;		
			*ang_vel = 0.2;}
		if (turtlebot_inputs.nanoSecs == time + 4.93){
			*ang_vel = 0;
			*vel = 0.2;}
	}
	if (turtlebot_inputs.rightBumperPressed){
		float time = turtlebot_inputs.nanoSecs;
		*vel = -*vel;
		if (turtlebot_inputs.nanoSecs == time + 1){
			*vel = 0;		
			*ang_vel = -0.2;}
		if (turtlebot_inputs.nanoSecs == time + 4.93){
			*ang_vel = 0;
			*vel = 0.2;}
	}
*/
	*vel = 0.2; // Robot forward velocity in m/s
	//0.7 is max and is a lot
	*ang_vel = 0;  // Robot angular velocity in rad/s
	//0.7 is max and is a lot 
  
	*soundValue = 0;
  
	//here are the various sound value enumeration options
	//soundValue.OFF
	//soundValue.RECHARGE
	//soundValue.BUTTON
	//soundValue.ERROR
	//soundValue.CLEANINGSTART
	//soundValue.CLEANINGEND 

}

