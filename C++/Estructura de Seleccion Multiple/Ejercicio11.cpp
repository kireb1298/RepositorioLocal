/*
Todo el mundo sabe cuantos annos tiene, pero ¿podria contestar a la pregunta cuantos dias tiene?
*/
#include <iostream>
#include <cstdlib>

int main()
{
    int dia1, dia2, mes1, mes2, a1, a2, aux1, aux2, diasTranscurridos;
    std::cout << "Digite Fecha de nacimiento (dia, mes y anno): " << std::endl;
    std::cin >> dia1 >> mes1 >> a1;
    std::cout << "Digite fecha actual (dia, mes y anno): " << std::endl;
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
    else
    {
        diasTranscurridos = (a1 - a2) - 1;
        diasTranscurridos *= 365;
        diasTranscurridos += (365 - aux2) + aux1;
        diasTranscurridos = abs(diasTranscurridos);
    }
    std::cout << "Usted tiene " << diasTranscurridos << " dias." << std::endl;
    system("pause");
    return 0;
}

/* Esta es otra manera de hacerlo usando la libreria ctime
#include <iostream>
#include <ctime>

int main()
{
    int dia, mes, anno, totalDias;
    bool bisiesto;
    time_t tiempo = time(0);
    tm *aux = localtime(&tiempo);

    std::cout << "Digite una fecha de nacimiento valida (dia/mes/anno)" << std::endl;
    std::cin >> dia >> mes >> anno;

    totalDias = 365 * ((aux->tm_year + 1900) - anno);
    totalDias += aux->tm_yday;  
    std::cout << "Tienes " << totalDias<< " dias en total."<< std::endl;

    return 0;
}
*/