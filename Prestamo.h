#ifndef PRESTAMO
#define PRESTAMO

#include "DtFecha.h"
#include "Material.h"
#include "DtMaterial.h"



class Prestamo
{
private:
    DtFecha fechaPrestamo;
    int diasPermitidos;
    Material *material;

public:
    Prestamo(int diasPermitidos, DtFecha fechaPrestamo);
    void setDiasP(int diasPermitidos);
    int getDiasP();
    ~Prestamo();

    Material *getMaterial();
    void agregarMaterial(Material * material);
};


#endif