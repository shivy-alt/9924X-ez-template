#include "main.h"
/*#include "lift.hpp"
#include "EZ-Template/util.hpp"
#include "autons.hpp"
#include "lift.cpp"
#include "pros/misc.h"*/
#include "pros/motors.h"
#include "subsystems.hpp"






/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////



 /*bool liftToggle = false;

pros::Task Lift_Task(lift_task);*/



// Chassis constructor
// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-19, 11, -12},     // Left Chassis Ports (negative port will reverse it!)
    {5, 7, -6},  // Right Chassis Ports (negative port will reverse it!)

    15,      // IMU Port
    2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
/*const float Kp=0.5;   // const float Kp=0.5;
const float Ki=0.01;  // const float Ki=0.01; 
const float Kd=1.5;   // const float Kd=0.1;

const int POSITION_TOLERANCE= 500;
const int MAX_OUTPUT=50;*/

/*void moveArmToPosition(int targetPosition){
int error= 0, lastError=0;
int integral=0;
int derivative=0;
ldb_motor1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
ldb_motor2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

while(true){
    int currentPosition = ldb_sensor.get_position();
    error= targetPosition - currentPosition;

    if(std::abs(error) <= POSITION_TOLERANCE){
        ldb_motor1.brake();
        ldb_motor2.brake();
        break;
    }

    integral += error;
    derivative =  error - lastError;
    lastError = error;

    int output = (Kp*error) + (Ki*integral ) + (Kd * derivative);

    output= std::clamp(output, -MAX_OUTPUT, MAX_OUTPUT);

    ldb_motor1.move_velocity(output);
    ldb_motor2.move_velocity(output);

    pros::delay(20);

    }
}*/
int ladyBrownBoolCounter=0;

/*void ladyBrownVariableCount(){
    if (ladyBrownBoolCounter==0){
        moveArmToPosition(0.0);
    }

    if (ladyBrownBoolCounter==1){
        moveArmToPosition(2600);
    }

    if (ladyBrownBoolCounter==2){
        
        moveArmToPosition(13500.0);
        pros::delay(50);
        
    }

    if (ladyBrownBoolCounter>1){
        ladyBrownBoolCounter=0;
        moveArmToPosition(0.0);

    if (ldb_sensor.get_position()>2583){
      ladyBrownBoolCounter=1;
      moveArmToPosition(0.0);
    }
    }
}*/






void initialize() {
  ldb_sensor.reset_position();
  // Print our branding over your terminal :D
  ez::ez_template_print();

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(false);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(0, 0);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
    
    Auton("4 RING (1+3) red", five_ring_red_side),
      Auton("Pos Safe Auto red (1+1)",pos_safe),
      Auton("Pos Goal Rush red (1+1+1)",goal_rush),
      Auton("Pos Safe Blue Auto (1+1)",pos_safe_blue),
      Auton("4 RING (1+3) BLUE",five_ring_blue_side),
      Auton("Sig Solo Awp (1+2+1) red",sig_sawp),
      Auton("Auton Skills",auto_skills),
      
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");


 
  
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
  ldb_sensor.reset_position();
}
/*void ldb_task() {
  pros::delay(2000);
  while (true){
    set_lift(ldbPID.compute(ldb_sensor.get_position()/100.0));

    pros::delay(ez::util::DELAY_TIME);
  }
}*/

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency
 

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
  

  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);
  ldb_motor1.set_brake_mode(MOTOR_BRAKE_HOLD);
  ldb_motor2.set_brake_mode(MOTOR_BRAKE_HOLD);
   bool ldb_bool = false;
  while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT))
        chassis.pid_tuner_toggle();

      // Trigger the selected autonomous routine
      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

    chassis.opcontrol_arcade_standard(ez::SPLIT);  // Tank control
    // chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade
  static bool  mogo_bool= false;
  static bool hang_bool = false;
  static bool sweeper_bool = false
;  
    // . . .
    // Put more user control code here!
    // . . .
    if(control.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
      intake1.move(127);
      
    } else if(control.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
      intake1.move(-127);
      
    } else{
      intake1.move(0);
      
    }
    if(control.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){
      sweeper_bool=!sweeper_bool;
      sweeper.set_value(sweeper_bool);
    }
    
    if(control.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
      mogo_bool=!mogo_bool;
      mogo_clamp.set_value(mogo_bool);

    
   
    }
   
    
   

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
      /*ladyBrownVariableCount();
      ladyBrownBoolCounter++;*/
      moveArmToPosition(2380);
      pros::delay(10);
      moveArmToPosition(2380);
      ldb_bool = false;


     // moveArmToPosition(9000);

    }
   
    
  
   if(control.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
      ldb_motor1.move(127);
      ldb_motor2.move(127);
      ldb_bool = true;

      
    } else if(control.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
      ldb_motor1.move(-127);
      ldb_motor2.move(-127);
      ldb_bool = true;

      
    } else{
      if (ldb_bool == true){
        ldb_motor1.move(0);
        ldb_motor2.move(0);
      }

      else{
        ldb_motor1.move(2);
        ldb_motor2.move(2);
      }
       
      
    }

     

     
    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }

  
}