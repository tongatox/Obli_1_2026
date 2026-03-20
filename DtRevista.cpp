#include "DtRevista.h"

DtRevista::DtRevista(int numeroEdicion, bool esMensual, string codigo, string titulo, int anioPublicado) : DtMaterial(codigo, titulo, anioPublicado)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}
void DtRevista::setNumeroEdicion(int numeroEdicion)
{
    this->numeroEdicion = numeroEdicion;
}
int DtRevista::getNumeroEdicion()
{
    return this->numeroEdicion;
}
void DtRevista::setEsMensual(bool esMensual)
{
    this->esMensual = esMensual;
}
bool DtRevista::getEsMensual()
{
    return this->esMensual;
}
DtRevista::~DtRevista()
{
}