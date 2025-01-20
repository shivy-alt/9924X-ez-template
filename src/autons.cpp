#include "autons.hpp"
#include "main.h"
#include "subsystems.hpp"
//blah

int tile_length=24;

void intake_on(){
  intake1.move(127);

  
}
void intake_off(){
  intake1.move(0);

  
}

void intake_reverse(){
  intake1.move(-127);
  

}




///
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80, 3, 250, 7, 500, 500);
  chassis.pid_swing_exit_condition_set(80, 3, 250, 7, 500, 500);
  chassis.pid_drive_exit_condition_set(80, 1, 250, 3, 500, 500);

  chassis.pid_turn_chain_constant_set(3);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

///
// Drive Example
///
void corner_clear_func(){
  sweeper.set_value(true);
  chassis.pid_turn_relative_set(45,120,true);
  sweeper.set_value(false);
}

void drive_forward(double distance, int speed, bool slew){
  chassis.pid_drive_set(tile_length*distance,speed,slew);
  
  
}

void drive_backward(double distance, int drive_speed, bool slew){
  chassis.pid_drive_set(-tile_length*distance,drive_speed,slew);
  
}

void relative_turn(int target, int turn_speed, bool turn_slew){
  chassis.pid_turn_relative_set(target, turn_speed, turn_slew);
  
}

void regular_turn(int target, int turn_speed, bool turn_slew){
  chassis.pid_turn_set(target, turn_speed, turn_slew);
  
}



void function_testing(){
  drive_forward(1.2, 50, false);
  pros::delay(2000);
  drive_backward(1.2,50,false);
  pros::delay(2000);
  relative_turn(45,50,false);
  pros::delay(2000);
  regular_turn(-45,50,false);
  

}
// . . .
// Make your own autonomous functions here!
// . . .
void Four_ring_auto_red_side(){
  drive_backward(1.2, 100, true);
  clamp_mogo();
  relative_turn(90, 100, true);
  intake_on();
  drive_forward(0.5, 110,true);
  pros::delay(500);
  intake_off();
  drive_backward(0.5, 100, true);

  


}

void Four_ring_auto_blue_side(){

}
void three_ring_and_wallstake(){
  
}
void Two_Ring_Corner_Clear_Auto_BLUE(){
  
}
void goal_rush(){
  drive_forward(1.67,127,true);
  chassis.pid_wait_until(0.8*tile_length);
  intake_on();
  chassis.pid_wait_until(tile_length*1.35);
  intake_off();
  sweeper.set_value(true);
  chassis.pid_wait();
  drive_backward(0.65,120,true);
  chassis.pid_wait();
  sweeper.set_value(false);
  /*relative_turn(165,100,true);
  chassis.pid_wait();
  drive_backward(0.25, 50, true);
  chassis.pid_wait();
  clamp_mogo();
  intake_on();
  pros::delay(300);
  drive_backward(tile_length*0.25, 10, true);
  chassis.pid_wait();
  relative_turn(164,100, true);
  chassis.pid_wait();
  drive_backward(0.525, 50, true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);
  intake1.move(127);
  pros::delay(350);
  drive_forward(0.55, 75, true);
  chassis.pid_wait_until(tile_length*0.5);
  mogo_clamp.set_value(false);
  pros::delay(500);
  relative_turn(-68, 100, true);
  chassis.pid_wait();
  drive_backward(1, 90, true);
  chassis.pid_wait();
  clamp_mogo();
  chassis.pid_wait_until(0.5);
  unclamp_mogo();
  relative_turn(90, 100, true);
  chassis.pid_wait();*/


}



void full_goal_auto(){
  
  


}
void solo_winpoint(){


//   chassis.pid_drive_set(-0.7*tile_length,100,true);
//   chassis.pid_wait();
//   chassis.pid_turn_relative_set(89,100,true);
//   chassis.pid_wait();
//   chassis.pid_drive_set(-0.37*tile_length,100,true);
//   chassis.pid_wait();
//   intake1.move(-127);

  
//   pros::delay(700);
//   intake1.move(0);
  
//   chassis.pid_drive_set(0.375*tile_length,100,true);
//   chassis.pid_wait();
//   chassis.pid_turn_relative_set(144,120,true);
//   chassis.pid_wait();
//   chassis.pid_drive_set(-1.7*tile_length,65,true);
//   chassis.pid_wait();
//   pros::delay(500);
//   mogo_clamp.set_value(true);
//   pros::delay(300);
//   chassis.pid_turn_relative_set(-190,100,true);
//   chassis.pid_wait();

//   intake_on();
//   chassis.pid_drive_set(1.25*tile_length,60,true);
//   chassis.pid_wait();
//   chassis.pid_drive_set(-tile_length*0.25,110,true);
//   chassis.pid_wait();
//   pros::delay(500);
//   chassis.pid_turn_relative_set(-25,100,true);
//   chassis.pid_wait();
//   chassis.pid_drive_set(0.7*tile_length,110,true);
//   chassis.pid_wait();
//   pros::delay(500);
//   chassis.pid_drive_set(-tile_length*0.75,120,true);
//   chassis.pid_wait();
//   pros::delay(100);
//   chassis.pid_turn_relative_set(-52.5,120,true);
//   chassis.pid_wait();
//   chassis.pid_drive_set(0.7*tile_length,100,true);
//   chassis.pid_wait();
  
//   pros::delay(700);
//   chassis.pid_drive_set(-tile_length*1,75,true);
//   chassis.pid_wait();
//   chassis.pid_turn_relative_set(25,100,true);
//   chassis.pid_drive_set(-0.5*tile_length,100,true);
//   chassis.pid_wait();

  


// }
void auto_skills(){
  //scoring preload onto alliance stake
    intake_on();
    pros::delay(500);

  //going for first mogo + scoring 6 rings
    chassis.pid_drive_relative_set(0.6*tile_length, 100, true);
    chassis.pid_wait();
    pros::delay(350);
    chassis.pid_turn_relative_set(-90, 115, true);
    pros::delay(500);
    chassis.pid_drive_relative_set(-0.65*tile_length,100,true);
    chassis.pid_wait();
    mogo_clamp.set_value(true);
    pros::delay(250);          

    chassis.pid_turn_relative_set(139,115,true);
    chassis.pid_wait();
    intake_on();
    chassis.pid_drive_relative_set(1.55*tile_length,110,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-25,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(0.8*tile_length,65,true);
    chassis.pid_wait();
    pros::delay(500);

    chassis.pid_turn_relative_set(171,120,true);
    chassis.pid_wait();

    chassis.pid_drive_relative_set(1.55*tile_length,115,true);
    chassis.pid_wait();
    pros::delay(350);
    chassis.pid_drive_relative_set(-0.6*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(28,80,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(0.9*tile_length,80,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-10,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(0.43*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(-0.6*tile_length,100,true);
    chassis.pid_wait();
    intake_on();
    chassis.pid_turn_relative_set(117,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(1.15*tile_length,100,true);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_turn_relative_set(10,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(-1.8*tile_length,60,true);
    chassis.pid_wait();
    mogo_clamp.set_value(false);
    pros::delay(300);
    chassis.pid_wait();

  //get the wall stake ring and score
    chassis.pid_turn_relative_set(45,100,true);
    pros::delay(500);
    ldb_motor1.move(127);
    ldb_motor2.move(127);
    intake_on();
    chassis.pid_turn_relative_set(135,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(0.9*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-45,100,true);
    chassis.pid_drive_relative_set(0.2*tile_length,100,true);
    ldb_motor1.move(127);
    ldb_motor2.move(127);

  //get 2nd mogo
    ldb_motor1.move(-127);
    ldb_motor2.move(-127);
    chassis.pid_drive_relative_set(-0.3*tile_length,100,true);
    chassis.pid_turn_relative_set(-135,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(3.5*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-235,100,true);
    chassis.pid_drive_relative_set(-0.65*tile_length,100,true);
    chassis.pid_wait();
    mogo_clamp.set_value(true);

  //score ring #1 into mogo #2
    chassis.pid_turn_relative_set(-140,115,true);
    chassis.pid_wait();
    intake_on();
    chassis.pid_drive_relative_set(1.55*tile_length,110,true);
    chassis.pid_wait();

  //score ring #2 onto mogo #2
    chassis.pid_turn_relative_set(30,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(0.8*tile_length,65,true);
    chassis.pid_wait();

  //score ring #3 onto mogo #2
    chassis.pid_turn_relative_set(-175,100,true);
    pros::delay(500);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_drive_relative_set(1.57*tile_length,115,true);
    chassis.pid_wait();
    pros::delay(350);

  //score ring #4 into mogo #2
    chassis.pid_drive_relative_set(-0.61*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(28,80,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(1*tile_length,80,true);
    chassis.pid_wait();
    
  //score ring #5 onto mogo #2
    chassis.pid_drive_relative_set(-0.61*tile_length, 100, true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-30,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(1.14*tile_length,100,true);
    chassis.pid_wait();
    intake_on();

  //score ring #6 onto mogo #2
    chassis.pid_turn_relative_set(-125,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(1.5*tile_length,100,true);
    chassis.pid_wait();
    pros::delay(500);

  //score mogo #2 into corner
    chassis.pid_turn_relative_set(10,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(-2*tile_length,60,true);
    chassis.pid_wait();
    mogo_clamp.set_value(false);
    pros::delay(300);

  //get ring to score on wall stake
    chassis.pid_turn_relative_set(45,100,true);
    pros::delay(500);
    chassis.pid_drive_relative_set(3*tile_length,100,true);
    ldb_motor1.move(127);
    ldb_motor2.move(127);
    intake_on();
    chassis.pid_turn_relative_set(180,100,true);
    chassis.pid_drive_relative_set(0.9*tile_length,100,true);
    chassis.pid_turn_relative_set(35,100,true);
    chassis.pid_drive_set(0.2*tile_length,100,true);
    ldb_motor1.move(127);
    ldb_motor2.move(127);

  //get 3rd mogo with blue ring
    chassis.pid_drive_relative_set(-0.3*tile_length,100,true);
    ldb_motor1.move(-127);
    ldb_motor2.move(-127);
    chassis.pid_turn_relative_set(-55,100,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(-3.5*tile_length,100,true);
    chassis.pid_wait();
    mogo_clamp.set_value(true);
    chassis.pid_turn_relative_set(-125,100,true);
    chassis.pid_drive_relative_set(-1.6*tile_length,100,true);
    mogo_clamp.set_value(false);
    pros::delay(300);

  //score alliance stake
    chassis.pid_turn_relative_set(35,100,true);
    chassis.pid_drive_relative_set(3*tile_length,100,true);
    intake1.move(127);
    intake2.move(127);
    chassis.pid_turn_relative_set(-60,100,true);
    chassis.pid_drive_relative_set(1.5*tile_length,100,true);
    chassis.pid_turn_relative_set(-35,100,true);
    chassis.pid_drive_relative_set(-0.2*tile_length,100,true);
    intake1.move(127);
    intake2.move(127);
    pros::delay(500);
    
  //get 4th mogo
    chassis.pid_drive_relative_set(0.2*tile_length,100,true);
    chassis.pid_turn_relative_set(180,100,true);
    chassis.pid_wait();
    mogo_clamp.set_value(true);

  //score ring #1 into mogo #4
    chassis.pid_turn_relative_set(135,115,true);
    chassis.pid_wait();
    chassis.pid_drive_relative_set(1.55*tile_length,110,true);
    intake_on();
    chassis.pid_wait();

  //score ring #2 onto mogo #4
    chassis.pid_turn_relative_set(-25,100,true);
    chassis.pid_drive_relative_set(0.8*tile_length,100,true);
    intake_on();
    chassis.pid_wait();
  
  //score ring #3 onto mogo #4
    chassis.pid_turn_relative_set(-45,120,true);
    chassis.pid_drive_relative_set(0.3*tile_length,120,true);
    intake_on();
    chassis.pid_wait();

  //score ring #4 onto mogo #4
    chassis.pid_turn_relative_set(135,120,true);
    chassis.pid_drive_relative_set(0.3*tile_length,120,true);
    intake_on();
    chassis.pid_wait();

  //score ring #5 onto mogo #4
    chassis.pid_turn_relative_set(90,120,true);
    chassis.pid_drive_relative_set(3*tile_length,120,true);
    intake_on();
    chassis.pid_wait();

  //score mogo #4 into corner
    chassis.pid_turn_relative_set(20,120,true);
    chassis.pid_drive_relative_set(-3.5*tile_length,120,true);
    mogo_clamp.set_value(false);
    pros::delay(300);

    //hang
    hang.set_value(true);
    chassis.pid_drive_relative_set(3*tile_length, 200, true);
    pros::delay(500);
    chassis.pid_drive_relative_set(-0.25*tile_length, 200, true);
} 