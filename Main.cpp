#include <iostream>
#include <string>

#include "Lector.h"

#define MAX_LECTORES 100
using namespace std;

struct Lectores
{
    Lector *l[MAX_LECTORES];
    int tope;
} colLectores;

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
    int i = 0;

    if (colLectores.tope >= MAX_LECTORES)
    {
        system("clear");
        cout << "Cantidad maxima de socios alcanzada!!!" << endl;
        system("sleep 2");
    }
    else
    {
        while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
            i++;

        if (colLectores.tope != i)
        {
            system("clear");
            cout << "Ya existe un Lector con esa cedula." << endl;
            system("sleep 2");
        }
        else
        {

            DtFecha fecha(fechaRegistro->getDia(), fechaRegistro->getMes(), fechaRegistro->getAnio());
            Lector *lector = new Lector(ci, nombre, fecha);
            colLectores.l[colLectores.tope] = lector;
            colLectores.tope++;
            cout << "Lector agregado con exito." << endl;
            system("sleep 2");
        }
    }
}

//void agregarPrestamo(string ci, string codigoMaterial, DtFecha* fechaPrestamo, int diasPermitidos);

void menuAgregarPrestamo()
{
    system("clear");
    cout << "______________________" << endl;
    cout << "___Agregar Prestamo_____" << endl;
}

int main()
{

    colLectores.tope = 0;
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
            menuAgregarPrestamo();
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