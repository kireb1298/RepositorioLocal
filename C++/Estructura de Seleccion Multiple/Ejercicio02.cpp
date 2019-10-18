/*
Lea un numero que represente el dia de la semana y diga que dia es,
teniendo en cuenta que la semana comienza el domingo.
*/

#include <iostream>

int main()
{
    int n;
    std::cout << "Digite un numero del 1 al 7: ";
    std::cin >> n;
    switch (n)
    {
    case 1:
        std::cout << "El dia representa a Domingo.";
        break;
    case 2:
        std::cout << "El dia representa a Lunes.";
        break;
    case 3:
        std::cout << "El dia representa a Martes.";
        break;
    case 4:
        std::cout << "El dia representa a Miercoles.";
        break;
    case 5:
        std::cout << "El dia representa a Jueves.";
        break;
    case 6:
        std::cout << "El dia representa a Viernes.";
        break;
    case 7:
        std::cout << "El dia representa a Sabado.";

    default:
        std::cout << "Numero invalido.";
        break;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}