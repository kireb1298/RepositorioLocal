#include "librerias.h"
#include "estructuras.h"
#include "interfaz.h"

//PROTOTIPO DE FUNCIONES
void instalacion();
void init(ColaV &c);
void init(ColaE &c);
void enqueue(ColaV &c, Vehiculo x);
void enqueue(ColaE &c, Trabajador x);
bool empty(ColaV c);
bool empty(ColaE c);
Vehiculo dequeue(ColaV &c);
Trabajador dequeue(ColaE);
void menuOpcion1(Informacion e, Trabajador g);


//FUNCIONES
void instalacion()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    bienvenida();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Informacion e;
    Trabajador g;
    Vehiculo m;

    std::string text;
    int opc, temp;
    std::ofstream crearInfo("DATA.dat", std::ios::binary);
    if (!crearInfo)
    {
        std::cout << "\tNO SE PUDO CREAR EL ARCHIVO [DATA.dat]" << std::endl;
        exit(1);
    }

    std::cout << "\tEXITO AL CREAR EL ARCHIVO [DATA.dat]...\n"
              << std::endl;

    std::cout
        << "\t\t[  DATOS DE LA EMPRESA  ]\n"
        << "\tRazon Social: ";
    std::cin.getline(e.razonSocial, 50);
    std::cout << "\tRUC: ";
    std::cin.getline(e.ruc, 13);
    std::cout << "\tCiudad: ";
    std::cin.getline(e.ciudad, 50);
    std::cout << "\tDireccion: ";
    std::cin.getline(e.direccion, 100);
    std::cout<< "\tTelefono: ";
    std::cin.getline(e.telefono, 14);
    std::cout
        << "\tTipo de empresa:\n"
        << "\t\t 1  >> Sociedad Anonima Abierta.\n"
        << "\t\t 2  >> Sociedad Anonima Cerrada.\n"
        << "\tDigite una opcion: ";
    std::cin >> opc;
    while (opc < 1 || opc > 2)
    {
        std::cout << "\tDigite opcion correcta: ";
        std::cin >> opc;
    }
    text = (opc == 1) ? "S.A.A" : "S.A.C";
    strcpy(e.tipo, text.c_str());
    e.nVehiculos = 1;
    e.nEmpleados = 1;
    crearInfo.write((char *)&e, sizeof(Informacion));
    crearInfo.close();
    std::cout << "\n";
    system("pause");
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    bienvenida();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::ofstream crearGerente("EMPLEADOS.dat", std::ios::binary);
    if (!crearGerente)
    {
        std::cout << "\n\tNO SE PUDO CREAR EL ARCHIVO [EMPLEADOS.dat]" << std::endl;
        exit(1);
    }
    std::cout << "\n\tEXITO AL CREAR EL ARCHIVO [EMPLEADOS.dat]...\n"
              << std::endl;
    std::cout << "\t\t[  DATOS DEL GERENTE  ]\n";
    std::cin.ignore();
    std::cout << "\tDNI: ";
    std::cin.getline(g.dni, 15);
    std::cout << "\tNombres: ";
    std::cin.getline(g.nombre, 50);
    std::cout << "\tApellidos: ";
    std::cin.getline(g.apellido, 50);
    std::cout << "\tEdad: ";
    std::cin >> g.edad;
    std::cin.ignore();
    std::cout << "\tCorreo Electronico: ";
    std::cin.getline(g.email, 70);
    std::cout << "\tAnno de ingreso: ";
    std::cin >> g.annIngreso;
    std::cin.ignore();
    g.nro = 1;
    crearGerente.write((char *)&g, sizeof(Trabajador));
    crearGerente.close();
    std::cout << "\n";
    system("pause");
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    bienvenida();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::ofstream machine("MACHINE.dat", std::ios::binary);
    if (!crearGerente)
    {
        std::cout << "\n\tNO SE PUDO CREAR EL ARCHIVO [MACHINE.dat]" << std::endl;
        exit(1);
    }

    
    std::cout << "\n\tEXITO AL CREAR EL ARCHIVO [MACHINE.dat]...\n"
              << std::endl;
    std::cout << "\t\t[  VEHICULOS  ]\n";

    std::cout << "\t[ Vehiculo >> N" << 1 << " ]" << std::endl;
    m.nro = 1;
    std::cout << "\tPlaca: ";
    std::cin.getline(m.placa, 10);
    std::cout << "\tMarca: ";
    std::cin.getline(m.marca, 15);
    std::cout
        << "\tTipo: \n"
        << "\t\t1  >> Omnibus\n"
        << "\t\t2  >> Camion\n"
        << "\t\t3  >> Plataforma\n"
        << "\tDigite una opcion: ";
    std::cin >> opc;
    std::cin.ignore();
    while (opc < 1 || opc > 3)
    {
        std::cout << "\tDigite opcion correcta: ";
        std::cin >> opc;
    }
    if (opc == 1)
    {
        text = "Omnibus";
        m.capMaxM = 2000;
        m.nroAsientos = 45;
    }
    else if (opc == 2)
    {
        text = "Camion";
        m.capMaxM = 15000;
        m.nroAsientos = 2;
    }
    else
    {
        text = "Plataforma";
        m.capMaxM = 30000;
        m.nroAsientos = 2;
    }
    strcpy(m.tipo, text.c_str());
    machine.write((char *)&m, sizeof(Vehiculo));
    machine.close();
    std::cout << std::endl;
}

void init(ColaV &c)
{
    c.primero = NULL;
    c.ultimo = NULL;
}

void init(ColaE &c)
{
    c.primero = NULL;
    c.ultimo = NULL;
}

void enqueue(ColaV &c, Vehiculo x)
{
    PNodov nuevo = new NodoV;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(c))
    {
        c.primero = nuevo;
        c.ultimo = nuevo;
    }
    else
    {
        c.ultimo->sgte = nuevo;
        c.ultimo = nuevo;
    }
}

void enqueue(ColaE &c, Trabajador x)
{
    PNodoe nuevo = new NodoE;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(c))
    {
        c.primero = nuevo;
        c.ultimo = nuevo;
    }
    else
    {
        c.ultimo->sgte = nuevo;
        c.ultimo = nuevo;
    }
}

bool empty(ColaV c)
{
    return (c.primero == NULL) ? true : false;
}

bool empty(ColaE c)
{
    return (c.primero == NULL) ? true : false;
}

Vehiculo dequeue(ColaV &c)
{
    Vehiculo x = c.primero->info;
    PNodov temp = c.primero;
    c.primero = c.primero->sgte;
    delete temp;
    return x;
}

Trabajador dequeue(ColaE &c)
{
    Trabajador x = c.primero->info;
    PNodoe temp = c.primero;
    c.primero = c.primero->sgte;
    delete temp;
    return x;
}

void menuOpcion1(Informacion e, Trabajador g)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\t\t[ INFORMACION COMPLETA DE LA EMPRESA ]\n\n";
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tRAZON SOCIAL: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.razonSocial << " " << e.tipo << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tRUC: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.ruc<< std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tCIUDAD: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.ciudad<< std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tDIRECCION: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.direccion<< std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tTELEFONO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.telefono<< std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tNUMERO DE CONDUCTORES: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.nEmpleados - 1 << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tNUMERO DE VEHICULOS: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.nVehiculos << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout 
        << "\n\t[ GERENTE ] \n"
        << "\tNOMBRE(S): ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << g.nombre << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tAPELLIDOS: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << g.apellido << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tDNI: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << g.dni << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tEDAD: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << g.edad << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tANNO DE INGRESO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << g.annIngreso << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tEMAIL: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << g.email << std::endl << std::endl;
    
    
    
    

}