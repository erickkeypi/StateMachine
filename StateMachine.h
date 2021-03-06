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

#ifndef _STATE_MACHINE
#define _STATE_MACHINE

#include "Arduino.h"

class StateMachine{

private:
  char estado[20];

public:
  boolean logAct;

  StateMachine();
  char *getState();
  void stateCase(char[],void(fc)(void));
  void changeState(char[]);

};
#endif
