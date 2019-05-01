#include "StateMachine.h"


//////////////////////////////////////

StateMachine maquina = StateMachine();
String password = "1234";

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  maquina.changeState("desbloqueado");
  Serial.println("Puerta desbloqueada");
}

void loop() {
  maquina.caso("desbloqueado",desbloqueadoF);
  maquina.caso("bloqueado",bloqueadoF);
  maquina.caso("contrasena",cambiandoContrasenaF);
  maquina.caso("nuevaContrasena",nuevaContrasenaF);
}


void desbloqueadoF(){
  while(Serial.available()){
    String mensaje = Serial.readStringUntil('\n');
    if(mensaje == "block"){
      maquina.changeState("bloqueado");
      Serial.println("Puerta bloqueada\nIntroduzca la contrasena para desbloquear");
    }
    if(mensaje == "setpwd"){
      maquina.changeState("contrasena");
      Serial.println("Cambiando contrasena\nIntroduzca la contrasena anterior");
    }
  }
}

void bloqueadoF(){
    while(Serial.available()){
      String mensaje = Serial.readStringUntil('\n');
      if( mensaje == password){
        maquina.changeState("desbloqueado");
        Serial.println("Puerta desbloqueada");
      }
      else{
        Serial.println("Contrasena incorrecta, intente otra vez");
      }
    }
}

void cambiandoContrasenaF(){
     while(Serial.available()){
      String mensaje = Serial.readStringUntil('\n');
      if( mensaje == password){
        Serial.println("Contrasena correcta");
        Serial.println("Introduzca la nueva contrasena");
        maquina.changeState("nuevaContrasena");
      }
      else{
        Serial.println("Contrasena incorrecta, intente otra vez");
      }
    }
}

void nuevaContrasenaF(){
     while(Serial.available()){
      password = Serial.readStringUntil('\n');
      Serial.println("Contrasena cambiada");
      maquina.changeState("desbloqueado");
      Serial.println("Puerta desbloqueada");
    }
}
