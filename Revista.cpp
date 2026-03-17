#include "Revista.h"

Revista::Revista(int numeroEdicion, bool esMensual, string codigo, string titulo, int anioPublicado) : Material(codigo, titulo, anioPublicado)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}
void Revista::setNumeroEdicion(int numeroEdicion)
{
    this->numeroEdicion = numeroEdicion;
}
int Revista::getNumeroEdicion()
{
    return this->numeroEdicion;
}
void Revista::setEsMensual(bool esMensual)
{
    this->esMensual = esMensual;
}
bool Revista::getEsMensual()
{
    return this->esMensual;
}
Revista::~Revista()
{
    
}

float Revista::calcularMulta(int diasAtraso)
{
    return diasAtraso * 2;
}