/*
Escriba un programa que lea un numero de canal de television y diga cual es el nombre
del canal
*/

#include <iostream>

int main()
{
    int canal;
    std::cout << "Digite el numero de un canal tv: (1 al 5)";
    std::cin >> canal;
    switch (canal)
    {
    case 1:
        std::cout << "Estas en el canal America Tv";
        break;
    case 2:
        std::cout << "Estas en el canal Latina";
        break;
    case 3:
        std::cout << "Estas en el canal ATV+";
        break;
    case 4:
        std::cout << "Estas en el canal Panamericana";
        break;
    case 5:
        std::cout << "Estas en el canal CableVision";
        break;
    default:
        std::cout << "Canal invalido";
        break;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}