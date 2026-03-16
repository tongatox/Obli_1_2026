#include "Libro.h"

Libro::Libro(string ci, string nombre)
{
    this->ci = ci;
    this->nombre = nombre;
}

void Libro::setCi(string ci)
{
    this->ci = ci;
}

string Libro::getCi()
{
    return this->ci;
}

void Libro::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Libro::getNombre()
{
    return this->nombre;
}

Libro::~Libro()
{
}