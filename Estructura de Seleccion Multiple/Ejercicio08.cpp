/*
En una empresa comercial existen tres categorias de articulos(A, B y C) y cuatro 
categorias de clientes (excelentes, buenos, regulares y malos). Ademas, tiene implementada 
la siguiente politica de descuentos (en porcentaje):

Tipo de Cliente          \           Tipo de articulo
                                        A   B   C
E: Excelente                            40  30  20
B: Bueno                                30  20  10
R: Regular                              20  10  0
M: Malo                                 0   0   0

Asi mismo, se sabe que los clientes de tipo E y B pueden pagar en efectivo, con cheque 
o al credito, los dos tipo R solo pueden hacerlo en efectivo o con cheque, mientras que 
los de tipo M solo pueden hacer compras en efectivo. Lea el tipo de cliente, el tipo
de articulo que desea adquirir e indique el descuento y las alternativas de pago que le 
son permitidas
*/

#include <iostream>

int main()
{
    char tipoCliente;
    char tipoArticulo;
    std::cout
        << "Tipos de Cliente (e: excelente / b: bueno / r: regular / m: malo)"
        << "Ingrese el tipo de cliente:";
    std::cin >> tipoCliente;
    std::cout << "Ingrese el tipo de articulo que desea comprar (a, b, c): ";
    std::cin >> tipoArticulo;
    switch (tipoCliente)
    {
    case 'e':
        std::cout << "Usted puede pagar con efectivo, con cheque o al credito.";
        switch (tipoArticulo)
        {
        case 'a':
            std::cout << "Tiene un 40% de descuento en este producto.";
            break;
        case 'b':
            std::cout << "Tiene un 30% de descuento en este producto.";
            break;
        case 'c':
            std::cout << "Tiene un 20% de descuento en este producto.";
            break;
        default:
            std::cout << "Tipo de Articulo invalido.";
            break;
        }
        break;
    case 'b':
        std::cout << "Usted puede pagar con efectivo, con cheque o al credito.";
        switch (tipoArticulo)
        {
        case 'a':
            std::cout << "Tiene un 30% de descuento en este producto.";
            break;
        case 'b':
            std::cout << "Tiene un 20% de descuento en este producto.";
            break;
        case 'c':
            std::cout << "Tiene un 10% de descuento en este producto.";
            break;
        default:
            std::cout << "Tipo de Articulo invalido.";
            break;
        }
        break;
    case 'r':
        std::cout << "Usted puede pagar con efectivo o cheque ";
        switch (tipoArticulo)
        {
        case 'a':
            std::cout << "Tiene un 20% de descuento en este producto.";
            break;
        case 'b':
            std::cout << "Tiene un 10% de descuento en este producto.";
            break;
        case 'c':
            std::cout << "No tiene descuento.";
            break;
        default:
            std::cout << "Tipo de Articulo invalido.";
            break;
        }
        break;
    case 'm':
        std::cout << "Usted puede pagar con efectivo.";
        switch (tipoArticulo)
        {
        case 'a':
        case 'b':
        case 'c':
            std::cout << "No tiene descuento.";
            break;
        default:
            std::cout << "Tipo de Articulo invalido.";
            break;
        }
        break;

    default:
    std::cout << "Tipo de Cliente invalido.";
        break;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}