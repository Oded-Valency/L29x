# L29x
this library has been written to eazy control on a 2 DC motor vehicle govern by a H-Bridge motor controller. power   : int (-100..+100), where  -100 stand for Full Power Back  , 0 stand for Stop , +100 stand for Full Power Forward heading : int (-100..+100), where     -100 stand for "Tank Left"  (left motor Back, right motor Forward)    -50 stand for "Pivot Left" (left motor stop, right motor Forward)      0 stand for "Stop"       (left motor stop, right motor stop)      -50 stand for "Pivot Right"(left motor Forward, right motor stop )   -100 stand for "Tank Right" (left motor Forward, right motor Back )   https://sites.google.com/site/ev3devpython/learn_ev3_python/using-motors   tested on L298D module via Arduino UNO R3 by: Valency Oded