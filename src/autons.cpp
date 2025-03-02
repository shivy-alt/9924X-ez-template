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
void wait(){
  chassis.pid_wait();
}

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

void relative_turn(double target, int turn_speed, bool turn_slew){
  chassis.pid_turn_relative_set(target, turn_speed, turn_slew);
  
}

void regular_turn(double target, int turn_speed, bool turn_slew){
  chassis.pid_turn_set(target, turn_speed, turn_slew);
  
}
void move_ldb(int velocity, int delay){
  ldb_motor1.move(velocity);
  ldb_motor2.move(velocity);
  pros::delay(delay);

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
void five_ring(){
  drive_forward(0.35, 127, true);
  chassis.pid_wait();
  move_ldb(127, 300);
  pros::delay(150);
  pros::delay(20);
  move_ldb(0,50);
  drive_backward(0.5, 127, true);
  chassis.pid_wait();
  relative_turn(20, 127,true);
  wait();
  drive_backward(1, 70, true);
  chassis.pid_wait_until(0.5);
  move_ldb(-127, 300);
  chassis.pid_wait_until(0.75);
  move_ldb(0,50);
  wait();
  drive_backward(0.3,50, true);
  wait();
  clamp_mogo();
  intake_on();
  relative_turn(105, 100, true);
  wait();
  drive_forward(0.83, 120, true);
  wait();
  pros::delay(200);
  drive_backward(0.83, 120, true);
  wait();
  relative_turn(45,100,true);
  wait();
  drive_forward(0.87, 100,true);
  wait();
  relative_turn(-43,100,true);
  wait();
  drive_forward(0.87, 100,true);
  wait();
  pros::delay(500);
  relative_turn(10,100,true);
  wait();
  drive_backward(0.87, 100, true);
  wait();
  relative_turn(167, 100, true);
  wait();
  drive_forward(0.85,100,true);
  wait();




  
  
  /*move_ldb(-120);
  pros::delay(300);
  move_ldb(0);
  drive_backward(1.5, 70, true);
  chassis.pid_wait();
  clamp_mogo();
  intake_on();
  relative_turn(124, 100,true);
  chassis.pid_wait();
  drive_forward(1.15, 50, true);
  chassis.pid_wait();
  relative_turn(92, 100, true);
  chassis.pid_wait();
  drive_forward(0.75,30, true);
  chassis.pid_wait();
  drive_backward(0.25, 100, true);
  chassis.pid_wait();
  relative_turn(-25,100, true);
  chassis.pid_wait();
  drive_forward(0.5, 30, true);
  chassis.pid_wait();*/
}

void Two_Ring_Corner_Clear_Auto_BLUE(){
  
}

void goal_rush(){
  intake_on();
  drive_forward(1.65,127,true);
  chassis.pid_wait_until(1.32*tile_length);
  intake_off();
  sweeper.set_value(true);
  drive_backward(0.75,500, true);
  chassis.pid_wait_until(0.4*tile_length);
  sweeper.set_value(false);
  
  /*relative_turn(-54, 50, true);
  chassis.pid_wait();
  intake_on();
  drive_forward(0.6,50, true);
  chassis.pid_wait();
  intake_off();
  relative_turn(-110, 100, true);
  chassis.pid_wait();
  drive_backward(0.5, 50,true);
  chassis.pid_wait();
  clamp_mogo();
  intake_on();
  drive_forward(1.5, 70, true);
  chassis.pid_wait();
  intake_off();
  pros::delay(250);
  unclamp_mogo();
  pros::delay(500);
  relative_turn(56.5, 100, true);
  chassis.pid_wait();
  drive_forward(1.67, 90, true);
  chassis.pid_wait();
  ldb_motor1.move(127);
  ldb_motor2.move(127);
  pros::delay(200);
  ldb_motor1.move(0);
  ldb_motor2.move(0);
  relative_turn(-25, 50, true);
  chassis.pid_wait();
  drive_backward(0.75, 100, true);
  chassis.pid_wait();*/

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

  
}


void auto_skills(){
  //scoring preload onto alliance stake
  intake_on();
  pros::delay(500);

  //going for first mogo
  chassis.pid_drive_set(0.55*tile_length, 80, true);
  pros::delay(350);
  chassis.pid_wait();
  chassis.pid_turn_relative_set(-90, 115, true);
  pros::delay(500);
  chassis.pid_drive_set(-0.62*tile_length,50,true);
  chassis.pid_wait();
  pros::delay(500);
  mogo_clamp.set_value(true);
  pros::delay(250);

  //scoring ring #1 into mogo #1
  chassis.pid_turn_relative_set(110,115,true);
  pros::delay(500);
  intake_on();
  chassis.pid_drive_set(1.2*tile_length,110,true);
  pros::delay(1500);

  //getting ring #2 and aligning for wall stake
  chassis.pid_turn_relative_set(38,100,true);
  pros::delay(500);
  chassis.pid_drive_set(1.4*tile_length,65,true);
  moveArmToPosition(2850);
  pros::delay(10);
  moveArmToPosition(2851);
  pros::delay(1000);
  chassis.pid_drive_set(0.2*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(32,100,true);
  pros::delay(500);

  //scoring wall stake
  chassis.pid_drive_set(0.2*tile_length,100,true);
  intake_on();
  chassis.pid_wait();
  pros::delay(100);
  intake_off();
  pros::delay(20);
  intake_on();
  pros::delay(20);
  intake_off();
  move_ldb(127, 280);
  pros::delay(200);
  move_ldb(0, 280);
  pros::delay(100);
  intake_on();
  chassis.pid_wait();
  chassis.pid_drive_set(-0.3*tile_length,100,true);
  pros::delay(500);
  move_ldb(-127, 500);
  pros::delay(500);
  move_ldb(0, 10);
  pros::delay(10);
  chassis.pid_drive_set(-0.3*tile_length,100,true);
  chassis.pid_wait();
  intake_on();

  //scoring ring #3 onto mogo #1
  chassis.pid_turn_relative_set(92,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(1.9*tile_length,60,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(0.4*tile_length,100,true);
  pros::delay(300);

  //score mogo in corner
  chassis.pid_turn_relative_set(105,80,true);
  pros::delay(500);
  chassis.pid_drive_set(-2.1*tile_length,60,true);
  pros::delay(800);
  intake_off();
  mogo_clamp.set_value(false);
  pros::delay(300);

  //getting 2nd mogo
  chassis.pid_drive_set(1.7*tile_length,100,true);
  pros::delay(500);
  chassis.pid_wait();
  chassis.pid_turn_relative_set(-20,100,true);
  pros::delay(800);
  chassis.pid_drive_set(4*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(-176,80,true);
  pros::delay(500);
  chassis.pid_drive_set(-0.5*tile_length,50,true);
  chassis.pid_wait();
  pros::delay(500);
  mogo_clamp.set_value(true);
  pros::delay(250);

  //scoring ring #1 into mogo #2
  chassis.pid_turn_relative_set(-97,115,true);
  pros::delay(500);
  intake_on();
  chassis.pid_drive_set(1.2*tile_length,110,true);
  pros::delay(1500);

  //getting ring #2 and aligning for wall stake
  chassis.pid_turn_relative_set(-58,100,true);
  pros::delay(500);
  chassis.pid_drive_set(1.34*tile_length,65,true);
  moveArmToPosition(2850);
  pros::delay(10);
  moveArmToPosition(2851);
  pros::delay(1000);
  chassis.pid_drive_set(0.25*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(-40,100,true);
  pros::delay(500);

  //scoring wall stake
  chassis.pid_drive_set(0.4*tile_length,100,true);
  intake_on();
  chassis.pid_wait();
  pros::delay(100);
  intake_off();
  pros::delay(20);
  intake_on();
  pros::delay(20);
  intake_off();
  move_ldb(127, 280);
  pros::delay(200);
  move_ldb(0, 280);
  pros::delay(100);
  intake_on();
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,100,true);
  pros::delay(500);
  move_ldb(-127, 500);
  pros::delay(500);
  move_ldb(0, 10);
  pros::delay(10);
  chassis.pid_wait();
  intake_on();

  //scoring ring #3 onto mogo #2
  chassis.pid_turn_relative_set(-92,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(1.9*tile_length,60,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(0.4*tile_length,100,true);
  pros::delay(300);

  //score mogo in corner
  chassis.pid_turn_relative_set(-105,80,true);
  pros::delay(500);
  chassis.pid_drive_set(-2.1*tile_length,60,true);
  pros::delay(800);
  intake_off();
  mogo_clamp.set_value(false);
  pros::delay(300);

  //getting 3rd mogo
  chassis.pid_drive_set(1.7*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(-20,100,true);
  pros::delay(800);
  chassis.pid_drive_set(4*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(-176,80,true);
  pros::delay(500);
  chassis.pid_drive_set(-0.5*tile_length,50,true);
  chassis.pid_wait();
  pros::delay(500);
  mogo_clamp.set_value(true);
  pros::delay(250);

  //score mogo in corner
  chassis.pid_drive_set(-3*tile_length,80,true);
  pros::delay(500);
  mogo_clamp.set_value(false);

  //getting 4th mogo
  chassis.pid_drive_set(1.7*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(-20,100,true);
  pros::delay(800);
  chassis.pid_drive_set(4*tile_length,100,true);
  pros::delay(500);
  chassis.pid_turn_relative_set(-176,80,true);
  pros::delay(500);
  chassis.pid_drive_set(-0.5*tile_length,50,true);
  chassis.pid_wait();
  pros::delay(500);
  mogo_clamp.set_value(true);
  pros::delay(250);
  
  //scoring ring #1 into mogo #4
  chassis.pid_turn_relative_set(-97,115,true);
  pros::delay(500);
  intake_on();
  chassis.pid_drive_set(1.2*tile_length,110,true);
  pros::delay(1500);
  
  //score mogo in corner
  chassis.pid_turn_relative_set(52,80,true);
  pros::delay(500);
  chassis.pid_drive_set(-4*tile_length,60,true);
  pros::delay(800);
  mogo_clamp.set_value(false);

  //hang
  move_ldb(-127, 500);
  pros::delay(500);
  move_ldb(0, 10);
  pros::delay(10);
  chassis.pid_drive_set(3*tile_length, 200, true);
  pros::delay(500);
  chassis.pid_drive_set(-0.25*tile_length, 200, true);
}