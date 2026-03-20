#include "Prestamo.h"

Prestamo::Prestamo(int diasPermitidos, DtFecha fechaPrestamo) : fechaPrestamo(fechaPrestamo)
{
    this->diasPermitidos = diasPermitidos;
}

void Prestamo::setDiasP(int diasPermitidos)
{
    this->diasPermitidos = diasPermitidos;
}
int Prestamo::getDiasP()
{
    return this->diasPermitidos;
}

Prestamo::~Prestamo()
{
}

Material *Prestamo::getMaterial()
{
    return this->material;
}


void Prestamo::agregarMaterial(Material * material)
{
    this->material = material;
}
