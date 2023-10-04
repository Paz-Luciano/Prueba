#ifndef FECHAHORA_H
#define FECHAHORA_H
#include <string>
#include "Fecha.h"
#include "Hora.h"

class FechaHora{

    public:

        FechaHora();//No es muy necesario este constructor porque los objetos _fecha y _horario, ya tienen su constructor vacio ya seteados
        FechaHora (Fecha fecha, Hora hora);
        FechaHora (int dia, int mes, int anio, int segundos, int minutos, int horas);
        Fecha getFecha ();
        Hora getHora ();
        void setFecha (Fecha fecha);
        void setFecha (int dia, int mese, int anio);
        void setHora (Hora hora);
        void setHora (int segundos, int minutos, int horas);
        std::string toString ();


    private:

        Fecha _fecha;
        Hora _hora;

};

#endif // FECHAHORA_H
