#include "librerias.h"

//PROTOTIPO DE FUNCIONES
void titulo(Informacion e);
void ascii(int codAscii, int cant);
bool AjustarVentana(int Ancho, int Alto);
void bienvenida();
void menuMain();
void menuOpcion2();
void menuOpcion3();
void menuOpcion4();
void menuOpcion5();


//FUNCIONES
void titulo(Informacion e)
{
    std::string nombre = e.razonSocial, tipo = e.tipo;
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);   
    std::cout << std::endl;
    std::cout << "\t\t"; ascii(205, 70);
    std::cout << std::endl;
    std::cout << "\t\t\t"; std::cout << "AGENCIA DE TRANSPORTES \"" << nombre << " " << tipo << "\"\n";
    std::cout << "\t\t\t\t"; std::cout << " COPYRIGHT 2019 | BY MILCESAR MP" << std::endl;
    std::cout << "\t\t"; ascii(205, 70);
    std::cout << std::endl << std::endl;
    ascii(196, 100); std::cout << std::endl << std::endl;
}

void ascii(int codAscii, int cant)
{
    for(int i = 0; i < cant; i++)
    {
        std::cout << char(codAscii); 
    } 
}

bool AjustarVentana(int Ancho, int Alto)
{
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;

    // Obtener el handle de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustar el buffer al nuevo tamaño
    SetConsoleScreenBufferSize(hConsola, Coordenada);

    // Cambiar tamaño de consola a lo especificado en el buffer
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}

void bienvenida()
{
    std::cout << "      _       _   _____   _    _   _    _   _____   _    _   _   ___     _____        \n";
    std::cout << "     | |     |_| |  ___| | \\  | | | |  | | |  ___| | \\  | | |_| |   \\   |  _  |    \n";
    std::cout << "     | |___   _  | |___  |  \\ | | | |  | | | |___  |  \\ | |  _  | |\\ \\  | | | |   \n";
    std::cout << "     |  _  | | | |  ___| |   \\| |  \\ \\/ /  |  ___| |   \\| | | | | | \\ \\ | | | |   \n";
    std::cout << "     | |_| | | | | |___  | |\\   |   \\  /   | |___  | |\\   | | | | |_/ / | |_| |     \n";
    std::cout << "     |_____| |_| |_____| |_| \\__|    \\/    |_____| |_| \\__| |_| |____/  |_____|     \n";
    std::cout << "                                                         By: Milcesar                \n";
    ascii(196, 100);
    std::cout 
        << std::endl
        << "\tBienvenido al asistente de instalacion.\n"
        << "\tAl no existir un archivo DATA.dat se procedera a crear uno.\n"
        << "\tProporcione correctamente los datos que se le pida.\n\n"
        << "\tRECOMENDACIONES:\n"
        << "\tEl RUC tiene [11] digitos.\n"
        << "\tEl DNI tiene [8] digitos.\n"
        << "\tPara iniciar, debe ingresar la informacion de 1 vehiculo.\n"
        << "\tPuedes ingresar mas vehiculo despues de la instalacion.\n\n";
}

void menuMain()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\t\t\t[ MENU PRINCIPAL ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout 
        << "\t\t1 >> Empresa\n"
        << "\t\t2 >> Vehiculos\n"
        << "\t\t3 >> Empleados\n"
        << "\t\t4 >> Clientes\n"
        << "\t\t5 >> Encargos\n"
        << "\t\t6 >> Salir\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\t\tIngrese una opcion: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void menuOpcion2()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\t\t\t[ MENU VEHICULOS ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout 
        << "\t\t1 >> Ver todos los vehiculos\n"
        << "\t\t2 >> Anadir vehiculo\n"
        << "\t\t3 >> Borrar vehiculo\n"
        << "\t\t4 >> Buscar vehiculo\n"
        << "\t\t5 >> Volver\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\t\tIngrese una opcion: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void menuOpcion3()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\t\t\t[ MENU EMPLEADOS ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout 
        << "\t\t1 >> Ver todos los empleados.\n"
        << "\t\t2 >> Anadir empleado\n"
        << "\t\t3 >> Borrar empleado\n"
        << "\t\t4 >> Buscar empleado\n"
        << "\t\t5 >> Volver\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\t\tIngrese una opcion: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void menuOpcion4()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\t\t\t[ MENU EMPLEADOS ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout 
        << "\t\t1 >> Ver todos los clientes.\n"
        << "\t\t2 >> Anadir cliente\n"
        << "\t\t3 >> Borrar cliente\n"
        << "\t\t4 >> Buscar cliente\n"
        << "\t\t5 >> Volver\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\t\tIngrese una opcion: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void menuOpcion5()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\t\t\t[ MENU ENCARGOS ]\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout 
        << "\t\t1 >> Ver todos los encargos.\n"
        << "\t\t2 >> Anadir encargo\n"
        << "\t\t3 >> Borrar encargo\n"
        << "\t\t4 >> Buscar encargo\n"
        << "\t\t5 >> Volver\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\t\tIngrese una opcion: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}