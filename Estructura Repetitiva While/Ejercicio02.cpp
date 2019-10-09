//Encuentre el 'mcm' de dos numeros 'a' y 'b' sabiendo que (a)(b) = (mcm)(mcd)

#include <iostream>

int main()
{
    int a, b, aux, mcd, mcm, temp1, temp2;
    std::cout << "Digite el numero (a): ";
    std::cin >> a;
    std::cout << "Digite el numero (b): ";
    std::cin >> b;

    if (a > b)
    {
        temp1 = a;
        temp2 = b;
    }
    else if (a < b)
    {
        temp1 = b;
        temp2 = a;
    }
    else
    {
        std::cout << "Los 2 numeros son iguales." << std::endl;
        return 0;
    }
    while (temp2 != 0)
    {
        aux = temp1 % temp2;
        temp1 = temp2;
        temp2 = aux;
    }
    mcd = temp1;
    mcm = (a * b) / mcd;
    std::cout << "El minimo comun multiplo de " << a << " y " << b << " es " << mcm << "." << std::endl;
    system("pause");
    return 0;
    }