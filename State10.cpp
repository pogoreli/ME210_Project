#include "state10.h"

//Implementation

int State10::mainFunction()
{
  showStateLEDs();
  return checkButtons();
}

void State10::showStateLEDs()
{
  LEDs.setLEDColor(0,0,0,0);
  LEDs.setLEDColor(1,255,150,0);
  LEDs.setLEDColor(2,0,255,0);
  //LEDs.setLEDColor(3,255,255,0);
  LEDs.setLEDColor(4,0,0,0);
  LEDs.showLEDs();
}

int State10::checkButtons()
{
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

  if(buttons.wasReleased(3) && button3WasPressed && button3CheckTime > millis())
  {
    button3WasPressed = false;
    servos.setServoLocRaw(0, 220);
    
    LEDs.setLEDColor(3,255,255,0);
    LEDs.showLEDs();
  }

  if (buttons.wasPressed(3) && !button3WasPressed)
  {
    button3WasPressed = true;
    button3CheckTime = millis() + checkInterval;
    LEDs.setLEDColor(3,255,0,0);
    LEDs.showLEDs();
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
