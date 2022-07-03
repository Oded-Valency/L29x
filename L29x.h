#ifndef L29x_h
#define L29x_h
#include "Arduino.h"

class L29x {
public:
  L29x (int in1pin, int in2pin ,int in3pin, int in4pin , int ENApin, int ENBpin);
  void steering (int heading, int power);
  void stop ();
private:
  int _in1pin;
  int _in2pin;
  int _in3pin;
  int _in4pin;
  int _ENApin;
  int _ENBpin;

  bool _in1;
  bool _in2;
  bool _in3;
  bool _in4;
  int _enA_power;
  int _enB_power;

  int _heading;
  int _power;
};
#endif 
