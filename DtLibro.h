#ifndef DTLIBRO
#define DTLIBRO

#include "DtMaterial.h"
#include <string>

using namespace std;


class DtLibro : public DtMaterial
{
private:
    string autor;
    int cantPaginas;
public:
    DtLibro(string autor, int cantPaginas,string codigo, string titulo, int anioPublicado);
    void setAutor(string autor);
    string getAutor();
    void setCantPaginas(int cantPaginas);
    int getCantPaginas();
    ~DtLibro();
    
    void mostrarMateriales();
};


#endif