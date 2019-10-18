#include <iostream>
#include <cstring>

struct Nodo
{
    char info;
    Nodo *sgte;
};

typedef Nodo *PNodo;

struct Cola
{
    PNodo primero;
    PNodo ultimo;
};

void init(Cola &c);
void enqueue(Cola &c, char x);
char dequeue(Cola &c);
bool empty(Cola c);

int main()
{
    Cola c;
    init(c);
    int i;
    bool exito = true;
    std::string palabra;
    std::cout << "Ingrese palabra: ";
    std::getline(std::cin, palabra);

    i = palabra.length() - 1;

    while (i != -1)
    {
        enqueue(c, palabra[i]);
        i--;
    }

    i = 0;
    while (!empty(c))
    {
        if (dequeue(c) != palabra[i])
            exito = false;
        i++;
    }

    std::cout << std::endl;

    if (exito == true)
        std::cout << "Es palindromo.";
    else
        std::cout << "No es palindromo.";

    std::cout << std::endl;
    system("pause");
    return 0;
}

void init(Cola &C)
{
    C.primero = NULL;
    C.ultimo = NULL;
}

void enqueue(Cola &C, char x)
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

char dequeue(Cola &C)
{
    char x = C.primero->info;
    PNodo temp = C.primero;
    C.primero = C.primero->sgte;
    delete temp;
    return x;
}

bool empty(Cola c)
{
    return (c.primero == NULL) ? true : false;
}
