#include <iostream>
#include <string>

#include "Lector.h"

#define MAX_LECTORES 1

using namespace std;

struct Lectores
{
    Lector *l[MAX_LECTORES];
    int tope;
} colSocios;

void menu()
{
    system("clear");
    cout << "________________________" << endl;
    cout << "_________MENU___________" << endl;
    cout << "1. Agregar Lector" << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "6. Exit" << endl;
    cout << "OPCION: ";
}

void registrarLector(string ci, string nombre, DtFecha *fechaRegistro);

void menuRegistarLector()
{
    string ci, nombre;
    int dia, mes, anio;

    system("clear");
    cout << "______________________" << endl;
    cout << "___Agregar Lector_____" << endl;
    cout << "Cedula: ";
    cin >> ci;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Ingrese fecha de registro." << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;

    DtFecha *fechaRegistro = new DtFecha(dia, mes, anio);

    registrarLector(ci, nombre, fechaRegistro);
}

void registrarLector(string ci, string nombre, DtFecha *fechaRegistro)
{
    
    if (colSocios.tope >= 1)
    {
        system("clear");
        cout << "Cantidad maxima de socios alcanzada!!!" << endl;
        system("sleep 2");
    }
    else
    {

        DtFecha fecha(fechaRegistro->getDia(), fechaRegistro->getMes(), fechaRegistro->getAnio());
        Lector *lector = new Lector(ci, nombre, fecha);
        colSocios.l[colSocios.tope] = lector;
        colSocios.tope++;
        cout << "Lector agregado con exito." << endl;
        system("sleep 2");
    }
}

int main()
{

    colSocios.tope = 0;
    int opcion;
    menu();
    cin >> opcion;
    while (opcion != 6)
    {
        switch (opcion)
        {
        case 1:
            menuRegistarLector();
            break;

        case 2:
            break;
        }
        menu();
        cin >> opcion;
    }
    cout << "Chauu!!" << endl;
    system("sleep 1");
    system("clear");
    return 0;
}