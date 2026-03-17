#include "DtMaterial.h"

DtMaterial::DtMaterial(string codigo, string titulo, int anioPublicado, float multaBase)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicado = anioPublicado;
    this->multaBase = multaBase;
}

void DtMaterial::setCodigo(string codigo)
{
    this->codigo = codigo;
}

string DtMaterial::getCodigo()
{
    return this->codigo;
}

void DtMaterial::setTitulo(string titulo)
{
    this->titulo = titulo;
}

string DtMaterial::getTitulo()
{
    return this->titulo;
}

void DtMaterial::setAnioPubli(int anioPublicado)
{
    this->anioPublicado = anioPublicado;
}

int DtMaterial::getAnioPubli()
{
    return this->anioPublicado;
}

void DtMaterial::setMultaBase(float multaBase)
{
    this->multaBase = multaBase;
}

float DtMaterial::getMultaBase()
{
    return this->multaBase;
}

DtMaterial::~DtMaterial()
{
}