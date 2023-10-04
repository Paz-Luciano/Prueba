#include<iostream>
using namespace std;
#include "Hora.h"
#include <ctime>

Hora::Hora(){
      //Explicado en LAB2 2023 2C Semana 03
      //Me devuelve la hora del sistema
      time_t t = time(NULL);
      struct tm *f = localtime (&t);
      _segundos = f-> tm_sec;
      _minutos = f-> tm_min;
      _horas = f-> tm_hour;
}
Hora::Hora(int segundos, int minutos, int horas){

     setSegundos(segundos);
     setMinutos(minutos);
     setHoras(horas);

}
void Hora::setHoras (int horas){

    _horas=horas;
}
void Hora::setMinutos (int minutos){

    _minutos=minutos;
}
void Hora::setSegundos (int segundos){

    _segundos=segundos;
}
int Hora::getHoras (){

    return _horas;
}
int Hora::getMinutos (){

    return _minutos;
}
int Hora::getSegundos (){

    return _segundos;
}

std::string Hora::toString (){

     std::string horaADevolver;

     horaADevolver = std::to_string(_horas)+ ":" + std::to_string(_minutos)+ ":" + std::to_string(_segundos);

     return horaADevolver;

}
