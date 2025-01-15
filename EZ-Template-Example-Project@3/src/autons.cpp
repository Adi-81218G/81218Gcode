#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

int tile_length=24;

void intake_on(){
  intake.move(-117);
  intake.move(117);
}
void intake_off(){
  intake.move(0);
  intake.move(0);
}

void intake_reverse(){
  intake.move(117);
  intake.move(-117);
}
// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  // https://ez-robotics.github.io/EZ-Template/tutorials/tuning_constants
  chassis.pid_drive_constants_set(19.65, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(9.0, 0.05, 60.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(9.5, 0.0, 65.0);           // Swing constants
  /*chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions*/

  // Exit conditions
  // https://ez-robotics.github.io/EZ-Template/tutorials/tuning_exit_conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  //chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
 //chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  // https://ez-robotics.github.io/EZ-Template/tutorials/slew_constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 50);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  //chassis.odom_turn_bias_set(0.9);

  /*chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);*/  // Changes the default behavior for turning, this defaults it to the shortest path there
}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

chassis.pid_drive_set(-0.8*tile_length,-120);
chassis.pid_wait();
chassis.pid_turn_set(-29_deg,60);
chassis.pid_wait();
  chassis.pid_drive_set(-0.53*tile_length,60,true);
  chassis.pid_wait();
  mogo_mech.set(true);
  chassis.pid_wait();


  intake_reverse();
  pros::delay(200);
  chassis.pid_turn_set(-100_deg,60,true);
  chassis.pid_wait();
  pros::delay(300);

  intake_reverse();
  chassis.pid_drive_set(0.8*tile_length,60,true);
  chassis.pid_wait();
  pros::delay(200);
  chassis.pid_drive_set(-0.25*tile_length,70,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_relative_set(-76_deg,60,true);
  chassis.pid_wait();
  intake_reverse();
  chassis.pid_drive_set(0.485*tile_length,70,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*0.75,60,true);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_turn_relative_set(21_deg,70,true);
  chassis.pid_wait();
  intake_reverse();
  chassis.pid_drive_set(0.93*tile_length,70,true);
  chassis.pid_wait();

  /*pros::delay(750);
  chassis.pid_drive_set(-tile_length*1.25,60,true);
  chassis.pid_wait();*/
}


// . . .
// Make your own autonomous functions here!
// . . .