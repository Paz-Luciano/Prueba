#include "Fecha.h"
#include <string>
#include <ctime>

Fecha::Fecha(){

    //Explicado en LAB2 2023 2C Semana 03 1:05:00 (aprox)
    //Me devuelve la hora del sistema
    time_t t = time(NULL);
    struct tm *f = localtime (&t);
    _dia = f-> tm_mday;
    _mes = f-> tm_mon+1;
    _anio = f-> tm_year+1900;

}

Fecha::Fecha (int dia, int mes, int anio){

   Validar = ValidarFecha (dia, mes, anio);

   if (Validar==true){
       _dia = dia;
       _mes = mes;
       _anio= anio;

   }
   else{
       _dia = 1;
       _mes = 1;
       _anio= 2023;

   }
}

bool Fecha::ValidarFecha (int dia, int mes, int anio){

    if (anio>=1000){//VALIDA QUE EL AÑO SEA A PARTIR DE 1000, EN ADELANTE

        if (mes==2){//SI EL MES ES FEBRERO

          if (anio%4==0&&anio%100!=0||anio%400==0){//PREGUNTA SI EL AÑO ES BISIESTO.

             if (dia>=1 && dia <=29){//VALIDA QUE EL DIA INGRESADO PARA EL MES DE FEBRERO SEA ENTRE 1 Y 29 (porque es AÑO BISIESTO).
                 return true;
             }
             else{
                return false;
             }
          }
          else{//SI NO ES BISIESTO, LOS DIAS de febrero TIENEN QUE SER ENTRE 1 Y 28.
             if (dia>=1 && dia <=28){
                 return true;
             }
             else{
                return false;
             }
          }
        }
        else{//SI EL MES NO ES FEBRERO

           if (mes>=1 && mes<=12 && dia>=1 && dia<=31){ //NUMERO DE MES Y DIAS VALIDOS

            if (mes==1||mes==3||mes==5||mes==8||mes==10||mes==12){//MESES QUE TIENEN 31 DIAS

              if (dia>=1&&dia<=31){//DIAS VALIDOS PARA MESES CON 31 DIAS
                 return true;
              }
              else{
                 return false;
              }
            }
           else{
             if (mes==4||mes==6||mes==7||mes==9||mes==11){//MESES QUE TIENEN 30 DIAS

               if (dia>=1 && dia<=30){//DIAS VALIDOS
                  return true;
               }
               else{
                  return false;
               }
             }
           }
         }
         else{//NUMEROS DE MES O DIA INVALIDOS
             return false;
         }
       }
    }
    else{//EL AÑO ES MENOR A 1000
        return false;
    }
}

int Fecha::setDia(int dia){
    _dia = dia;
}
int Fecha::setMes(int mes){
    _mes = mes;
}

int Fecha::setAnio(int anio){
    _anio = anio;
}

int Fecha::getDia(int dia){
    return _dia;
}
int Fecha::getMes(int mes){
    return _mes;
}

int Fecha::getAnio(int anio){
    return _anio;
}


void Fecha::AgregarDia(int dia, int mes, int anio){

    if (mes==1||mes==3||mes==5||mes==8||mes==10||mes==12){//MESES QUE TIENEN 31 DIAS

        if (dia==31&&mes!=12){//CAMBIO DE DIA Y DE MES
            _mes = mes+1;
            _dia = 1;
            _anio= anio;
        }
        else{

            if(dia==31&&mes==12){//CAMBIO DE DIA DE MES Y DE AÑO
                _dia = 1;
                _mes = 1;
                _anio= anio+1;
            }
            else{ //CAMBIO DE DIA
            _dia = dia+1;
            _mes = mes;
            _anio= anio;
            }
        }
    }
    else{

        if (mes==4||mes==6||mes==7||mes==9||mes==11){//MESES CON 30 DIAS

            if (dia==30){//CAMBIO DE DIA Y DE MES
               _mes = mes+1;
               _dia = 1;
               _anio= anio;
            }
            else{
               _dia = dia+1;
               _mes = mes;
               _anio= anio;
            }
        }
        else{ //SI EL MES ES FEBRERO

            if (anio%4==0&&anio%100!=0||anio%400==0){//PREGUNTA SI EL AÑO ES BISIESTO. //FEBRERO CON 29 DIAS

                if(dia==29){//CAMBIO DE DIA Y DE MES
                    _dia = 1;
                    _mes = mes+1;
                    _anio= anio;
                }
                else{//CAMBIO DE DIA
                    _dia = dia+1;
                    _mes = mes;
                    _anio= anio;
                }
            }
            else{ //SI EL ANIO NO ES BISIESTO
                if (dia==28){//CAMBIO DE DIA Y DE MES
                    _dia = 1;
                    _mes = mes+1;
                    _anio= anio;
                }
                else{//CAMBIO DE DIA
                    _dia = dia+1;
                    _mes = mes;
                    _anio= anio;
                }
            }
        }
     }
}

void Fecha::RestarDia(int dia, int mes, int anio){

    if (mes==1||mes==3||mes==5||mes==8||mes==10||mes==12){//MESES QUE TIENEN 31 DIAS

        if (dia==1&&mes==1){//CAMBIO DE DIA, MES Y ANIO
            _mes = 12;
            _dia = 31;
            _anio= anio-1;
        }
        else{

            if(dia==1&&mes==12){//CAMBIO DE DIA DE MES Y DE AÑO
                _dia = 1;
                _mes = 1;
                _anio= anio-1;
            }
            else{ //CAMBIO DE DIA
            _dia = dia-1;
            _mes = mes;
            _anio= anio;
            }
        }
    }
    else{

        if (mes==4||mes==6||mes==7||mes==9||mes==11){//MESES CON 30 DIAS

            if (dia==30){//CAMBIO DE DIA Y DE MES
               _mes = mes-1;
               _dia = 1;
               _anio= anio;
            }
            else{
               _dia = dia+1;
               _mes = mes;
               _anio= anio;
            }
        }
        else{ //SI EL MES ES FEBRERO

            if (anio%4==0&&anio%100!=0||anio%400==0){//PREGUNTA SI EL AÑO ES BISIESTO. //FEBRERO CON 29 DIAS

                if(dia==29){//CAMBIO DE DIA Y DE MES
                    _dia = 1;
                    _mes = mes-1;
                    _anio= anio;
                }
                else{//CAMBIO DE DIA
                    _dia = dia+1;
                    _mes = mes;
                    _anio= anio;
                }
            }
            else{ //SI EL ANIO NO ES BISIESTO
                if (dia==28){//CAMBIO DE DIA Y DE MES
                    _dia = 1;
                    _mes = mes-1;
                    _anio= anio;
                }
                else{//CAMBIO DE DIA
                    _dia = dia-1;
                    _mes = mes;
                    _anio= anio;
                }
            }
        }
     }
}

void Fecha::AgregarDias (int cantidad){

    int x;

    if (cantidad>0){

       for (x=0; x<cantidad; x++){

        AgregarDia(_dia, _mes, _anio);

       }
    }
    else {
        if (cantidad<0){

         for (x=0; x<cantidad; x++){

         RestarDia(_dia, _mes, _anio);

         }
        }
    }

}

std::string Fecha::toString (){

    std::string valorADevolver;

    Validar = ValidarFecha (_dia, _mes, _anio); //SI MODIFICO EN MAIN LA FECHA, SOLO MUESTRO UNA FECHA VALIDA

    if (Validar){

        if (_dia<=9&&_mes<=9){

        valorADevolver ="0"+std::to_string(_dia)+"/0"+std::to_string(_mes)+"/"+std::to_string(_anio);
        return valorADevolver;
        }

        if(_dia<=9&&_mes>9){
        valorADevolver ="0"+std::to_string(_dia)+"/"+std::to_string(_mes)+"/"+std::to_string(_anio);
        return valorADevolver;
        }

        if(_dia>9&&_mes<=9){
        valorADevolver =   std::to_string(_dia)+"/0"+std::to_string(_mes)+"/"+std::to_string(_anio);
        return valorADevolver;
        }

        if (_dia>9&&_mes>9){
        valorADevolver =    std::to_string(_dia)+"/"+std::to_string(_mes)+"/"+std::to_string(_anio);
        return valorADevolver;
        }
    }
    else{
         valorADevolver = "0"+std::to_string (1)+"/0"+std::to_string (1)+"/"+std::to_string (2023);
         return valorADevolver;
    }
}









