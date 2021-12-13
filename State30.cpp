#include "state30.h"

//float LengthOfTrack = 30;

//Implementation

int State30::mainFunction()
{
  showStateLEDs();

  startCar();
  recordTheData();

  Serial.begin(9600);
  Serial.print(motor.getCounts());
  Serial.print(" is ");
  Serial.print(getDistance());
  Serial.print("inch");
  Serial.print(" out of ");
  Serial.print(LengthOfTrack);
  Serial.println();
  Serial.end();
  
  return checkButtons();
}

void State30::recordTheData()
{
  float data[6] = {millis(), motor.getCounts(), motor.getVelRadSec(), accel.accX, accel.accY, accel.accZ};
  state0.recordData(data);
}

void State30::showStateLEDs()
{
  LEDs.setLEDColor(1,255,0,0);
  LEDs.setLEDColor(2,255,0,0);
  LEDs.setLEDColor(3,255,0,0);
  LEDs.setLEDColor(4,255,0,0);
  LEDs.showLEDs();
}
    
void State30::startCar()
{
      //motor.getCountsAndReset();
      motor.setPWMOutput(255);
}

void State30::stopCar()
{
      motor.setPWMOutput(0);
      motor.getCountsAndReset();
      state0.closeData();
}

float State30::getDistance()
{
  return (-motor.getCounts() / 68) * 5.9;
}

int State30::checkButtons()
{
  bool button4WasPressed = false;
  unsigned long button4CheckTime;
  bool button1WasPressed = false;
  unsigned long button1CheckTime;
  unsigned long checkInterval = 1000;

  if(getDistance()>LengthOfTrack)
  {
    stopCar();
    return 10;
  }
  
  buttons.checkStates();

  if (buttons.wasPressed(4) && !button4WasPressed)
  {
    button4WasPressed = true;
    button4CheckTime = millis() + checkInterval;
  }

  if(buttons.wasPressed(4) && button4WasPressed && button4CheckTime > millis())
  {
    button4WasPressed = false;
    stopCar();
    return 10;
  }

  if (buttons.wasPressed(1) && !button1WasPressed)
  {
    button1WasPressed = true;
    button1CheckTime = millis() + checkInterval;
  }

  if(buttons.wasPressed(1) && button1WasPressed && button1CheckTime > millis())
  {
    button1WasPressed = false;
    stopCar();
    return -10;
  }
  
  return 0;
}
