#include <iostream>
#include <cstring>

struct Persona
{
    std::string nombre;
    char sexo;
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

void init(Cola &c);
void enqueue(Cola &c, Persona x);
bool empty(Cola c);
Persona dequeue(Cola &c);
void registro(Cola &c);

int main()
{
    Cola mixto, mujer;
    Persona aux;

    init(mixto);
    init(mujer);
    registro(mixto);

    while (!empty(mixto))
    {
        aux = dequeue(mixto);
        if (aux.sexo == 'm')
            enqueue(mujer, aux);
    }

    std::cout << "La cola de mujeres es: " << std::endl;

    while (!empty(mujer))
    {
        aux = dequeue(mujer);
        std::cout << aux.nombre << "    ";
    }
    std::cout << std::endl;
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

void registro(Cola &c)
{
    Persona x;
    int n;

    std::cout << "Digite el numero de elementos: ";
    std::cin >> n;
    std::cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Elemento " << i << std::endl;
        
        std::cout << "Nombre: ";
        std::getline(std::cin, x.nombre);
        std::cout << "Sexo (h/m): ";
        std::cin >> x.sexo;
        std::cin.ignore();
        enqueue(c, x);
    }
}
