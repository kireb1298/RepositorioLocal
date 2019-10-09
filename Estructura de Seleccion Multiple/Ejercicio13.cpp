/*
Dada una fecha, obtenga el numero de dia dentro de ese anno. Por ejemplo, el 26/10/2000
es el dia 300 del año 2000
*/

#include <iostream>

int main()
{
    int dia, mes, anno, aux;

    std::cout << "Digite una fecha valida (dia, mes, anno): " << std::endl;
    std::cin >> dia >> mes >> anno;

    switch (mes)
    {
    case 1:
        aux = dia;
        break;
    case 2:
        aux = dia + 31;
        break;
    case 3:
        aux = dia + 59;
        break;
    case 4:
        aux = dia + 90;
        break;
    case 5:
        aux = dia + 120;
        break;
    case 6:
        aux = dia + 151;
        break;
    case 7:
        aux = dia + 181;
        break;
    case 8:
        aux = dia + 212;
        break;
    case 9:
        aux = dia + 243;
        break;
    case 10:
        aux = dia + 273;
        break;
    case 11:
        aux = dia + 304;
        break;
    case 12:
        aux = dia + 334;
        break;
    default:
        std::cout << "Mes invalido." << std::endl;
    }

    std::cout << "El " << dia << "/" << mes << "/" << anno << " es el dia " << aux << " del anno " << anno << std::endl; 
    system("pause");
    return 0;
}