#include "StateMachine.h"

#define LED LED_BUILTIN
#define STATE_FIRST 0
#define STATE_SECOND 1
#define STATE_THIRD 2

StateMachine machine = StateMachine();

unsigned long t = 0;
int count = 0;

void setup(){
  pinMode(LED,OUTPUT);
  machine.changeState(STATE_FIRST);
}

void loop(){
  machine.stateCase(STATE_FIRST,fs);
  machine.stateCase(STATE_SECOND,ss);
  machine.stateCase(STATE_THIRD,ts);
}

void fs(){
  if(millis() > 1000 + t){
    digitalWrite(LED,!digitalRead(LED));
    count ++;
    t = millis();
  }
  if(count >= 5){
    count =0;
    machine.changeState(STATE_SECOND);
  }
}

void ss(){
  if(millis() > 500 + t){
    digitalWrite(LED,!digitalRead(LED));
    count ++;
    t = millis();
  }
  if(count >= 10){
    count =0;
    machine.changeState(STATE_THIRD);
  }
}

void ts(){
  if(millis() > 100 + t){
    digitalWrite(LED,!digitalRead(LED));
    count ++;
    t = millis();
  }
  if(count >= 100){
    count =0;
    machine.changeState(STATE_FIRST);
  }
}
