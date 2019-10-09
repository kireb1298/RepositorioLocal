/*
Un alumno es calificado con 'a', 'b','c' o 'd'. Sera bueno su obtuvo un 'a', regular si obtuvo un
'b', malo si obtuvo un 'c', y pesimo si obtuvo un 'd'. Lea un calificativo y escriba que tipo
de alumno es.
*/

#include <iostream>

int main()
{
    char cal; //calificativo
    std::cout << "Digite el calificativo: (a, b, c, d)";
    std::cin >> cal;
    switch (cal)
    {
    case 'a':
        std::cout << "Su calificativo es bueno.";
        break;
    case 'b':
        std::cout << "Su calificativo es regular.";
        break;
    case 'c':
        std::cout << "Su calificativo es malo.";
        break;
    case 'd':
        std::cout << "Su calificativo es pesimo.";
        break;
    default:
        std::cout << "Calificativo invalido.";
        break;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}