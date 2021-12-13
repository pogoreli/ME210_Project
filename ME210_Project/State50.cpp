#include "state50.h"

//Implementation

unsigned long switchTime;
bool green;
bool switchTimeWasAssigned = false;

int State50::mainFunction()
{
  showStateLEDs();
  return checkButtons();
}

void State50::showStateLEDs()
{
  int checkIntervalLed = 1000;
  LEDs.clearLEDs();
  LEDs.setLEDColor(0,0,0,0);
  LEDs.setLEDColor(2,0,0,0);
  LEDs.setLEDColor(3,0,0,0);
  LEDs.setLEDColor(4,0,0,0);

  //LEDs.setLEDColor(1,0,255,0);

  if(!switchTimeWasAssigned)
  {
    switchTimeWasAssigned = true;
    switchTime = millis() + checkIntervalLed;
    green = true;
  }
  
  if(switchTime < millis())
  {
    switchTime = millis() + checkIntervalLed;
    green = !green;
  }

  LEDs.setLEDColor(1,0,0,0);

  if(green)
  {
    LEDs.setLEDColor(1,0,255,0);
  }else
  {
    LEDs.setLEDColor(1,0,0,255);
  }

  LEDs.showLEDs();
}

int State50::checkButtons()
{
  bool button1WasPressed = false;
  unsigned long button1CheckTime;
  unsigned long checkInterval = 1000;

  buttons.checkStates();


  if (buttons.wasPressed(1) && !button1WasPressed)
  {
    button1WasPressed = true;
    button1CheckTime = millis() + checkInterval;
  }

  if(buttons.wasPressed(1) && button1WasPressed && button1CheckTime > millis())
  {
    button1WasPressed = false;
    return -50;
  }
  
  return 0;
}
