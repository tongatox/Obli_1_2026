#ifndef REVISTA
#define REVISTA

#include "Material.h"

class Revista : public Material
{
private:
    int numeroEdicion;
    bool esMensual;
public:
    Revista(int numeroEdicion, bool esMensual,string codigo, string titulo, int anioPublicado);
    void setNumeroEdicion(int numeroEdicion);
    int getNumeroEdicion();
    void setEsMensual(bool esMensual);
    bool getEsMensual();
    ~Revista();

    float calcularMulta(int diasAtraso);
};



#endif