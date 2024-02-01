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




// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}

#pragma endregion VEXcode Generated Robot Configuration
#include <stdio.h>
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

motor left_motor1 = motor(PORT1, ratio18_1, false);
motor left_motor2 = motor(PORT8, ratio18_1, false);
motor_group left_motors = motor_group(left_motor1, left_motor2);

motor right_motor1 = motor(PORT2, ratio18_1, true);
motor right_motor2 = motor(PORT9, ratio18_1, true);
motor_group right_motors = motor_group(right_motor1, right_motor2);

drivetrain all_motors = drivetrain(left_motors, right_motors);

optical Optical5 = optical(PORT5);

//public bool vex::motor::spinFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v)

void MoveForward(int x) {

    Brain.Screen.print("move forward ");
    //all_motors.driveFor(forward,x,inches,143,rpm);
    //all_motors.drive(forward);
    right_motors.spin(forward,95,percent);
    left_motors.spin(reverse,95,percent);
    


}

void MoveBackward(int x) {
    // left_motors.spin(reverse,x,volt);
    // right_motors.spin(reverse,x,volt);
Brain.Screen.print("move back" + x);

    left_motors.spinFor(forward, x, sec, 5, rpm);
    right_motors.spinFor(forward, x, sec, 143, rpm);
}

void Rotate(int x) {
    //left_motors.spinFor(forward, x, sec, 5, rpm);
    right_motors.spinFor(reverse, x, sec, 143, rpm);
}

void RotateLeft(int x) {
  Brain.Screen.print("rotate left" + x);
    Rotate(-x);
}

void RotateRight(int x) {
  Brain.Screen.print("rotate right" + x);
    Rotate(x);
}

void Stop() {
    all_motors.stop();
}

int main() {
    MoveForward(100);
    Stop();
    return 0;
}