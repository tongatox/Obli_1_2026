#ifndef LIBRO
#define LIBRO
#include <string>
#include "DtFecha.h"


using namespace std;

class Libro
{
private:
    string ci;
    string nombre;
    DtFecha fechaRegistro;
public:
    Libro(string ci, string nombre, DtFecha fechaRegistro);
    void setCi(string ci);
    string getCi();
    void setNombre(string nombre);
    string getNombre();
    ~Libro();
};







#endif