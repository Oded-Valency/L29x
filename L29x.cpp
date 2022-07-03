/* cpp code for L29x.h library
this library has been written to eazy control on a 2 DC motor vehicle govern by a H-Bridge motor controller.
power   : int (-100..+100), where  -100 stand for Full Power Back  , 0 stand for Stop , +100 stand for Full Power Forward
heading : int (-100..+100), where  
  -100 stand for "Tank Left"  (left motor Back, right motor Forward)
   -50 stand for "Pivot Left" (left motor stop, right motor Forward)
     0 stand for "Stop"       (left motor stop, right motor stop)  
   -50 stand for "Pivot Right"(left motor Forward, right motor stop )
  -100 stand for "Tank Right" (left motor Forward, right motor Back )
  https://sites.google.com/site/ev3devpython/learn_ev3_python/using-motors
 
tested on L298D module via Arduino UNO R3
by: Valency Oded
last rev 1.2 at 29-Jul-2022   compilation error debud 1
rev 1.x predefine Arduino pin allocation,  
rev 2.x will get the arduino pin num from the user
*/
    //#include <Wire.h>
    //#include <Arduino.h>
#include "Arduino.h"
#include "L29x.h"

static int pos = 0;    // stores the servo position

// ***** General librery Objects Constractors  ***** 
//Servo servo1door;                   // set Object Servo for the door

// *****   Main class declaration   *****
L29x::L29x (int in1pin, int in2pin ,int in3pin, int in4pin , int ENApin, int ENBpin )
  {
  pinMode(in1pin  , OUTPUT);	   
	pinMode(in2pin  , OUTPUT);	 
	pinMode(in3pin  , OUTPUT);	 
  pinMode(in4pin  , OUTPUT);	   
  pinMode(ENApin  , OUTPUT);	   
	pinMode(ENApin  , OUTPUT);	
  
  _in1pin = in1pin ;
  _in2pin = in2pin ;
  _in3pin = in3pin ;
  _in4pin = in4pin ;
  _ENApin = ENApin ;
  _ENBpin = ENBpin ;

  digitalWrite(_in1pin, LOW);
  digitalWrite(_in2pin, LOW);
  digitalWrite(_in3pin, LOW);
  digitalWrite(_in4pin, LOW);  

  }
 void L29x::steering(int heading, int power)
{
  _heading = heading;
  _power = power;
  // user errors handling
    if (heading > 100)  { heading =  100;} 
    if (heading <-100)  { heading = -100;}
    if (power > 100)    { power   =  100;} 
    if (power <-100)    { power   = -100;}
 
  // Set Motors H-Bridge pins according to Vehicle movement direction 
    if (power >= 0 )    // set pins to go forward
       { digitalWrite(_in1pin, LOW);
         digitalWrite(_in2pin, HIGH);
         digitalWrite(_in3pin, LOW);
         digitalWrite(_in4pin, HIGH); }
    if (power >= 0 )    // set pins to go Backward
       { digitalWrite(_in1pin, HIGH);
         digitalWrite(_in2pin, LOW);
         digitalWrite(_in3pin, HIGH);
         digitalWrite(_in4pin, LOW); }

// set power to motors according the heading and power request
// based on https://sites.google.com/site/ev3devpython/learn_ev3_python/using-motors/ev3%20tank%20vs%20steer.PNG?attredirects=0
 
    if (_heading >= 0) // steering right (or straight)
    { _enA_power = 100 - 2 * _heading;                    // set right motor percentage
      _enA_power = _enA_power * abs(_power)/100;           // add the power requirement
      _enA_power = map (_enA_power , 0 , 100 , 0 , 255);  // translate to arduino output PWM
      _enB_power = 100  * abs(_power)/100 ;               // left motor is full so only add the power requirement
      _enB_power = map (_enB_power , 0 , 100 , 0 , 255);  // translate to arduino output PWM
     }
    if (_heading < 0) // steering left
    { _enA_power = 100 * abs(_power)/100 ;
      _enA_power = map (_enA_power , 0 , 100 , 0 , 255);
      _enB_power = -100 + 2 * _heading ;
      _enB_power = _enB_power * abs(_power)/100 ;
      _enB_power = map (_enB_power , 0 , 100 , 0 , 255);
     }
      analogWrite (_ENApin, _enA_power);   // set power to right motor pin
      analogWrite (_ENApin, _enB_power);   // set power to left  motor pin
 
}
  L29x::stop()
  {

  }


 
