#include "state20.h"

//Implementation

int State20::mainFunction()
{
  showStateLEDs();
  return checkButtons();
}

void State20::showStateLEDs()
{
  LEDs.setLEDColor(1,0,255,0);
  LEDs.setLEDColor(2,0,255,0);
  LEDs.setLEDColor(3,0,255,0);
  LEDs.setLEDColor(4,0,0,0);
  LEDs.showLEDs();
}

int State20::checkButtons()
{
  buttons.checkStates();

  if(ir.queryStart() == 0)
  {
    LEDs.setLEDColor(0,255,0,0);
  }

  if(ir.queryStart() == 1)
  {
    LEDs.setLEDColor(0,255,255,0);
  }

  if(ir.queryStart() == 2)
  {
    LEDs.setLEDColor(0,0,255,0);
    return 10;
  }

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
