

# falcon-motor
This project contains the motor part of a drone and some contents of wireless control.

Hardware:

Xbee S2C

arduino board

arduino wireless SD shield

SimonK 30A ESC brushless motor controller

Readytosky 2212 920kV brushless motor

11.1v 3s 20c lipo battery

buttons 

10koms resistor

Software:

XCTU

arduino

wire for the motor(see attach)

wire for the controller(see attach)

codes(see attach)

XCTU configurations:

Coordinator:

ID:4869                                 //unique ID for the network             

CE:enabled[1]                           //set as coordinator

DL:FFFF                                 //set it as broadcast Mode

Router:

ID:4869                                 //unique ID for the network

CE:disabled[0]                          //disable coordinator

DL:0                                    //default

JV:enabled[1]                           //enable channel verification(set as router)


process:

1.The motor was tested on a 5v DC power source. It is hard to decide which battery to use because I do not know how many power the power source need to supply in order to lift the drone and I also to make sure the current is not too big which will burn the motor.

2.I use a potentiometer to control the speed of motor. But serial.write() only transmit string values and transform string to int could be hard so I decide to use bottons to change speed when bottons are pressed.

3.at the beginning I send the data from coordinate to router which creates the lag for about 10s, since the mode is broadcast mode. Then I decide to send the values from router which almost has 0 lag.


Han Li
