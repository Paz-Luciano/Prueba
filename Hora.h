#ifndef HORA_H
#define HORA_H
#include <string>

class Hora
{
    public:
        Hora();
        Hora(int segundos, int minutos, int horas);
        void setHoras (int horas);
        void setMinutos (int minutos);
        void setSegundos (int segundos);
        int getHoras ();
        int getMinutos ();
        int getSegundos ();
        std::string toString ();

    private:

        int _segundos, _minutos, _horas;
};

#endif // HORA_H
