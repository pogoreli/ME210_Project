#include <ME210Nano.h>
#include <ME210NanoAccel.h>
#include <ME210NanoButtons.h>
#include <ME210NanoIR.h>
#include <ME210NanoLEDs.h>
#include <ME210NanoMotor.h>
#include <ME210NanoPots.h>
#include <ME210NanoSDFile.h>
#include <ME210NanoServos.h>

#ifndef STATE50_H
#define STATE50_H
#include <Arduino.h>

class State50 
{
  public:
    int mainFunction();
  private:
    ME210NanoLEDs LEDs;
    ME210NanoButtons buttons;
    int checkButtons();
    void showStateLEDs();
    unsigned long switchTime;
    bool green;
    unsigned long checkIntervalLed;
    bool switchTimeWasAssigned;

};


#endif
