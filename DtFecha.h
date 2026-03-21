#ifndef DTFECHA
#define DTFECHA

class DtFecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    DtFecha(int dia, int mes, int anio);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAnio();
    void setAnio(int anio);
    ~DtFecha();
    bool FmayorqueF(DtFecha *fecha);
};

#endif
