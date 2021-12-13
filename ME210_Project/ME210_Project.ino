#include "state0.h"
#include "state10.h"
#include "state20.h"
#include "state30.h"
#include "state40.h"
#include "state50.h"



State0 state0;
State10 state10;
State20 state20;
State30 state30;
State40 state40;
State50 state50;


int currentState = 0;

void setup() 
{
  state30.state0 = state0;
}

void loop() 
{

  switch (currentState) 
  {
  case 0:
    currentState += state0.mainFunction();
    break;
  case 10:
    currentState += state10.mainFunction();
    break;
  case 20:
    currentState += state20.mainFunction();
    break;
    case 30:
    currentState += state30.mainFunction();
    break;
    case 40:
    currentState += state40.mainFunction();
    break;
    case 50:
    currentState += state50.mainFunction();
    break; 
  }
}
