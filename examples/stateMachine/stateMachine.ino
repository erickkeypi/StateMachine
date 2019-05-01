#include "StateMachine.h"

#define LED 13

StateMachine machine = StateMachine();

unsigned long t = 0;
int count = 0;

void setup(){
  pinMode(LED,OUTPUT);
  machine.changeState("firstState");
}

void loop(){
  machine.stateCase("firstState",fs);
  machine.stateCase("secondState",ss);
  machine.stateCase("thirdState",ts);
}

void fs(){
  if(millis() > 1000 + t){
    digitalWrite(LED,!digitalRead(LED));
    count ++;
    t = millis();
  }
  if(count >= 5){
    count =0;
    machine.changeState("secondState");
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
    machine.changeState("thirdState");
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
    machine.changeState("firstState");
  }
}
