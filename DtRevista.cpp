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

void DtRevista::mostrarMateriales()
{
    cout << "Material: Revista" << endl;
    cout << "- Código: " << this->getCodigo() << endl;
    cout << "- Título: " << this->getTitulo() << endl;
    cout << "- Año de publicación: " << this->getAnioPubli() << endl;
    cout << "- Número de edición: " << this->getNumeroEdicion() << endl;
    if (this->esMensual)
    {
        cout << "- Es mensual: Sí" << endl;
    }
    else
    {
        cout << "- Es mensual: no" << endl;
    }
}