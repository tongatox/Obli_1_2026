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
    cout << "4. Obtener Materiales Prestados" << endl;
    cout << "5. Consultar Multa" << endl;
    cout << "6. Ver Prestamos antes de fecha" << endl;
    cout << "7. Exit" << endl;
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

    try
    {
        DtFecha *fechaRegistro = new DtFecha(dia, mes, anio);
        registrarLector(ci, nombre, fechaRegistro);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << '\n';
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
}

void agregarPrestamo(string ci, string codigoMaterial, DtFecha *fechaPrestamo, int diasPermitidos);

void menuAgregarPrestamo()
{
    string ci, codigoMaterial;
    int dia, mes, anio, diasPermitidos;

    system("clear");
    cout << "______________________" << endl;
    cout << "___Agregar Prestamo___" << endl;
    cout << "Ingrece cedula del Lector: ";
    cin >> ci;
    cout << "Ingrece codigo del material a prestar: ";
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

    try
    {
        DtFecha *fecha = new DtFecha(dia, mes, anio);
        agregarPrestamo(ci, codigoMaterial, fecha, diasPermitidos);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << '\n';
    }
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha *fechaPrestamo, int diasPermitidos)
{

    int i = 0, a = 0, f = 0;

    if (colMateriales.tope == 0)
        throw invalid_argument("Recuerde agregar un material previamente.");

    while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
        i++;
    if (colLectores.tope == i)
        throw invalid_argument("No existe un Lector con esa cedula");

    while (colMateriales.tope > a && colMateriales.m[a]->getCodigo() != codigoMaterial)
        a++;
    if (colMateriales.tope == a)
        throw invalid_argument("No existe un Material con ese codigo");

    DtFecha fecha(fechaPrestamo->getDia(), fechaPrestamo->getMes(), fechaPrestamo->getAnio());

    Prestamo *p = new Prestamo(diasPermitidos, fecha);

    p->agregarMaterial(colMateriales.m[a]);

    while (colLectores.l[i]->getTopePrestamo() > f && colLectores.l[i]->getPrestamo()[f]->getMaterial()->getCodigo() != codigoMaterial)
        f++;
    if (colLectores.l[i]->getTopePrestamo() != f)
        throw invalid_argument("Ya tiene un prestamo con ese material");

    colLectores.l[i]->agregarPrestamo(p);
    cout << "Prestamo agregado con exito." << endl;
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
    cout << "Opcion: ";
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
        cout << "Opcion: ";
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
    }
    else if (DtRevista *dtr = dynamic_cast<DtRevista *>(dtmaterial))
    {
        Revista *r = new Revista(dtr->getNumeroEdicion(), dtr->getEsMensual(), dtr->getCodigo(), dtr->getTitulo(), dtr->getAnioPubli());
        colMateriales.m[colMateriales.tope] = r;
        colMateriales.tope++;
        cout << "Material agregado con exito." << endl;
    }
}

DtMaterial **obtenerMaterialesPrestados(string ci, int &cantMateriales);

void menuObtenerMaterialesPrestados()
{

    string ci;
    int cantMateriales;
    DtMaterial **dtm;
    system("clear");
    cout << "__________________________________" << endl;
    cout << "___Obtener Materiales Prestados___" << endl;
    cout << "Ingrese cedula de lector: ";
    cin >> ci;
    cout << "Ingrese cantidad de materiales a obtener: ";
    cin >> cantMateriales;

    try
    {
        dtm = obtenerMaterialesPrestados(ci, cantMateriales);
        for (int i = 0; i < cantMateriales; i++)
        {
            dtm[i]->mostrarMateriales();
            system("sleep 1");
            cout << '\n';
        }
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << '\n';
    }
}

DtMaterial **obtenerMaterialesPrestados(string ci, int &cantMateriales)
{
    int i = 0;

    while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
        i++;
    if (colLectores.tope == i)
        throw invalid_argument("No existe un Lector con esa cedula");
    if (cantMateriales > 11)
        throw invalid_argument("La cantidad de materiales debe ser 10 como maximo.");
    if (colLectores.l[i]->getTopePrestamo() < cantMateriales)
        throw invalid_argument("No puede pedir mas materiales prestados de los que tiene el lector");

    return colLectores.l[i]->getMaterialesPrestados(cantMateriales);
}

float consultarMultaMaterial(string ci, string codigoMaterial, int diasAtraso);

void menuConsultarMultaMaterial()
{
    string ci, codigoMaterial;
    int diasAtraso;
    float multa = 0;

    system("clear");
    cout << "______________________________" << endl;
    cout << "___Consultar Multa Material___" << endl;
    cout << "Ingrese cedula del lector: ";
    cin >> ci;
    cout << "Ingrese codigo del material: ";
    cin >> codigoMaterial;
    cout << "Ingrese dias de atraso: ";
    cin >> diasAtraso;

    try
    {
        multa = consultarMultaMaterial(ci, codigoMaterial, diasAtraso);
        cout << "La multa es de: " << multa << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << '\n';
    }
}

float consultarMultaMaterial(string ci, string codigoMaterial, int diasAtraso)
{
    int i = 0, a = 0, f = 0;

    while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
        i++;
    if (colLectores.tope == i)
        throw invalid_argument("No existe un Lector con esa cedula");

    while (colMateriales.tope > a && colMateriales.m[a]->getCodigo() != codigoMaterial)
        a++;
    if (colMateriales.tope == a)
        throw invalid_argument("No existe un Material con ese codigo");

    while (colLectores.l[i]->getTopePrestamo() > f && colLectores.l[i]->getPrestamo()[f]->getMaterial()->getCodigo() != codigoMaterial)
        f++;
    if (colLectores.l[i]->getTopePrestamo() == f)
        throw invalid_argument("Ese material no esta prrstado a ese lector.");

    return colLectores.l[i]->getPrestamo()[f]->getMaterial()->calcularMulta(diasAtraso);
}

DtMaterial **verPrestamosAntesDeFecha(string ci, DtFecha *fecha, int &cantPrestamos);

void menuVerPrestamosAntesDeFecha()
{
    string ci;
    int dia, mes, anio, cantPrestamos;
    system("clear");
    cout << "__________________________________" << endl;
    cout << "___Ver Prestamos Antes de Fecha___" << endl;
    cout << "Ingrese cedula del lector: ";
    cin >> ci;
    cout << "Ingrese fecha a comparar: " << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
    cout << "Ingrese cantidad de prestamos: ";
    cin >> cantPrestamos;
    cout << '\n';
    DtMaterial **m;
    try
    {
        DtFecha *fecha = new DtFecha(dia, mes, anio);
        m = verPrestamosAntesDeFecha(ci, fecha, cantPrestamos);
        for (int i = 0; i < cantPrestamos; i++)
        {
            cout << "Prestamo: " << i + 1 << endl;
            m[i]->mostrarMateriales();
            system("sleep 1");
            cout << '\n';
        }
        system("sleep 5");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

DtMaterial **verPrestamosAntesDeFecha(string ci, DtFecha *fecha, int &cantPrestamos)
{
    int i = 0, x = 0;
    DtMaterial **dtm = new DtMaterial *[cantPrestamos];
    while (colLectores.tope > i && colLectores.l[i]->getCi() != ci)
        i++;
    if (colLectores.tope == i)
        throw invalid_argument("No existe un Lector con esa cedula");
    if (colLectores.l[i]->getTopePrestamo() < cantPrestamos)
        throw invalid_argument("No puede pedir mas prestamos de los que tiene el lector");

    for (int a = 0; a < colLectores.l[i]->getTopePrestamo(); a++)
    {
        if (colLectores.l[i]->getPrestamo()[a]->getFecha().FmayorqueF(fecha))
        {
            if (Libro *l = dynamic_cast<Libro *>(colLectores.l[i]->getPrestamo()[a]->getMaterial()))
            {
                DtLibro *dtl = new DtLibro(l->getAutor(), l->getCantPaginas(), l->getCodigo(), l->getTitulo(), l->getAnioPubli());
                if (x < cantPrestamos)
                {
                    dtm[x] = dtl;
                }
                else
                {
                    return dtm;
                }
            }
            else if (Revista *r = dynamic_cast<Revista *>(colLectores.l[i]->getPrestamo()[a]->getMaterial()))
            {
                DtRevista *dtr = new DtRevista(r->getNumeroEdicion(), r->getEsMensual(), r->getCodigo(), r->getTitulo(), r->getAnioPubli());
                if (x < cantPrestamos)
                {
                    dtm[x] = dtr;
                }
                else
                {
                    return dtm;
                }
            }
            x++;
        }
    }
    cantPrestamos = x;
    return dtm;
}

int main()
{

    colLectores.tope = 0;
    colMateriales.tope = 0;

    int opcion;
    menu();
    cin >> opcion;
    while (opcion != 7)
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
            menuObtenerMaterialesPrestados();
            break;
        case 5:
            menuConsultarMultaMaterial();
            break;
        case 6:
            menuVerPrestamosAntesDeFecha();
            break;
        }
        system("sleep 2");
        menu();
        cin >> opcion;
    }
    cout << "Chauu!!" << endl;
    system("sleep 1");
    system("clear");
    return 0;
}
