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
controller Controller = controller(primary);
motor left_motor1 = motor(PORT1, ratio18_1, false);
motor left_motor2 = motor(PORT2, ratio18_1, false);
motor_group left_motors = motor_group(left_motor1, left_motor2);

motor right_motor1 = motor(PORT3, ratio18_1, true);
motor right_motor2 = motor(PORT4, ratio18_1, true);
motor_group right_motors = motor_group(right_motor1, right_motor2);

motor lifting_arm1 = motor(PORT5, ratio36_1, true);
motor lifting_arm2 = motor(PORT6, ratio36_1, true);
motor_group lifiting_arms = motor_group(lifting_arm1,lifting_arm2);

motor wings =  motor(PORT7, ratio18_1,true);
motor catapult = motor (PORT8, ratio18_1,true );


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
left_motors.spin(reverse,100,percent);
right_motors.spin(reverse,100,percent);

}

void moveBackward() {
Brain.Screen.print("Move back ");
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
    left_motors.spin(reverse,95,percent);
    right_motors.spin(reverse,30,percent);
}

void leftWhileForward() {
   Brain.Screen.print("Move left forward ");
    left_motors.spin(reverse,30,percent);
    right_motors.spin(reverse,95,percent);
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



void openWings(){

  if(wings.position(turns) < 4.5){
     wings.spin(forward,120,percent);
  } 
  else {
    Brain.Screen.print("open wings else");
     wings.spin(forward,0,percent);
  }


  // if(wingsOpen){
  //   Brain.Screen.print("opening wings");
  //  //wings.spinFor(forward,1080,degrees);
  // }
  //    Brain.Screen.print("closing wings");
  //   //wings.spinFor(reverse,1080,degrees);
  // }
} 

void closeWings(){
   if(wings.position(turns) < 5 && wings.position(turns) > 0 ){
     wings.spin(reverse,120,percent);
  } 
  else {
     Brain.Screen.print("close wings else");
     wings.spin(reverse,0,percent);
  }
}


//basically when this will keep the the motor running backwards and we should be able to turn it off an on
void launchCatapult(bool catapultOn){
  if(catapultOn){
     Brain.Screen.print("catapult On");
catapult.spin(reverse,5,volt);
  }
else{
   Brain.Screen.print(" catapultof");
  catapult.setStopping(coast);
  catapult.stop();
}
}

int main() {
  
  bool catapultOn = false;


  while(true){

    // first set off if statment should be used for movment
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
      closeWings();
    } else if (Controller.ButtonR2.pressing()) {
      openWings();
    }
    else if(Controller.ButtonRight.pressing()){ // need to test this with the catapult
    catapultOn = !catapultOn;
    launchCatapult(catapultOn);
    } else {
    left_motors.setStopping(brake);
    right_motors.setStopping(brake);
    wings.setStopping(hold);
    left_motors.stop();
    right_motors.stop();
    wings.stop();


//second set of iff statments should be used for wings 
//lets check if we can open the wings while moving forward. 
    //  if (Controller.ButtonL2.pressing()) {
    //   closeWings();
    // } else if (Controller.ButtonR2.pressing()) {
    //   openWings();
    // else {
    //    wings.setStopping(hold);
    //    wings.stop();
    // }

//third set of if statments should be for the launcher

// the forth set of if statments should be for the lifting arm

    }
  }
  return 0; 
}
