#ifndef PRESTAMO
#define PRESTAMO

#include "DtFecha.h"

class Prestamo
{
private:
    DtFecha fechaPrestamo;
    int diasPermitidos;

public:
    Prestamo(int diasPermitidos, DtFecha fechaPrestamo);
    void setDiasP(int diasPermitidos);
    int getDiasP();
    ~Prestamo();
};


#endif