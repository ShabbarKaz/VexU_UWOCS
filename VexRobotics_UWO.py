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
        if (controller.buttonUp.pressing()):
            moveForward()
            brain.screen.print("Up button pressed")
        if (controller.buttonDown.pressing()):
            brain.screen.print("Up button pressed")
            moveBackward()
        if (controller.buttonY.pressing()):
            brain.screen.print("Up button pressed")
            moveLeft()
        if (controller.buttonA.pressing()):
            brain.screen.print("Up button pressed")
            moveRight() 
        if (controller.buttonUp.pressing() and controller.buttonA.pressing()):
            brain.screen.print("Up and left button pressed")
            left_motors.set_velocity(50,PERCENT)
            right_motors.set_velocity(40,PERCENT)
            left_motors.stop()
            right_motors.stop()
        if (controller.buttonDown.pressing() and controller.buttonY.pressing()):
            brain.screen.print("Up and right button pressed")     
            left_motors.set_velocity(40,PERCENT)
            right_motors.set_velocity(50,PERCENT)
            left_motors.stop()
            right_motors.stop()        
        if(controller.buttonL2.pressing()):
            moveForward()
        if(controller.buttonR2.pressing()):   
            moveBackward()
        if(controller.buttonA.released(stop())):
           stop()


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
        left_motor1.spin(FORWARD)
        left_motor2.spin(FORWARD)
        right_motor1.spin(FORWARD)
        right_motor2.spin(FORWARD)
        wait(5,MSEC)

        left_motors.stop()
        right_motors.stop()

def moveBackward():
        #brain.screen.print("Move back ")
        left_motor1.spin(REVERSE)
        left_motor2.spin(REVERSE)
        right_motor1.spin(REVERSE)
        right_motor2.spin(REVERSE)
        wait(5,MSEC)
        left_motors.stop()
        right_motors.stop()


  
       
def moveLeft():
        #brain.screen.print("Move left ")
        left_motor1.spin(REVERSE)
        left_motor2.spin(REVERSE)
        right_motor1.spin(FORWARD)
        right_motor2.spin(FORWARD)
        wait(5,MSEC)

        left_motors.stop()
        right_motors.stop()


        

def moveRight():
        #brain.screen.print("Move right ")
        left_motor1.spin(FORWARD)
        left_motor1.
        left_motor2.spin(FORWARD)
        right_motor1.spin(REVERSE)
        right_motor2.spin(REVERSE)
        wait(5,MSEC)
        left_motors.stop()
        right_motors.stop()



competition = Competition(usercontrolled,autonomous)


# def moveWingsOut():
#     wings_motor.spin(FORWARD)
#     wings_motor.stop()

# def moveWingsIn():
#     wings_motor.spin(FORWARD)
#     wings_motor.stop()
    
