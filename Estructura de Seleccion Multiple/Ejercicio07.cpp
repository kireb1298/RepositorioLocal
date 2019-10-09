/*
Muestre las opciones de un menu, seleccione una opcion e imprima el mensaje 
apropiado indicando la opcion seleccionado
*/

#include <iostream>

int main()
{
    int opcion;
    std::cout
        << "-------- MENU --------"
        << "\n1. Pedir Saludo."
        << "\n2. Bailar."
        << "\n3. Comer."
        << "\n4. Saltar."
        << "\n5. Despedirse"
        << "\n\nEscoja un opcion: ";
    std::cin >> opcion;
    switch (opcion)
    {
    case 1:
        std::cout << "Hola sujeto que esta viendo la consola.";
        break;
    case 2:
        std::cout << "Estoy bailando.";
        break;
    case 3:
        std::cout << "Estoy comiendo.";
        break;
    case 4:
        std::cout << "Estoy saltando.";
        break;
    case 5:
        std::cout << "Adios sujeto que observa la consola.";
        break;

    default:
        std::cout << "Opcion invalida.";
        break;
    }

    system("pause");
    return 0;
}