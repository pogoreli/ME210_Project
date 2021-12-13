#include <ME210Nano.h>
#include <ME210NanoAccel.h>
#include <ME210NanoButtons.h>
#include <ME210NanoIR.h>
#include <ME210NanoLEDs.h>
#include <ME210NanoMotor.h>
#include <ME210NanoPots.h>
#include <ME210NanoSDFile.h>
#include <ME210NanoServos.h>

#ifndef STATE0_H
#define STATE0_H
#include <Arduino.h>

class State0 
{
  public:
    int mainFunction();
    void recordData(float arrayD[]);
    void closeData();
    

   private:
    ME210NanoLEDs LEDs;
    ME210NanoButtons buttons;
    ME210NanoSDFile sd;
    int checkButtons();
    void showStateLEDs();
    unsigned long button3Time;
    unsigned long button4CheckTime;
    bool button4WasPressed = false;
    bool deleteTheFile = false;
    bool initFileSuccess = false;
    
    

};


#endif
