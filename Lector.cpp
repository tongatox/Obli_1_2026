#include "Lector.h"

Lector::Lector(string ci, string nombre, DtFecha fechaRegistro) : fechaRegistro(fechaRegistro)
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
int Lector::getTopePrestamo()
{
    return this->tope_prestamo;
}


DtMaterial **Lector::getMaterialesPrestados(int &cantMateriales)
{
    DtMaterial **materiales = new DtMaterial *[cantMateriales];
    for (int i = 0; i < cantMateriales; i++)
    {
        if (Libro *l = dynamic_cast<Libro *>(prestamo[i]->getMaterial()))
        {

            DtLibro *dtl = new DtLibro(l->getAutor(), l->getCantPaginas(), l->getCodigo(), l->getTitulo(), l->getAnioPubli(), l->calcularMulta(0));
            materiales[i] = dtl;
        }
        else if (Revista *r = dynamic_cast<Revista *>(prestamo[i]->getMaterial()))
        {
            DtRevista *dtr = new DtRevista(r->getNumeroEdicion(), r->getEsMensual(), r->getCodigo(), r->getTitulo(), r->getAnioPubli(), r->calcularMulta(0));
            materiales[i] = dtr;
        }
    }
    return materiales;
}