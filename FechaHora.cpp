#include<iostream>
using namespace std;
#include "FechaHora.h"
#include "Fecha.h"
#include "Hora.h"

FechaHora::FechaHora(){


}
FechaHora::FechaHora (Fecha fecha, Hora hora){

    _fecha = fecha;
    _hora = hora;
}
FechaHora::FechaHora (int dia, int mes, int anio, int segundos, int minutos, int horas){

       setFecha (dia, mes, anio);
       setHora (segundos, minutos, horas);
}
Fecha FechaHora::getFecha (){

      return _fecha;
}
Hora FechaHora::getHora (){

      return _hora;
}

void FechaHora::setFecha (Fecha fecha){
    _fecha = fecha;

}
void FechaHora::setFecha (int dia, int mes, int anio){
     //Una manera de hacerlo
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);

}
void FechaHora::setHora (Hora hora){
    _hora = hora;
}

void FechaHora::setHora (int segundos, int minutos, int horas){
    //Otra manera de hacerlo
    _hora = Hora (segundos, minutos, horas);
}
std::string FechaHora::toString (){

    std::string valorADevolver;

    valorADevolver = _fecha.toString() +" "+_hora.toString(); ///Utilizo el to_string de ambas clases, ya que ambos lo resolvian individualmente

    return valorADevolver;
}
