#ifndef LECTOR
#define LECTOR
#include <string>
#include "DtFecha.h"
#include "Prestamo.h"
#include "DtMaterial.h"
#include "DtLibro.h"
#include "DtRevista.h"
#include "Libro.h"
#include "Revista.h"
#include "Material.h"

#define MAX_PRESTAMO 10

using namespace std;

class Lector
{
private:
    string ci;
    string nombre;
    DtFecha fechaRegistro;
    Prestamo *prestamo[MAX_PRESTAMO];
    int tope_prestamo;

public:
    Lector(string ci, string nombre, DtFecha fechaRegistro);
    void setCi(string ci);
    string getCi();
    void setNombre(string nombre);
    string getNombre();
    ~Lector();

    int getTopePrestamo();
    Prestamo ** getPrestamo();
    void agregarPrestamo(Prestamo *prestamo);

    DtMaterial **getMaterialesPrestados(int &cantMateriales);
};

#endif