#include <iostream>
#include <cstring>

struct Persona
{
    std::string nombre;
    int edad;
};

struct Nodo
{
    Persona info;
    Nodo *sgte;
};
typedef Nodo *PNodo;

struct Cola
{
    PNodo primero;
    PNodo ultimo;
};

void init(Cola &C);
void enqueue(Cola &C, Persona x);
bool empty(Cola C);
Persona dequeue(Cola &C);

int main()
{
    Cola c;
    init(c);
    Persona x, aux;
    int n, menorEdad = 0, cant = 0;
    float ganancia;

    std::cout << "Digite el numero de personas en la cola: ";
    std::cin >> n;
    std::cout << "Digite el precio de entrada: ";
    std::cin >> ganancia;

    for (int i = 1; i <= n; i++)
    {
        std::cout << "Elemento " << i << std::endl;
        std::cin.ignore();
        std::cout << "Nombre: ";
        std::getline(std::cin, x.nombre);
        std::cout << "edad: ";
        std::cin >> x.edad;
        if (x.edad >= 18)
            enqueue(c, x);
        else
            menorEdad++;
    }

    while (!empty(c))
    {
        aux = dequeue(c);
        cant++;
    }

    ganancia *= cant;

    std::cout
        << "Menores de edad que no igresaron: " << menorEdad << "\n"
        << "Ganancia Total: " << ganancia << "$" << std::endl;

    system("pause");
    return 0;
}

void init(Cola &C)
{
    C.primero = NULL;
    C.ultimo = NULL;
}

void enqueue(Cola &C, Persona x)
{
    PNodo nuevo = new Nodo;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(C))
    {
        C.primero = nuevo;
        C.ultimo = nuevo;
    }
    else
    {
        C.ultimo->sgte = nuevo;
        C.ultimo = nuevo;
    }
}

Persona dequeue(Cola &C)
{
    Persona x = C.primero->info;
    PNodo temp = C.primero;
    C.primero = C.primero->sgte;
    delete temp;
    return x;
}

bool empty(Cola c)
{
    return (c.primero == NULL) ? true : false;
}