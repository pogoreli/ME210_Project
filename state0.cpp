#include "state0.h"

//Implementation

int State0::mainFunction()
{
  showStateLEDs();
  return checkButtons();
}

void State0::showStateLEDs()
{
  LEDs.setLEDColor(0,0,0,0);
  LEDs.setLEDColor(1,255,255,0);
  LEDs.setLEDColor(3,0,0,0);
  LEDs.setLEDColor(4,0,0,0);
  LEDs.showLEDs();
}
  
int State0::checkButtons()
{
  bool button4WasPressed = false;
  unsigned long button4CheckTime;

  buttons.checkStates();
  
  if (buttons.wasPressed(4) && !button4WasPressed)
  {
    button4WasPressed = true;
    button4CheckTime = millis() + 1000;
  }

  if(buttons.wasPressed(4) && button4WasPressed && button4CheckTime > millis())
  {
    button4WasPressed = false;
    return 10;
  }

  
  return 0;
}
