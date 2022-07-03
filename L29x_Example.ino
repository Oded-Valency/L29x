/* Example program for L29x.h
this librrary has been written to eaze control on a 2 motor vhicle govern by a H-Bridge motor controller.
testd on L298D module via Arduino UNO R3
by: Valency Oded
last rev 1.2 at 29-Jul-2022 compilation error debud 1
 */
 
#include  "L29x.h"
//Left Motor
int enA = 6;  // Power 0..255
int in1 = 4;  
int in2 = 5;
//Right motor
int enB = 10;  // Power 0..255
int in3 = 9;
int in4 = 8;
// initialise values
int power   = 0 ; // motors power required
int heading = 0 ; // Steering Required 
L29x Robo (in1,  in2 , in3,  in4 ,  enA,  enB);

void setup() {
 
}

void loop() {
  Robo.steering (0,80);   // go straight, power 80
  delay(400);             // for 400 mili seconds
  Robo.steering (50,40);  // steer pivot right, power 40
  delay(550);             // for 550 mili seconds
  Robo.steering (0,0);    // stop
}
