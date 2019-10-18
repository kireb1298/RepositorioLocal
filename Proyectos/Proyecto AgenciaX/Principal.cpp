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
        Vehiculo maqui, aux[5];
        Trabajador empleado;
        Cliente client;
        Encargo post;
        ColaE infoEmpleado;
        ColaV infoMaqui;
        ColaC infoCliente;
        ColaP infoPost;
        std::string tt;
        int opc1, opc2;
        init(infoEmpleado);
        init(infoMaqui);
        init(infoCliente);
        init(infoPost);

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

        std::ifstream leerCliente("CLIENTE.dat", std::ios::binary);
        if (!leerCliente)
        {
            std::cout << "FAIL CLIENTE" << std::endl;
            return 1;
        }
        std::cout << "\tEL ARCHIVO [CLIENTE.dat] HA SIDO CARGADO CON EXITO..." << std::endl;

        std::ifstream leerEncargo("ENCARGO.dat", std::ios::binary);
        if (!leerEmple)
        {
            std::cout << "FAIL ENCARGO" << std::endl;
            return 1;
        }
        std::cout << "\tEL ARCHIVO [ENCARGO.dat] HA SIDO CARGADO CON EXITO..." << std::endl;

        system("pause");

        leerInfo.read((char *)&infoEmpresa, sizeof(Informacion));

        leerMachine.seekg(0, std::ios::beg);
        leerMachine.read((char *)&maqui, sizeof(Vehiculo));
        while (!leerMachine.eof())
        {
            enqueue(infoMaqui, maqui);
            leerMachine.read((char *)&maqui, sizeof(Vehiculo));
        }

        leerEmple.seekg(0, std::ios::beg);
        leerEmple.read((char *)&empleado, sizeof(Trabajador));
        while (!leerEmple.eof())
        {
            enqueue(infoEmpleado, empleado);
            leerEmple.read((char *)&empleado, sizeof(Trabajador));
        }

        leerCliente.seekg(0, std::ios::beg);
        leerCliente.read((char *)&client, sizeof(Cliente));
        while (!leerCliente.eof())
        {
            enqueue(infoCliente, client);
            leerEmple.read((char *)&client, sizeof(Cliente));
        }

        leerEncargo.seekg(0, std::ios::beg);
        leerEncargo.read((char *)&post, sizeof(Encargo));
        while (!leerEncargo.eof())
        {
            enqueue(infoPost, post);
            leerEncargo.read((char *)&post, sizeof(Encargo));
        }

        leerInfo.close();
        leerMachine.close();
        leerEmple.close();
        leerCliente.close();
        leerEncargo.close();

        do
        {
            system("cls");
            titulo(infoEmpresa);
            menuMain();
            opc1 = 0;
            opc2 = 0;
            std::cin >> opc1;
            fflush(stdin);
            while (opc1 < 1 || opc1 > 7)
            {
                std::cout << "Digite una opcion valida: ";
                std::cin >> opc1;
                fflush(stdin);
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
                fflush(stdin);
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                    fflush(stdin);
                }

                switch (opc2)
                {
                case 1:
                    system("cls");
                    verCola(infoMaqui);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    addVehiculo(infoEmpresa, infoMaqui);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    delVehiculo(infoMaqui);
                    infoEmpresa.nVehiculos--;
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    busVehiculo(infoMaqui);
                    system("pause");
                    break;
                }
                break;
            case 3:
                titulo(infoEmpresa);
                menuOpcion3();
                std::cin >> opc2;
                fflush(stdin);
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                    fflush(stdin);
                }

                switch (opc2)
                {
                case 1:
                    system("cls");
                    verCola(infoEmpleado);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    addEmpleado(infoEmpresa, infoEmpleado);
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    delEmpleado(infoEmpleado);
                    infoEmpresa.nEmpleados--;
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    busEmpleado(infoEmpleado);
                    system("pause");
                    break;
                }
                break;
            case 4:
                titulo(infoEmpresa);
                menuOpcion4();
                std::cin >> opc2;
                fflush(stdin);
                while (opc2 < 1 || opc2 > 6)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                    fflush(stdin);
                }
                switch (opc2)
                {
                case 1:
                    system("cls");
                    verCola(infoCliente);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    addCliente(infoEmpresa, infoCliente);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    delCliente(infoCliente);
                    infoEmpresa.nClientes--;
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    busCliente(infoCliente);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    preferencia(infoCliente);
                    system("pause");
                    break;
                }
                break;
            case 5:
                titulo(infoEmpresa);
                menuOpcion5();
                std::cin >> opc2;
                fflush(stdin);
                while (opc2 < 1 || opc2 > 5)
                {
                    std::cout << "Digite una opcion valida: ";
                    std::cin >> opc2;
                    fflush(stdin);
                }
                switch (opc2)
                {
                case 1:
                    system("cls");
                    verCola(infoPost);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    addEncargo(infoEmpresa, infoPost, infoCliente);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    delEncargo(infoPost);
                    infoEmpresa.nEncargos--;
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    busEncargo(infoPost);
                    system("cls");
                    break;
                }
                break;
            case 6:
                system("cls");
                guardarDatosI(infoEmpresa);
                remove("DATA.dat");
                rename("tempi.dat", "DATA.dat");
                guardarDatosV(infoMaqui);
                remove("MACHINE.dat");
                rename("tempv.dat", "MACHINE.dat");
                guardarDatosE(infoEmpleado);
                remove("EMPLEADOS.dat");
                rename("tempe.dat", "EMPLEADOS.dat");
                guardarDatosC(infoCliente);
                remove("CLIENTE.dat");
                rename("tempc.dat", "CLIENTE.dat");
                guardarDatosP(infoPost);
                remove("ENCARGO.dat");
                rename("tempp.dat", "ENCARGO.dat");
                system("pause");
                break;
            }
        } while (opc1 != 7);
    }
    system("pause");
    return 0;
}