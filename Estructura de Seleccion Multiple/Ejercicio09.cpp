//Dada una fecha, ¿Cuantos dias faltan para que termine el año?
#include <iostream>

int main()
{
    int dia, mes, a, diaFaltante;
    std::cout
        << "Digite una fecha Valida"
        << "\nDia: ";
    std::cin >> dia;
    std::cout << "Mes: ";
    std::cin >> mes;
    std::cout << "Ano: ";
    std::cin >> a;

    switch (mes)
    {
    case 1:
        diaFaltante = 365 - dia;
        break;
    case 2:
        diaFaltante = 365 - (dia + 31);
        break;
    case 3:
        diaFaltante = 365 - (dia + 59);
        break;
    case 4:
        diaFaltante = 365 - (dia + 90);
        break;
    case 5:
        diaFaltante = 365 - (dia + 120);
        break;
    case 6:
        diaFaltante = 365 - (dia + 151);
        break;
    case 7:
        diaFaltante = 365 - (dia + 181);
        break;
    case 8:
        diaFaltante = 365 - (dia + 212);
        break;
    case 9:
        diaFaltante = 365 - (dia + 243);
        break;
    case 10:
        diaFaltante = 365 - (dia + 273);
        break;
    case 11:
        diaFaltante = 365 - (dia + 304);
        break;
    case 12:
        diaFaltante = 365 - (dia + 334);
        break;
    default:
        std::cout << "Mes invalido." << std::endl;
        break;
    }
    std::cout << "Faltan " << diaFaltante << " dias para el ano " << a + 1 << std::endl;
    system("pause");
    return 0;
}