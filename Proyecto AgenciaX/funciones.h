#include "librerias.h"
#include "estructuras.h"
#include "interfaz.h"

//PROTOTIPO DE FUNCIONES
void instalacion();
void init(ColaV &c);
void init(ColaE &c);
void init(ColaC &c);
void init(ColaP &c);
void enqueue(ColaV &c, Vehiculo x);
void enqueue(ColaE &c, Trabajador x);
void enqueue(ColaC &c, Cliente x);
void enqueue(ColaP &c, Encargo x);
bool empty(ColaV c);
bool empty(ColaE c);
bool empty(ColaC c);
bool empty(ColaP c);
Vehiculo dequeue(ColaV &c);
Trabajador dequeue(ColaE &c);
Cliente dequeue(ColaC &c);
Encargo dequeue(ColaP &c);
void verCola(ColaV c);
void verCola(ColaE c);
void verCola(ColaC c);
void verCola(ColaP c);
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
    std::cout << "\tTelefono: ";
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
    e.nEncargos = 0;
    e.nClientes = 0;
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
    g.nro = 0;
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

    std::ofstream cliente("CLIENTE.dat", std::ios::binary);
    if (!crearGerente)
    {
        std::cout << "\n\tNO SE PUDO CREAR EL ARCHIVO [CLIENTE.dat]" << std::endl;
        exit(1);
    }

    std::cout << "\n\tEXITO AL CREAR EL ARCHIVO [CLIENTE.dat]...\n"
              << std::endl;

    std::ofstream encargo("ENCARGO.dat", std::ios::binary);
    if (!crearGerente)
    {
        std::cout << "\n\tNO SE PUDO CREAR EL ARCHIVO [ENCARGO.dat]" << std::endl;
        exit(1);
    }

    std::cout << "\n\tEXITO AL CREAR EL ARCHIVO [ENCARGO.dat]...\n"
              << std::endl;
    cliente.close();
    encargo.close();
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

void init(ColaC &c)
{
    c.primero = NULL;
    c.ultimo = NULL;
}

void init(ColaP &c)
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
        if (strcmp(c.ultimo->info.placa, nuevo->info.placa) != 0)
        {
            c.ultimo->sgte = nuevo;
            c.ultimo = nuevo;
        }
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
        if (strcmp(c.ultimo->info.dni, nuevo->info.dni) != 0)
        {
            c.ultimo->sgte = nuevo;
            c.ultimo = nuevo;
        }
    }
}

void enqueue(ColaC &c, Cliente x)
{
    PNodoc nuevo = new NodoC;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(c))
    {
        c.primero = nuevo;
        c.ultimo = nuevo;
    }
    else
    {
        if (strcmp(c.ultimo->info.dni, nuevo->info.dni) != 0)
        {
            c.ultimo->sgte = nuevo;
            c.ultimo = nuevo;
        }
    }
}

void enqueue(ColaP &c, Encargo x)
{
    PNodop nuevo = new NodoP;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(c))
    {
        c.primero = nuevo;
        c.ultimo = nuevo;
    }
    else
    {
        if (c.ultimo->info.codigo != nuevo->info.codigo)
        {
            c.ultimo->sgte = nuevo;
            c.ultimo = nuevo;
        }
    }
}

void enqueuePriority(ColaP &c, Encargo x)
{
    PNodop nuevo = new NodoP;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(c))
    {
        c.primero = nuevo;
        c.ultimo = nuevo;
    }
    else if (x.priority < c.primero->info.priority)
    {
        nuevo->sgte = c.primero;
        c.primero = nuevo;
    }
    else
    {
        PNodop p = c.primero;
        while (p->sgte != NULL && p->sgte->info.priority < x.priority)
            p = p->sgte;
        nuevo->sgte = p->sgte;
        p->sgte = nuevo;
        if (nuevo->sgte == NULL)
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

bool empty(ColaC c)
{
    return (c.primero == NULL) ? true : false;
}

bool empty(ColaP c)
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

Cliente dequeue(ColaC &c)
{
    Cliente x = c.primero->info;
    PNodoc temp = c.primero;
    c.primero = c.primero->sgte;
    delete temp;
    return x;
}

Encargo dequeue(ColaP &c)
{
    Encargo x = c.primero->info;
    PNodop temp = c.primero;
    c.primero = c.primero->sgte;
    delete temp;
    return x;
}

void verCola(ColaV c)
{

    PNodov p;
    p = c.primero;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t[ INFORMACION DE TODOS LOS VEHICULOS ] \n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (p != NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\tVEHICULO N";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.nro;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tPLACA: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.placa;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tTIPO: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.tipo;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tMARCA: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.marca;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tCAPACIDAD DE MERCANCIA: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout
            << p->info.capMaxM
            << " kg";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tNUMERO DE ASIENTOS: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout
            << p->info.nroAsientos
            << "\n\n";
        p = p->sgte;
    }
}

void verCola(ColaE c)
{
    PNodoe p;
    p = c.primero;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t[ INFORMACION DE TODOS LOS EMPLEADOS ] \n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (p != NULL)
    {
        if (p->info.nro != 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tNOMBRE(S): ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.nombre << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tAPELLIDOS: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.apellido << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tDNI: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.dni << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tEDAD: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.edad << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tANNO DE INGRESO: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.annIngreso << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tEMAIL: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.email << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tSUELDO: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.sueldo << std::endl
                      << std::endl;
        }
        p = p->sgte;
    }
}

void verCola(ColaC c)
{
    PNodoc p;
    p = c.primero;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t[ INFORMACION DE TODOS LOS CLIENTES ] \n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (p != NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tNOMBRE(S): ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.nombre;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tAPELLIDOS: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.apellido;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\t:PREFERENCIA: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        if (p->info.preferencia == 1)
            std::cout << "Premium";
        else if (p->info.preferencia == 2)
            std::cout << "Regular";
        else
            std::cout << "Nuevo";
        std::cout << "\n\n";
        p = p->sgte;
    }
}

void verCola(ColaP c)
{
    PNodop p;
    p = c.primero;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t[ INFORMACION DE TODOS LOS ENCARGOS ] \n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (p != NULL)
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tCODIGO: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.codigo;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\tDIRECCION: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.direccion;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "\n\t:DESCRIPCION: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << p->info.descripcion;
        std::cout << "\n\n";
        p = p->sgte;
    }
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
    std::cout << e.ruc << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tCIUDAD: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.ciudad << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tDIRECCION: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.direccion << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tTELEFONO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.telefono << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tNUMERO DE CONDUCTORES: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.nEmpleados - 1 << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tNUMERO DE VEHICULOS: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.nVehiculos << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tNUMERO DE CLIENTES: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.nClientes << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\tNUMERO DE ENCARGOS: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << e.nEncargos << std::endl;
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
    std::cout << g.email << std::endl
              << std::endl;
}

void addVehiculo(Informacion &e, ColaV &c)
{
    int opc;
    std::string text;
    Vehiculo aux;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t\t[ AGREGAR VEHICULO ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    e.nVehiculos++;
    aux.nro = e.nVehiculos;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tPLACA: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.ignore();
    std::cin.getline(aux.placa, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tMARCA: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(aux.marca, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout
        << "\tTIPO:\n"
        << "\t\t1  >> Omnibus\n"
        << "\t\t2  >> Camion\n"
        << "\t\t3  >> Plataforma\n"
        << "\tDigite una opcion: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin >> opc;
    while (opc < 1 || opc > 3)
    {
        std::cout << "\tDigite opcion correcta: ";
        std::cin >> opc;
    }
    if (opc == 1)
    {
        text = "Omnibus";
        aux.capMaxM = 2000;
        aux.nroAsientos = 45;
    }
    else if (opc == 2)
    {
        text = "Camion";
        aux.capMaxM = 15000;
        aux.nroAsientos = 2;
    }
    else
    {
        text = "Plataforma";
        aux.capMaxM = 30000;
        aux.nroAsientos = 2;
    }
    strcpy(aux.tipo, text.c_str());
    enqueue(c, aux);
    std::cout << std::endl
              << std::endl;
}

void addEmpleado(Informacion &e, ColaE &c)
{
    Trabajador x;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t[ AGREGAR EMPLEADO ] \n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    e.nEmpleados++;
    x.nro = e.nEmpleados;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tNOMBRE: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.ignore();
    std::cin.getline(x.nombre, 50);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tAPELLIDO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(x.apellido, 50);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tDNI: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(x.dni, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tEMAIL: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(x.email, 70);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tEDAD: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin >> x.edad;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tANNO DE INGRESO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin >> x.annIngreso;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tSUELDO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin >> x.sueldo;
    enqueue(c, x);
    std::cout << std::endl
              << std::endl;
}

void addEncargo(Informacion &e, ColaP &c, ColaC &d)
{
    srand(time(NULL));
    Encargo p;
    Cliente q;
    PNodoc bus = d.primero;
    bool exito = false;
    int priority;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t\t[ AGREGAR ENCARGO ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    e.nEncargos++;
    p.codigo = 10000 + rand() % (100000 - 10000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tDIRECCION: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.ignore();
    std::cin.getline(p.direccion, 50);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tCODIGO POSTAL: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(p.codPostal, 50);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tDESCRIPCION: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(p.descripcion, 50);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tDNI DEL CLIENTE: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(p.dniCliente, 15);

    while (bus != NULL)
    {
        if (strcmp(p.dniCliente, bus->info.dni) == 0)
        {
            q = bus->info;
            exito = true;
        }
        bus = bus->sgte;
    }

    if (exito == true)
        std::cout << "\tSE AGREGO CON EXITO...\n";
    else
    {
        std::cout << "\tNO EXISTE EL CLIENTE...\n";
        exit(1);
    }
    priority = q.preferencia;
    p.priority = priority;
    enqueuePriority(c, p);
    std::cout << std::endl
              << std::endl;
}

void addCliente(Informacion &e, ColaC c)
{
    Cliente p;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\n\n\t\t\t[ AGREGAR CLIENTE ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    e.nClientes++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tNOMBRE: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.ignore();
    std::cin.getline(p.nombre, 40);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tAPELLIDO: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(p.apellido, 40);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\tDNI: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cin.getline(p.dni, 15);
    p.preferencia = 3;
    enqueue(c, p);
    std::cout << std::endl
              << std::endl;
}

void busVehiculo(ColaV c)
{
    bool exito = false;
    char dato[10];
    std::cin.ignore();
    std::cout << "\n\n\tIngrese la placa: ";
    std::cin.getline(dato, 10);
    PNodov p;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->info.placa, dato) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tVEHICULO N";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.nro;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tPLACA: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.placa;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tTIPO: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.tipo;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tMARCA: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.marca;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tCAPACIDAD DE MERCANCIA: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout
                << p->info.capMaxM
                << " kg";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tNUMERO DE ASIENTOS: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout
                << p->info.nroAsientos
                << "\n\n";
            exito = true;
        }
        p = p->sgte;
    }
    if (exito == false)
        std::cout << "\n\tNO SE HALLARON RESULTADOS...\n";
}

void busEmpleado(ColaE c)
{
    bool exito = false;
    char dato[15];
    std::cin.ignore();
    std::cout << "\n\n\tIngrese el DNI: ";
    std::cin.getline(dato, 15);
    PNodoe p;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->info.dni, dato) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tNOMBRE(S): ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.nombre << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tAPELLIDOS: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.apellido << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tDNI: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.dni << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tEDAD: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.edad << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tANNO DE INGRESO: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.annIngreso << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tEMAIL: " << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.email;
            std::cout << "\tSUELDO: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.sueldo << std::endl
                      << std::endl;
            exito = true;
        }
        p = p->sgte;
    }
    if (exito == false)
        std::cout << "\n\tNO SE HALLARON RESULTADOS...\n";
}

void busCliente(ColaC c)
{
    char dato[15];
    bool exito = false;
    std::cin.ignore();
    std::cout << "\n\n\tIngrese el DNI: ";
    std::cin.getline(dato, 15);
    PNodoc p;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->info.dni, dato) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tNOMBRE";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.nombre;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tAPELLIDO";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.apellido;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tDNI";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.dni;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tPREFERENCIA";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.preferencia << std::endl
                      << std::endl;
            exito = true;
        }
        p = p->sgte;
    }
    if (exito == false)
        std::cout << "\n\tNO SE HALLARON RESULTADOS...\n";
}

void busEncargo(ColaP c)
{
    int dato;
    bool exito = false;
    std::cout << "\n\n\tIngrese el codigo: ";
    std::cin >> dato;
    PNodop p;
    p = c.primero;
    while (p != NULL)
    {
        if (p->info.codigo == dato)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\n\tDIRECCION: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.direccion;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tCODIGO POSTAL: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.codPostal;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tDESCRIPCION: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.direccion;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\tDNI DEL CLIENTE: ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            std::cout << p->info.dniCliente << std::endl
                      << std::endl;
            exito = true;
        }
        p = p->sgte;
    }

    if (exito == false)
        std::cout << "\n\n\tNO SE ENCONTRARON RESULTADOS...";
}

void delVehiculo(ColaV &c)
{
    bool exito = false;
    char dato[10];
    std::string text;
    std::cin.ignore();
    std::cout << "\n\n\tIngrese la placa: ";
    std::cin.getline(dato, 10);
    PNodov p, aux;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->sgte->info.placa, dato) == 0)
        {
            aux = p->sgte;
            p->sgte = p->sgte->sgte;
            delete aux;
            exito = true;
        }
        p = p->sgte;
    }
    text = (exito) ? "\n\n\tEXITO AL BORRAR.." : "\n\n\tNO SE ENCONTRO RESULTADOS...";
    std::cout << text << std::endl
              << std::endl;
}

void delEmpleado(ColaE &c)
{
    bool exito = false;
    char dato[10];
    std::string text;
    std::cin.ignore();
    std::cout << "\n\n\tIngrese el dni: ";
    std::cin.getline(dato, 15);
    PNodoe p, aux;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->sgte->info.dni, dato) == 0)
        {
            aux = p->sgte;
            p->sgte = p->sgte->sgte;
            delete aux;
            exito = true;
        }
        p = p->sgte;
    }
    text = (exito) ? "\n\n\tEXITO AL BORRAR.." : "\n\n\tNO SE ENCONTRO RESULTADOS...";
    std::cout << text << std::endl
              << std::endl;
}

void delCliente(ColaC &c)
{
    bool exito = false;
    char dato[10];
    std::string text;
    std::cin.ignore();
    std::cout << "\n\n\tIngrese el dni: ";
    std::cin.getline(dato, 15);
    PNodoc p, aux;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->sgte->info.dni, dato) == 0)
        {
            aux = p->sgte;
            p->sgte = p->sgte->sgte;
            delete aux;
            exito = true;
        }
        p = p->sgte;
    }
    text = (exito) ? "\n\n\tEXITO AL BORRAR.." : "\n\n\tNO SE ENCONTRO RESULTADOS...";
    std::cout << text << std::endl
              << std::endl;
}

void delEncargo(ColaP &c)
{
    bool exito = false;
    int dato;
    std::string text;
    std::cin.ignore();
    std::cout << "\n\n\tIngrese el codigo: ";
    std::cin >> dato;
    PNodop p, aux;
    p = c.primero;
    while (p != NULL)
    {
        if (p->sgte->info.codigo == dato)
        {
            aux = p->sgte;
            p->sgte = p->sgte->sgte;
            delete aux;
            exito = true;
        }
        p = p->sgte;
    }
    text = (exito) ? "\n\n\tEXITO AL BORRAR.." : "\n\n\tNO SE ENCONTRO RESULTADOS...";
    std::cout << text << std::endl
              << std::endl;
}

void preferencia(ColaC &c)
{
    char dato[15];
    int pr;
    std::cin.ignore();
    std::cout << "\n\n\tIngrese el DNI: ";
    std::cin.getline(dato, 15);
    std::cout
        << "\tPreferencia: \n"
        << "\t\t1 >> Premium\n"
        << "\t\t2 >> Regular\n"
        << "\tIngrese una opcion: ";
    std::cin >> pr;
    PNodoc p;
    p = c.primero;
    while (p != NULL)
    {
        if (strcmp(p->info.dni, dato) == 0)
        {
            p->info.preferencia = pr;
        }
    }
    std::cout << "\n\n";
}

void guardarDatosV(ColaV c)
{
    Vehiculo aux;
    std::ofstream save("tempv.dat", std::ios::binary);
    while (!empty(c))
    {
        aux = dequeue(c);
        save.write((char *)&aux, sizeof(Vehiculo));
    }
    std::cout << "\tEXITO AL GUARDAR MACHINE.DAT...\n";
    save.close();
}

void guardarDatosI(Informacion c)
{
    std::ofstream save("tempi.dat", std::ios::binary);
    save.write((char *)&c, sizeof(Informacion));
    std::cout << "\n\n\tEXITO AL GUARDAR DATA.dat...\n";
    save.close();
}

void guardarDatosE(ColaE c)
{
    Trabajador aux;
    std::ofstream save("tempe.dat", std::ios::binary);
    while (!empty(c))
    {
        aux = dequeue(c);
        save.write((char *)&aux, sizeof(Trabajador));
    }
    std::cout << "\tEXITO AL GUARDAR EMPLEADOS.dat...\n";
    save.close();
}

void guardarDatosC(ColaC c)
{
    Cliente aux;
    std::ofstream save("tempc.dat", std::ios::binary);
    while (!empty(c))
    {
        aux = dequeue(c);
        save.write((char *)&aux, sizeof(Cliente));
    }
    std::cout << "\tEXITO AL GUARDAR CLIENTE.dat...\n";
    save.close();
}

void guardarDatosP(ColaP c)
{
    Encargo aux;
    std::ofstream save("tempp.dat", std::ios::binary);
    while (!empty(c))
    {
        aux = dequeue(c);
        save.write((char *)&aux, sizeof(Encargo));
    }
    std::cout << "\tEXITO AL GUARDAR ENCARGO.dat...\n\n";
    save.close();
}