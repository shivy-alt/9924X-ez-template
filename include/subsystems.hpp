#pragma once


#include "EZ-Template/PID.hpp"
#include "EZ-Template/piston.hpp"
#include "EZ-Template/util.hpp"
#include "api.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"




// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor intake1(20,pros::MotorGearset::blue);
//inline pros::adi::DigitalOut mogo_clamp(2);
inline pros::Controller control(pros::E_CONTROLLER_MASTER);
inline pros::adi::DigitalOut sweeper(1);
inline pros::adi::DigitalOut mogo_clamp(2);

inline pros::Rotation ldb_sensor(9);
inline pros::Motor ldb_motor1(-10);





inline void clamp_mogo(){
  mogo_clamp.set_value(true);
}

inline void unclamp_mogo(){
  mogo_clamp.set_value(false);
}


inline pros::Motor ldb_motor2(8);

inline ez::PID ldbPID{0.45, 0, 0, 0, "LadyBrown"};

inline void set_lift(int input){
    ldb_motor1.move(-127);
    ldb_motor2.move(127);
}

inline void ldb_wait() {
    while (ldbPID.exit_condition({ldb_motor1, ldb_motor2},true) == ez::RUNNING){
        pros::delay(ez::util::DELAY_TIME);
    }
}

inline const float Kp=4.5;   // const float Kp=0.5;
inline const float Ki=0.01;  // const float Ki=0.01; 
inline const float Kd=3;   // const float Kd=0.1;
inline int error= 0;
inline int lastError=0;
inline int integral=0;
inline int derivative=0;

inline const int POSITION_TOLERANCE= 500;
inline const int MAX_OUTPUT=127; // reason for ldb being slow is because this was set to 50 instead of max velocity; test next time at practice
inline void moveArmToPosition(int targetPosition){
    int error= 0;
    int lastError=0;
    int integral=0;
    int  derivative=0;

ldb_motor1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
ldb_motor2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);



    while(true){
        int currentPosition = ldb_sensor.get_position();
        error= targetPosition - currentPosition;
    
        if(std::abs(error) <= POSITION_TOLERANCE){
            ldb_motor1.brake();
            ldb_motor2.brake();
            break;
        }//add back if needed;
    
        integral += error;
        derivative =  error - lastError;
        lastError = error;
    
        int output = (Kp*error) + (Ki*integral ) + (Kd * derivative);
    
        output= std::clamp(output, -MAX_OUTPUT, MAX_OUTPUT);
    
        ldb_motor1.move_velocity(output);
        ldb_motor2.move_velocity(output);
    
        pros::delay(20);
    }
    

}
