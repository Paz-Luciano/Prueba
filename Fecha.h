#ifndef FECHA_H
#define FECHA_H
#include <string>

class Fecha{

        private:
        int _dia, _mes, _anio;
        bool Validar;
        bool ValidarFecha (int dia, int mes, int anio);
        void AgregarDia(int dia, int mes, int anio);
        void RestarDia(int dia, int mes, int anio);

        public:
        Fecha ();
        Fecha (int dia, int mes, int anio);
        int setDia (int dia);
        int setMes (int mes);
        int setAnio(int anio);
        int getDia (int dia);
        int getMes (int mes);
        int getAnio(int anio);
        void AgregarDias (int cantidad);
        std::string toString();
};

#endif // FECHA_H
