//Dada una fecha, diga la fecha del dia de ayer

#include <iostream>

int main()
{
    int dia, mes, a, maxdia;
    std::cout << "Digite una fecha valida: " << std::endl;
    std::cout << "Dia: ";
    std::cin >> dia;
    std::cout << "Mes: ";
    std::cin >> mes;
    std::cout << "Ano: ";
    std::cin >> a;
    if (dia == 1)
        mes = mes - 1;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxdia = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxdia = 30;
        break;
    case 2:
        if (!(a % 4) && (a % 100) || (a % 400))
            maxdia = 29;
        else 
            maxdia = 28;
        break;
        default:
            std::cout << "Mes invalido." << std::endl;
            break;
    }
    dia = dia - 1;
    if (dia == 0)
        dia = maxdia;
    std::cout << "El dia siguiente sera: " << dia << "/" << mes << "/" << a;
    return 0;
    system("pause");
    return 0;
}