#include <iostream>
#include <string>

#include "Lector.h"

#define MAX_LECTORES 100
#define MAX_MATERIALES 50

using namespace std;

struct Lectores
{
    Lector *l[MAX_LECTORES];
    int tope;
} colLectores;

struct Materiales
{
    Material *m[MAX_MATERIALES];
    int tope;
} colMateriales;

void menu()
{
    system("clear");
    cout << "________________________" << endl;
    cout << "_________MENU___________" << endl;
    cout << "1. Agregar Lector" << endl;
    cout << "2. Agregar Prestamo" << endl;
    cout << "3. Agregar Material" << endl;
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

    try
    {
        registrarLector(ci, nombre, fechaRegistro);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << '\n';
        system("sleep 2");
    }
}

void registrarLector(string ci, string nombre, DtFecha *fechaRegistro)
{
    int i = 0;

    if (colLectores.tope >= MAX_LECTORES)
        throw invalid_argument("Cantidad maxima de lectores alcanzada!!!");

    while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
        i++;

    if (colLectores.tope != i)
        throw invalid_argument("Ya existe un lector con esa cedula.");

    DtFecha fecha(fechaRegistro->getDia(), fechaRegistro->getMes(), fechaRegistro->getAnio());
    Lector *lector = new Lector(ci, nombre, fecha);
    colLectores.l[colLectores.tope] = lector;
    colLectores.tope++;
    cout << "Lector agregado con exito." << endl;
    system("sleep 2");
}

void agregarPrestamo(string ci, string codigoMaterial, DtFecha *fechaPrestamo, int diasPermitidos);

void menuAgregarPrestamo()
{
    string ci, codigoMaterial;
    int dia, mes, anio, diasPermitidos;

    system("clear");
    cout << "______________________" << endl;
    cout << "___Agregar Prestamo_____" << endl;
    cout << "Ingrece cedula del Lector: ";
    cin >> ci;
    cout << "Ingrece codigo del material a presar: ";
    cin >> codigoMaterial;
    cout << "Ingrese la fecha del prestamo: " << endl;
    cout << "Día: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
    cout << "Dias de prestamo permitidos: ";
    cin >> diasPermitidos;

    DtFecha *fecha = new DtFecha(dia, mes, anio);
    try
    {
        agregarPrestamo(ci, codigoMaterial, fecha, diasPermitidos);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << '\n';
        system("sleep 2");
    }
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha *fechaPrestamo, int diasPermitidos)
{

    int i = 0;
    if (colMateriales.tope == 0)
        throw invalid_argument("Recuerde agregar un material previamente.");

    while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
    {
        i++;
        if (colLectores.tope == i)
        {
            throw invalid_argument("No existe un Lector con esa cedula");
            system("sleep 2");
        }
    }
}

void agregarMaterial(DtMaterial *dtMaterial);

void menuAgregarMaterial()
{
    string codigo, titulo;
    int anioPublicado, tipo;

    system("clear");
    cout << "______________________" << endl;
    cout << "___Agregar Material___" << endl;
    cout << "Seleccione tipo Material: " << endl;
    cout << "1. Libro." << endl;
    cout << "2. Revista." << endl;
    cin >> tipo;
    cout << "Ingrese Codigo: ";
    cin >> codigo;
    cout << "Ingrese Titulo: ";
    cin >> titulo;
    cout << "Ingrese año publicado: ";
    cin >> anioPublicado;
    string autor;
    int cantPaginas, numEdicion, opMensual;
    bool esMensual;

    switch (tipo)
    {
    case 1:
    {
        cout << "Ingrese nombre del autor: ";
        cin >> autor;
        cout << "Ingrese cantidad de paginas: ";
        cin >> cantPaginas;

        DtLibro *dtl = new DtLibro(autor, cantPaginas, codigo, titulo, anioPublicado);
        try
        {
            agregarMaterial(dtl);
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << '\n';
            system("sleep 2");
        }
        break;
    }
    case 2:
    {

        cout << "Ingrese número de edicion: ";
        cin >> numEdicion;
        cout << "Es mensual: " << endl;
        cout << "1. Si." << endl;
        cout << "2. No." << endl;
        cin >> opMensual;
        switch (opMensual)
        {
        case 1:
        {
            esMensual = true;
            break;
        }
        case 2:
        {
            esMensual = false;
            break;
        }
        }

        DtRevista *dtr = new DtRevista(numEdicion, esMensual, codigo, titulo, anioPublicado);

        try
        {
            agregarMaterial(dtr);
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << '\n';
            system("sleep 2");
        }

        break;
    }
    }
}

void agregarMaterial(DtMaterial *dtmaterial)
{
    int i = 0;

    if (colMateriales.tope >= MAX_MATERIALES)
        throw invalid_argument("Cantidad maxima de materiales alcanzada!!!");

    while (colMateriales.tope > i && colMateriales.m[i]->getCodigo() != dtmaterial->getCodigo())
        i++;

    if (colMateriales.tope != i)
        throw invalid_argument("Ya existe un material con esa codigo.");

    if (DtLibro *dtl = dynamic_cast<DtLibro *>(dtmaterial))
    {
        Libro *l = new Libro(dtl->getAutor(), dtl->getCantPaginas(), dtl->getCodigo(), dtl->getTitulo(), dtl->getAnioPubli());
        colMateriales.m[colMateriales.tope] = l;
        colMateriales.tope++;
        cout << "Material agregado con exito." << endl;
        system("sleep 2");
    }
    else if (DtRevista *dtr = dynamic_cast<DtRevista *>(dtmaterial))
    {
        Revista *r = new Revista(dtr->getNumeroEdicion(), dtr->getEsMensual(), dtr->getCodigo(), dtr->getTitulo(), dtr->getAnioPubli());
        colMateriales.m[colMateriales.tope] = r;
        colMateriales.tope++;
        cout << "Material agregado con exito." << endl;
        system("sleep 2");
    }
}

int main()
{

    colLectores.tope = 0;
    colMateriales.tope = 0;

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
        case 3:
            menuAgregarMaterial();
            break;
        case 4:

            break;
        case 5:

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
