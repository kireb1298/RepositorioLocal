/*
Todo el mundo sabe cuantos annos tiene, pero ¿podria contestar a la pregunta cuantos dias tiene?
*/
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
