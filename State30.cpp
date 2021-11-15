#include "state30.h"

//Implementation

int State30::mainFunction()
{
  showStateLEDs();
  return checkButtons();
}

void State30::showStateLEDs()
{
  LEDs.setLEDColor(1,255,0,0);
  LEDs.setLEDColor(2,255,0,0);
  LEDs.setLEDColor(3,255,0,0);
  LEDs.setLEDColor(4,255,0,0);
  LEDs.showLEDs();
}

int State30::checkButtons()
{
  bool button4WasPressed = false;
  unsigned long button4CheckTime;
  bool button1WasPressed = false;
  unsigned long button1CheckTime;
  unsigned long checkInterval = 1000;

  buttons.checkStates();

  if (buttons.wasPressed(4) && !button4WasPressed)
  {
    button4WasPressed = true;
    button4CheckTime = millis() + checkInterval;
  }

  if(buttons.wasPressed(4) && button4WasPressed && button4CheckTime > millis())
  {
    button4WasPressed = false;
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
    return -10;
  }
  
  return 0;
}
