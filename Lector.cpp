#include "Lector.h"

Lector::Lector(string ci, string nombre, DtFecha fechaRegistro): fechaRegistro(fechaRegistro)
{
    this->ci = ci;
    this->nombre = nombre;
}

void Lector::setCi(string ci)
{
    this->ci = ci;
}

string Lector::getCi()
{
    return this->ci;
}

void Lector::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Lector::getNombre()
{
    return this->nombre;
}

Lector::~Lector()
{
}