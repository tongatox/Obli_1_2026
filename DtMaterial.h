#ifndef DTMATERIAL
#define DTMATERIAL

#include <string>
#include <iostream>


using namespace std;


class DtMaterial
{
private:
    string codigo;
    string titulo;
    int anioPublicado;
    float multaBase;
public:
    DtMaterial(string codigo, string titulo, int anioPublicado);
    void setCodigo(string codigo);
    string getCodigo();
    void setTitulo(string titulo);
    string getTitulo();
    void setAnioPubli(int anioPublicado);
    int getAnioPubli();
    void setMultaBase(float multaBase);
    float getMultaBase();
    ~DtMaterial();

    virtual void mostrarMateriales() = 0; 
};












#endif