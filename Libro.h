#ifndef LIBRO
#define LIBRO

#include "Material.h"
#include <string>

using namespace std;


class Libro : public Material
{
private:
    string autor;
    int cantPaginas;
public:
    Libro(string autor, int cantPaginas,string codigo, string titulo, int anioPublicado);
    void setAutor(string autor);
    string getAutor();
    void setCantPaginas(int cantPaginas);
    int getCantPaginas();
    ~Libro();

    float calcularMulta(int diasAtraso);
};







#endif