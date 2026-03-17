#include "Libro.h"

Libro::Libro(string autor, int cantPaginas, string codigo, string titulo, int anioPublicado) : Material(codigo, titulo, anioPublicado)
{
    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

void Libro::setAutor(string autor)
{
    this->autor = autor;
}

string Libro::getAutor()
{
    return this->autor;
}

void Libro::setCantPaginas(int cantPaginas)
{
    this->cantPaginas = cantPaginas;
}

int Libro::getCantPaginas()
{
    return this->cantPaginas;
}

Libro::~Libro()
{
}

float Libro::calcularMulta(int diasAtraso)
{
    return diasAtraso * 5;
}
