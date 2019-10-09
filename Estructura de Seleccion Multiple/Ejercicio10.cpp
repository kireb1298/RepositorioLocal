//Obtenga el numero de dias transcurridos entre dos fechas
#include <iostream>
#include <cstdlib>

int main()
{
    int dia1, dia2, mes1, mes2, a1, a2, aux1, aux2, diasTranscurridos;
    std::cout << "Digite la primer fecha (dia, mes y anno): " << std::endl;
    std::cin >> dia1 >> mes1 >> a1;
    std::cout << "Digite la segunda fecha (dia, mes y anno): " << std::endl;
    std::cin >> dia2 >> mes2 >> a2;

    switch (mes1)
    {
    case 1:
        aux1 = dia1;
        break;
    case 2:
        aux1 = dia1 + 31;
        break;
    case 3:
        aux1 = dia1 + 59;
        break;
    case 4:
        aux1 = dia1 + 90;
        break;
    case 5:
        aux1 = dia1 + 120;
        break;
    case 6:
        aux1 = dia1 + 151;
        break;
    case 7:
        aux1 = dia1 + 181;
        break;
    case 8:
        aux1 = dia1 + 212;
        break;
    case 9:
        aux1 = dia1 + 243;
        break;
    case 10:
        aux1 = dia1 + 273;
        break;
    case 11:
        aux1 = dia1 + 304;
        break;
    case 12:
        aux1 = dia1 + 334;
        break;
    default:
        std::cout << "Mes invalido." << std::endl;
    }

    switch (mes2)
    {
    case 1:
        aux2 = dia2;
        break;
    case 2:
        aux2 = dia2 + 31;
        break;
    case 3:
        aux2 = dia2 + 59;
        break;
    case 4:
        aux2 = dia2 + 90;
        break;
    case 5:
        aux2 = dia2 + 120;
        break;
    case 6:
        aux2 = dia2 + 151;
        break;
    case 7:
        aux2 = dia2 + 181;
        break;
    case 8:
        aux2 = dia2 + 212;
        break;
    case 9:
        aux2 = dia2 + 243;
        break;
    case 10:
        aux2 = dia2 + 273;
        break;
    case 11:
        aux2 = dia2 + 304;
        break;
    case 12:
        aux2 = dia2 + 334;
        break;
    default:
        std::cout << "Mes invalido." << std::endl;
    }

    if (a1 == a2)
    {
        diasTranscurridos = aux1 - aux2;
        diasTranscurridos = abs(diasTranscurridos);
    }
    else if (a1 > a2)
    {
        diasTranscurridos = (a1 - a2) - 1;
        diasTranscurridos *= 365;
        diasTranscurridos += (365 - aux1) + aux2;
        diasTranscurridos = abs(diasTranscurridos);
    }
    else
    {
        diasTranscurridos = (a1 - a2) - 1;
        diasTranscurridos *= 365;
        diasTranscurridos += (365 - aux2) + aux1;
        diasTranscurridos = abs(diasTranscurridos);
    }

    std::cout << "La cantidad de dias transcurridos entre las dos fechas es: " << diasTranscurridos << std::endl;
    system("pause");
    return 0;
}