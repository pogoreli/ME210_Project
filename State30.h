#include <ME210Nano.h>
#include <ME210NanoAccel.h>
#include <ME210NanoButtons.h>
#include <ME210NanoIR.h>
#include <ME210NanoLEDs.h>
#include <ME210NanoMotor.h>
#include <ME210NanoPots.h>
#include <ME210NanoSDFile.h>
#include <ME210NanoServos.h>
#include "state0.h"

#ifndef STATE30_H
#define STATE30_H
#include <Arduino.h>

class State30 
{
  public:
    int mainFunction();
    State0 state0;
  private:
    ME210NanoLEDs LEDs;
    ME210NanoButtons buttons;
    ME210NanoMotor motor;
    ME210NanoAccel accel;
    int checkButtons();
    void showStateLEDs();
    float LengthOfTrack = 30;
    float getDistance();
    void startCar();
    void stopCar();
    void recordTheData();

};


#endif
