#ifndef LECTOR
#define LECTOR
#include <string>
#include "DtFecha.h"


using namespace std;

class Lector
{
private:
    string ci;
    string nombre;
    DtFecha fechaRegistro;
public:
    Lector(string ci, string nombre, DtFecha fechaRegistro);
    void setCi(string ci);
    string getCi();
    void setNombre(string nombre);
    string getNombre();
    ~Lector();
};







#endif