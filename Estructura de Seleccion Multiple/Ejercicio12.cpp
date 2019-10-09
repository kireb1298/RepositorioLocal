/*
Dada una fecha, diga que dia de la semana fue, sabiendo que el 1 de enero de 1900 fue 
lunes
*/

#include <iostream>

int main()
{
    int dia, mes, anno, b, c, a, d, r;
    bool bisiesto;
    std::cout << "Digite una fecha valida (dia, mes, anno): " << std::endl;
    std::cin >> dia >> mes >> anno;

    bisiesto = ((anno % 4 == 0) && (anno % 100 != 0) || (anno % 400 == 0));

    if (bisiesto && mes > 0 && mes < 3)
        c = -1;
    else
        c = 0;

    if (anno >= 1900 && anno <= 1999)
    {
        a = 1;
        b = anno - 1900;
    }
    else if (anno >= 2000 && anno <= 2099)
    {
        a = 0;
        b = anno - 2000;
    }
    else if (anno >= 2100 && anno <= 2199)
    {
        a = -1;
        b = anno - 2100;
    }
    else if (anno >= 2200 && anno <= 2299)
    {
        a = -2;
        b = anno - 2200;
    }
    else
        std::cout << "Anno no disponible para la operacion.";

    b = b + (b / 4);

    switch (mes)
    {
    case 1:
    case 10:
        d = 6;
        break;
    case 2:
    case 3:
    case 11:
        d = 2;
        break;
    case 4:
    case 7:
        d = 5;
        break;
    case 5:
        d = 0;
        break;
    case 6:
        d = 3;
        break;
    case 8:
        d = 1;
        break;
    case 9:
    case 12:
        d = 4;
        break;
    default:
        std::cout << "Mes invalido." << std::endl;
        break;
    }

    r = dia + a + b + c + d;
    r = r % 7;

    switch (r)
    {
    case 1:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Lunes";
        break;
    case 2:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Martes";
        break;
    case 3:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Miercoles";
        break;
    case 4:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Jueves";
        break;
    case 5:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Viernes";
        break;
    case 6:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Sabado";
        break;
    case 0:
        std::cout << "El " << dia << "/" << mes << "/" << anno << " sera Domingo";
        break;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}