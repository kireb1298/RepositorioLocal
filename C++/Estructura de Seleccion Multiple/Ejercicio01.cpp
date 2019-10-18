//Si las volcales se representan con numeros del 1 al 5, lea un numero y diga que vocal es.
#include <iostream>

int main()
{
    int n;
    std::cout << "Digite un numero del 1 al 5: ";
    std::cin >> n;
    switch (n)
    {
    case 1:
        std::cout << "La vocal es \'a\'";
        break;
    case 2:
        std::cout << "La vocal es \'e\'";
        break;
    case 3:
        std::cout << "La vocal es \'i\'";
        break;
    case 4:
        std::cout << "La vocal es \'o\'";
        break;
    case 5:
        std::cout << "La vocal es \'u\'";
        break;
    default:
        std::cout << "Numero invalido.";
        break;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}