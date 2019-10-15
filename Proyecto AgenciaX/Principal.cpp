#include "librerias.h"
#include "funciones.h"

int main()
{
    std::string text;
    std::ifstream comprobar("DATA.dat", std::ios::binary);
    bool band1 = (!comprobar) ? true : false;
    comprobar.close();
    text = (band1) ? "\n\n\n\tNO SE PUDO ENCONTRAR O ABRIR EL ARCHIVO [DATA.dat]" : "\n\n\n\tEL ARCHIVO [DATA.dat] HA SIDO CARGADO CON EXITO...";
    std::cout << text << std::endl;
    system("pause");
    system("cls");

    if (band1)
    {
        AjustarVentana(100, 50);
        instalacion();
    }
    else
    {
        AjustarVentana(100, 30);
        Informacion infoEmpresa;
        Vehiculo maqui, aux;
        Trabajador empleado;
        ColaE infoEmpleado;
        ColaV infoMaqui;
        std::string tt;
        int opc1, opc2;
        init(infoEmpleado);
        init(infoMaqui);

        std::cout << "\n\n\n";
        std::ifstream leerInfo("DATA.dat", std::ios::binary);
        if (!leerInfo)
        {
            std::cout << "FAIL DATA" << std::endl;
            return 1;
        }

        std::ifstream leerMachine("MACHINE.dat", std::ios::binary);
        if (!leerMachine)
        {
            std::cout << "FAIL MACHINE" << std::endl;
            return 1;
        }
        std::cout << "\tEL ARCHIVO [MACHINE.dat] HA SIDO CARGADO CON EXITO..." << std::endl;

        std::ifstream leerEmple("EMPLEADOS.dat", std::ios::binary);
        if (!leerEmple)
        {
            std::cout << "FAIL EMPLEADOS" << std::endl;
            return 1;
        }
        std::cout << "\tEL ARCHIVO [EMPLEADOS.dat] HA SIDO CARGADO CON EXITO..." << std::endl;

        system("pause");

        leerInfo.read((char *)&infoEmpresa, sizeof(Informacion));

        leerMachine.seekg(0, std::ios::beg);
        leerMachine.read((char *)&maqui, sizeof(maqui));
        while (!leerMachine.eof())
        {
            enqueue(infoMaqui, maqui);
            leerMachine.read((char *)&maqui, sizeof(maqui));
        }
        leerEmple.seekg(0, std::ios::beg);
        leerEmple.read((char *)&empleado, sizeof(empleado));

        while (!leerEmple.eof())
        {
            enqueue(infoMaqui, maqui);
            leerEmple.read((char *)&empleado, sizeof(empleado));
        }
        do
        {
            system("cls");
            titulo(infoEmpresa);
            menuMain();
            std::cin >> opc1;
            while (opc1 < 1 || opc1 > 6)
            {
                std::cout << "Digite una opcion valida: ";
                std::cin >> opc1;
            }
            system("cls");
            switch (opc1)
            {
            case 1:
                menuOpcion1(infoEmpresa, empleado);
                std::cout << std::endl;
                system("pause");
                break;

            case 2:
                titulo(infoEmpresa);
                menuOpcion2();
                std::cin >> opc2;
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                }

                switch (opc2)
                {
                case 1:

                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    break;
                }
                break;
            case 3:
                titulo(infoEmpresa);
                menuOpcion3();
                std::cin >> opc2;
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                }
                std::cout << std::endl;
                system("pause");
                break;
            case 4:
                titulo(infoEmpresa);
                menuOpcion4();
                std::cin >> opc2;
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                }
                std::cout << std::endl;
                system("pause");
                break;
            case 5:
                titulo(infoEmpresa);
                menuOpcion5();
                std::cin >> opc2;
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                }
                std::cout << std::endl;
                system("pause");
                break;
            }
        } while (opc1 != 6);
        leerInfo.close();
        leerMachine.close();
        leerEmple.close();
    }
    system("pause");
    return 0;
}