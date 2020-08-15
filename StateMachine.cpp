/*
Copyright 2019 Erick Rafael Garcia Martinez

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "StateMachine.h"

StateMachine::StateMachine(){
  for (int i=0;i<20;i++){
    estado[i]=0;
  }
  strcpy(estado,"default");
  logAct = false;
}

char *StateMachine::getState(){
  return estado;
}

void StateMachine::stateCase(char nombre[],void(fc)(void)){
  if (strcmp(estado,nombre) == 0){
    fc();
  }
}

void StateMachine::changeState(char _est[]){
  strcpy(estado,_est);
  if(logAct){
    Serial.print(F("Changing state to: "));
    Serial.println(estado);
  }
}
