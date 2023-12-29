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
#define waitUntil(condition)                                                   
  do {                                                                         
    wait(5, msec);                                                             
  } while (!(condition))

#define repeat(iterations)                                                     
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
controller Controller = controller(primary);
motor left_motor1 = motor(PORT1, ratio18_1, false);
motor left_motor2 = motor(PORT2, ratio18_1, false);
motor_group left_motors = motor_group(left_motor1, left_motor2);

motor right_motor1 = motor(PORT3, ratio18_1, true);
motor right_motor2 = motor(PORT4, ratio18_1, true);
motor_group right_motors = motor_group(right_motor1, right_motor2);




// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

void moveForward() {
     Brain.Screen.print("Move forward ");

//Drivetrain.setDriveVelocity(50,percent);


left_motors.spin(reverse,100,percent);
right_motors.spin(reverse,100,percent);

}

void moveBackward() {
   Brain.Screen.print("Move back ");
//Drivetrain.setDriveVelocity(-50,percent);
 left_motors.spin(forward,100,percent);
 right_motors.spin(forward,100,percent);
}

void moveLeft() {

 Brain.Screen.print("Move left ");
 left_motors.spin(forward,95,percent);
 right_motors.spin(reverse,95,percent);
}

void moveRight() {

 Brain.Screen.print("Move right ");
 left_motors.spin(reverse,95,percent);
 right_motors.spin(forward,95,percent);
}

void rightWhileForward() {
   Brain.Screen.print("Move forward right ");
    // left_motors.spin(forward, 10, percent);
    // right_motors.spin(reverse, 5, percent );
    left_motors.spin(reverse,70,percent);
    right_motors.spin(reverse,30,percent);
}

void leftWhileForward() {
   Brain.Screen.print("Move left forward ");
    // left_motors.spin(forward, 5, volt);
    // right_motors.spin(forward, 10, volt);
    left_motors.spin(reverse,30,percent);
    right_motors.spin(reverse,70,percent);
}

void rightWhileBack() {
   Brain.Screen.print("Move right while forward");
     left_motors.spin(forward, 30, percent);
     right_motors.spin(forward, 95, percent);

}

void leftWhileBack() {
    // brain.screen.print("Move left while forward");
     left_motors.spin(forward, 30, percent);
    right_motors.spin(forward, 95, percent);
 }

int main() {
  
  while(true){
    if (Controller.ButtonUp.pressing() && Controller.ButtonA.pressing()) {
        rightWhileForward();
    } else if (Controller.ButtonUp.pressing() && Controller.ButtonY.pressing()) {
        leftWhileForward();
    } else if (Controller.ButtonDown.pressing() && Controller.ButtonA.pressing()) {
        rightWhileBack();
    } else if (Controller.ButtonDown.pressing() && Controller.ButtonY.pressing()) {
        leftWhileBack();
    } else if (Controller.ButtonUp.pressing()) {
        moveForward();
        //Brain.screen.print("Up button pressed");
    } else if (Controller.ButtonDown.pressing()) {
       // Brain.screen.print("Down button pressed");
        moveBackward();
    } else if (Controller.ButtonY.pressing()) {
       // Brain.screen.print("Y button pressed");
        moveLeft();
    } else if (Controller.ButtonA.pressing()) {
       // Brain.screen.print("A button pressed");
        moveRight();
    } else if (Controller.ButtonL2.pressing()) {
        moveForward();
    } else if (Controller.ButtonR2.pressing()) {
        moveBackward();
    } else {
    //Drivetrain.setStopping(brake);
    left_motors.setStopping(brake);
    right_motors.setStopping(brake);
    left_motors.stop();
    right_motors.stop();



    }
  }
  return 0; 
}
