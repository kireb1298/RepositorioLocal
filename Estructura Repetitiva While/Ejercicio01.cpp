/*
El factorial de un numero se define como el producto de todos los numeros consecutivos 
desde la unidad hasta el numero y se denota por el simobolo '!'. Por ejemplo, 
!4 = 4x3x2x1. Teniendo en cuenta esto, lea un numero y encuentre su factorial. 
*/

#include <iostream>

int main()
{
    int numero, cont;
    unsigned long int factorial = 1; //unsigned long es agregado para que admita una mayor cantidad de numeros	
    std::cout
        << "Programa para obtener el factorial de un numero." 
        << "\nDigite un numero: ";
    std::cin >> numero;

    cont = numero;

    while(cont != 1)
    {
        factorial *= cont;
        cont--; 
    }

    std::cout << "El factorial de " << numero << " es " << factorial << std::endl;
}