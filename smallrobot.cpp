#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);
gps DrivetrainGPS = gps(PORT3, 0.00, 0.00, mm, 180);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainGPS, 319.19, 320, 40, mm, 18);


void calibrateDrivetrain() {
  wait(200, msec);
  Brain.Screen.print("Calibrating");
  Brain.Screen.newLine();
  Brain.Screen.print("GPS");
  DrivetrainGPS.calibrate();
  while (DrivetrainGPS.isCalibrating()) {
    wait(25, msec);
  }

  // Clears the screen and returns the cursor to row 1, column 1.
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
}

// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}

#pragma endregion VEXcode Generated Robot Configuration
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "vex.h"

using namespace vex;

// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS

// void playVexcodeSound(const char *soundName) {
//   printf("VEXPlaySound:%s\n", soundName);
//   wait(5, msec);
// }

controller Controller = controller(primary);
motor left_motor = motor(PORT1, ratio18_1, false);
motor right_motor = motor(PORT2, ratio18_1, true);
drivetrain all_motors = drivetrain(left_motor, right_motor);
motor infeed_motor = motor(PORT4, ratio18_1,true); 
optical Optical5 = optical(PORT5);

// Brain methods
void Brain_Print() { Brain.Screen.print("infeed reverse "); }

// Infeed methods
void Infeed_Collect(){ 
  infeed_motor.spin(forward,95,percent); 
}
void Infeed_Release(){ 
  infeed_motor.spin(reverse,95,percent);
}
void Infeed_Stop() { 
  infeed_motor.stop(); 
}

// Wheel methods
void Wheels_MoveForward(int x) { 
  all_motors.driveFor(forward,x,inches,143,rpm); 
}
void Wheels_MoveBackward(int x) { 
  all_motors.driveFor(forward,x,inches,143,rpm); 
}
void Wheels_RotateLeft(int x) { 
  all_motors.turnFor(right,x,degrees); 
}
void Wheels_RotateRight(int x) { 
  all_motors.turnFor(right,x,degrees); 
}
void Wheels_Stop() { 
  all_motors.stop(); 
}

void grabTriball(){
  Infeed_Collect();
  Infeed_Stop();
}

void releaseTriball(){
  Infeed_Release();
  Infeed_Stop();
}

//Code for the autonomous portion
void autonomousMode(){
    //Robot moves to the side of our goal
      Wheels_MoveForward(10);
      Wheels_RotateLeft(45);
      Wheels_MoveForward(10);
      Wheels_RotateLeft(45);
      Wheels_MoveForward(5);

    //Scores initial triball
      releaseTriball()

    //Move to alliance triball 
      Wheels_RotateLeft(160);
      Wheels_MoveForward(5);
      Wheels_RotateLeft(80);
      Wheels_MoveForward(5);

    //Grab alliance triball 
      grabTriball();

    //Move to goal
      Wheels_RotateLeft(100);
      Wheels_MoveForward(10);

    //Score alliance triball
      releaseTriball();

    //Move to defend 
      Wheels_MoveBackward(3);
      Wheels_RotateLeft(90);
      Wheels_MoveForward(5);

    //Defense strategy
      ????

    //Move to touch elevation bar
}

int main() {
    Wheels_MoveForward(50);
    Wheels_RotateRight(365);
    Wheels_Stop();
    return 0;
}
