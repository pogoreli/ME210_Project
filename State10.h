#include <ME210Nano.h>
#include <ME210NanoAccel.h>
#include <ME210NanoButtons.h>
#include <ME210NanoIR.h>
#include <ME210NanoLEDs.h>
#include <ME210NanoMotor.h>
#include <ME210NanoPots.h>
#include <ME210NanoSDFile.h>
#include <ME210NanoServos.h>

#ifndef STATE10_H
#define STATE10_H
#include <Arduino.h>

class State10 
{
  public:
    int mainFunction();
  private:
    ME210NanoLEDs LEDs;
    ME210NanoButtons buttons;
    ME210NanoServos servos;
    int checkButtons();
    void showStateLEDs();
    bool button3WasPressed = false;
    unsigned long button3CheckTime;
    
    bool button4WasPressed = false;
    unsigned long button4CheckTime;
    
    bool button1WasPressed = false;
    unsigned long button1CheckTime;
    
    unsigned long checkInterval = 1000;

};


#endif
