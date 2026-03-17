#include "DtLibro.h"

DtLibro::DtLibro(string autor, int cantPaginas, string codigo, string titulo, int anioPublicado, float multaBase) : DtMaterial(codigo, titulo, anioPublicado, multaBase)
{
    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

void DtLibro::setAutor(string autor)
{
    this->autor = autor;
}

string DtLibro::getAutor()
{
    return this->autor;
}

void DtLibro::setCantPaginas(int cantPaginas)
{
    this->cantPaginas = cantPaginas;
}

int DtLibro::getCantPaginas()
{
    return this->cantPaginas;
}

DtLibro::~DtLibro()
{
}
