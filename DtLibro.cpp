#include "DtLibro.h"

DtLibro::DtLibro(string autor, int cantPaginas, string codigo, string titulo, int anioPublicado) : DtMaterial(codigo, titulo, anioPublicado)
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


void DtLibro::mostrarMateriales()
{
    cout << "Material: Libro" << endl;
    cout << "- Código: "<< this->getCodigo() << endl;
    cout << "- Título: "<< this->getTitulo() << endl;
    cout << "- Año de publicación: " << this->getAnioPubli() << endl;
    cout << "- Autor: " << this->getAutor() << endl;
    cout << "- Cantidad de páginas: " << this->getCantPaginas() << endl;
}
