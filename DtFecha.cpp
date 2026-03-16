#include "DtFecha.h"
#include <iostream>

using namespace std;

DtFecha::DtFecha(int dia, int mes, int anio)
{
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900)
        throw invalid_argument("Fecha no valida\n");
    else
    {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
}

int DtFecha::getDia()
{
    return this->dia;
}

void DtFecha::setDia(int dia)
{
    if (dia < 1 || dia > 31)
        throw invalid_argument("Elija un dia del 1 al 31\n");
    else
        this->dia = dia;
}

int DtFecha::getMes()
{
    return this->mes;
}

void DtFecha::setMes(int mes)
{
    if (mes < 1 || mes > 31)
        throw invalid_argument("Elija un mes del 1 al 12\n");
    else
        this->mes = mes;
}

int DtFecha::getAnio()
{
    return this->anio;
}

void DtFecha::setAnio(int anio)
{
    if (anio < 1900)
        throw invalid_argument("Elija un año superior a 1900\n");
    else
        this->anio = anio;
}

/*bool DtFecha::FmayorqueF(DtFecha *fecha) // Devuelve true solo si fecha1 es mas antigua que fecha2, si no, devuelve false.
{
    if (fecha->getAnio() < this->getAnio())
    {
        return true;
    }
    else if (fecha->getAnio() == this->getAnio())
    {
        if (fecha->getMes() < this->getMes())
        {
            return true;
        }
        else if (fecha->getMes() == this->getMes())
        {
            if (fecha->getDia() < this->getDia())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}*/

DtFecha::~DtFecha() {}
