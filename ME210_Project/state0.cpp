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
  LEDs.setLEDColor(4,0,0,0);

  if(initFileSuccess)
  {
    LEDs.setLEDColor(2,0,255,0);
  }else
  {
    LEDs.setLEDColor(2,255,0,0);
  }
  
  LEDs.showLEDs();
}

void State0::recordData(float arrayD[])
{
  sd.addData(arrayD, sizeof(arrayD));
}

void State0::closeData()
{
  sd.closeFile();
}
  
int State0::checkButtons()
{
  buttons.checkStates();

  if(buttons.wasPressed(3))
  {
    button3Time = millis() + 2000;
    LEDs.setLEDColor(3,255,255,0);
    LEDs.showLEDs();
  }

  if(!buttons.isDown(3))
  {
    LEDs.setLEDColor(3,0,0,0);
    LEDs.showLEDs();
  }

  if(buttons.isDown(3) && button3Time < millis())
  {
    LEDs.setLEDColor(3,255,0,0);
    LEDs.showLEDs();
    deleteTheFile = true;
  }

   if(buttons.wasReleased(3) && deleteTheFile)
   {
    String headings [] = {"Time", "Position", "Velocity", "AccX", "AccY", "AccZ"};
    deleteTheFile = false;
    sd.deleteFile();
    initFileSuccess = sd.initFile(headings, sizeof(headings), "Team_1A_Data.csv");
   }
  
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
