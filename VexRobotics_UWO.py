#region VEXcode Generated Robot Configuration
from vex import *
import urandom

# Brain should be defined by default
brain=Brain()

# Robot configuration code
controller_1 = Controller(PRIMARY)
motor_group_1_motor_a = Motor(Ports.PORT1, GearSetting.RATIO_18_1, False)
motor_group_1_motor_b = Motor(Ports.PORT2, GearSetting.RATIO_18_1, False)
motor_group_1 = MotorGroup(motor_group_1_motor_a, motor_group_1_motor_b)
motor_group_3_motor_a = Motor(Ports.PORT3, GearSetting.RATIO_18_1, True)
motor_group_3_motor_b = Motor(Ports.PORT4, GearSetting.RATIO_18_1, True)
motor_group_3 = MotorGroup(motor_group_3_motor_a, motor_group_3_motor_b)


# wait for rotation sensor to fully initialize
wait(30, MSEC)


def play_vexcode_sound(sound_name):
    # Helper to make playing sounds from the V5 in VEXcode easier and
    # keeps the code cleaner by making it clear what is happening.
    print("VEXPlaySound:" + sound_name)
    wait(5, MSEC)

# add a small delay to make sure we don't print in the middle of the REPL header
wait(200, MSEC)
# clear the console to make sure we don't have the REPL in the console
print("\033[2J")

#endregion VEXcode Generated Robot Configuration
#Authors : 
#
#Description : this program is used to control the VexRobotics robot for over undercompetition taking place on january 13 in MSOE
#
#--------------------------------------------

#--------------------------------------------
#
#wiring guide : basically relevant parts list for the code
#
#
#
#--------------------------------------------


#defining variables for the motors and sensors

#Brain
brain = Brain()
controller = Controller(PRIMARY)


#motors - will need adjustment
left_motor1 = Motor(Ports.PORT1, GearSetting.RATIO_18_1, True) 
left_motor2 = Motor(Ports.PORT2, GearSetting.RATIO_18_1, True)
left_motors = MotorGroup(left_motor1,left_motor2)

right_motor1 = Motor(Ports.PORT3, GearSetting.RATIO_18_1, False)
right_motor2 = Motor(Ports.PORT4, GearSetting.RATIO_18_1, False)
right_motors = MotorGroup(right_motor1,right_motor2)


#wings_motor = Motor(Ports.PORT5, GearSetting.RATIO_18_1, True)
#claw_motor = Motor(Ports.PORT6, GearSetting.RATIO_18_1, True)
#launcher_motor = Motor(Ports.PORT7, GearSetting.RATIO_18_1, True)

#
# The purpose of this method is to move allow for the robot to turn it in a certain angle 
#depending on the direction of turning some wheels will be moving forward and some will be moving backwards
#    
    

#
# The purpose of this method is to move the robot in a straigt line either to the front or to the back
# #we need to figure out how to do implement this method
#       
def autonomous():  
    #move forward
    #left_motor1.run(100)

    print("autonomous")
    
#
# The purpose of this method is to move the robot in a straigt line either to the front or to the back
# #we need to figure out how to do implement this method 
#       
def usercontrolled():
    #movements for the wheels 
    while(True):
        # if (controller.buttonUp.pressing() and controller.buttonA.pressing()):
        #     brain.screen.print("Up and left button pressed")
        #     left_motors.set_velocity(50,PERCENT)
        #     right_motors.set_velocity(40,PERCENT)
        # elif (controller.buttonDown.pressing() and controller.buttonY.pressing()):
        #     brain.screen.print("Up and right button pressed")     
        #     left_motors.set_velocity(40,PERCENT)
        #     right_motors.set_velocity(50,PERCENT) 

        if(controller.buttonUp.pressing() and controller.buttonA.pressing()):
            rightWhileForward()

        elif(controller.buttonUp.pressing() and controller.buttonY.pressing() ):
            leftWhileForward()
        
        elif (controller.buttonUp.pressing()):
            moveForward()
            brain.screen.print("Up button pressed")
        elif (controller.buttonDown.pressing()):
                brain.screen.print("Down button pressed")
                moveBackward()
        elif (controller.buttonY.pressing()):
                brain.screen.print("Y button pressed")
                moveLeft()
        elif (controller.buttonA.pressing()):
                brain.screen.print("A button pressed")
                moveRight() 
        elif(controller.buttonL2.pressing()):
            moveForward()
        elif(controller.buttonR2.pressing()):   
            moveBackward()
        else:
            left_motors.stop()
            right_motors.stop()    




     #movement for the wings
     #movement for the claw             
#
# 
# the further methods will be determined as we go along/get to know about the design of the robot itself 



#
# The purpose of this method is to move the robot in a straigt line either to the front or to the back
#we need to figure out how to do implement this method
#
def moveForward():
    #brain.screen.print("Move forward ")
    # right_motors.set_velocity(50,PERCENT)
    # left_motors.set_velocity(50,PERCENT)

    left_motors.spin(FORWARD,10,VOLT)
    right_motors.spin(FORWARD,10,VOLT)

def moveBackward():
    brain.screen.print("Move back ")
    # left_motors.set_velocity(-50,PERCENT)
    # right_motors.set_velocity(-50,PERCENT)

    left_motors.spin(REVERSE,10,VOLT)
    right_motors.spin(REVERSE,10,VOLT)
       
def moveLeft():
    brain.screen.print("Move left ")
    # left_motors.set_velocity(-50,PERCENT)
    # right_motors.set_velocity(50,PERCENT)

    left_motors.spin(REVERSE,10,VOLT)
    right_motors.spin(FORWARD,10,VOLT)

def moveRight():
    brain.screen.print("Move right ")
    # left_motors.set_velocity(50,PERCENT)
    # right_motors.set_velocity(-50,PERCENT)

    left_motors.spin(FORWARD,10,VOLT)
    right_motors.spin(REVERSE,10,VOLT)

def rightWhileForward():

    left_motors.spin(FORWARD,10,VOLT)
    right_motors.spin(FORWARD,5,VOLT)

def leftWhileForward():

    left_motors.spin(FORWARD,5,VOLT)
    right_motors.spin(FORWARD,10,VOLT)

def rightWhileBack():
    brain.screen.print("move right while forward")
    
    left_motors.spin(REVERSE,10,VOLT)
    right_motors.spin(REVERSE,5,VOLT)    

def leftWhileBack():
    brain.screen.print("move left while forward")
    left_motors.spin(REVERSE,5,VOLT)
    right_motors.spin(REVERSE,10,VOLT)




competition = Competition(usercontrolled,autonomous)


# def moveWingsOut():
#     wings_motor.spin(FORWARD)
#     wings_motor.stop()

# def moveWingsIn():
#     wings_motor.spin(FORWARD)
#     wings_motor.stop()
    
