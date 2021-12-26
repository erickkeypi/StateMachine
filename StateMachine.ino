
#include "StateMachine.h"


#define STATE_DEFAULT 0
#define STATE_RUN 1
#define STATE_STOP 2
#define STATE_ERROR 3



StateMachine machine = StateMachine();

void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("BEGINS");

  machine.changeState(STATE_DEFAULT);
}

void loop(){

  machine.stateCase(STATE_DEFAULT,defaultF);
  machine.stateCase(STATE_ERROR,errorF);
  machine.stateCase(STATE_RUN,runF);
  machine.stateCase(STATE_STOP,stopF);
}

void defaultF(){
  static unsigned int t = millis()/1000;

  t = millis()/1000;
  machine.changeCondition(t%10 == 1, STATE_STOP);
}

void stopF(){
  Serial.println("STOP");
  machine.changeState(STATE_RUN);
}

void runF(){
  Serial.println("RUN");
  delay(1500);
  machine.changeState(STATE_DEFAULT);
}

void errorF(){
  Serial.println("ERROR");
  machine.changeState(STATE_DEFAULT);
}
