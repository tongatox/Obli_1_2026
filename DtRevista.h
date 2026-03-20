#ifndef DTREVISTA
#define DTREVISTA

#include "DtMaterial.h"

class DtRevista : public DtMaterial
{
private:
    int numeroEdicion;
    bool esMensual;
public:
    DtRevista(int numeroEdicion, bool esMensual,string codigo, string titulo, int anioPublicado);
    void setNumeroEdicion(int numeroEdicion);
    int getNumeroEdicion();
    void setEsMensual(bool esMensual);
    bool getEsMensual();
    ~DtRevista();
};



#endif