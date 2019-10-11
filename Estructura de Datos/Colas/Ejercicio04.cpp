#include <iostream>

struct Nodo
{
    int info;
    Nodo *sgte;
};
typedef Nodo *PNodo;

struct Cola
{
    PNodo primero;
    PNodo ultimo;
};

void init(Cola &c);
void enqueue(Cola &c, int x);
bool empty(Cola c);
int dequeue(Cola &c);
void registro(Cola &c);

int main()
{
    int numero, aux;
    Cola c;
    init(c);
    registro(c);

    std::cout << "Digite el numero a eliminar: ";
    std::cin >> numero;

    std::cout << "Cola sin " << numero << std::endl;
    while (!empty(c))
    {
        aux = dequeue(c);
        if (aux != numero)
            std::cout << aux << "   ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}

void registro(Cola &c)
{
    int n, x;

    std::cout << "Digite el numero de elementos: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        std::cout << "Elemento " << i << ": ";
        std::cin >> x;
        enqueue(c, x);
    }
}

void init(Cola &C)
{
    C.primero = NULL;
    C.ultimo = NULL;
}

void enqueue(Cola &c, int x)
{
    PNodo nuevo = new Nodo;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (empty(c))
    {
        c.primero = nuevo;
        c.ultimo = nuevo;
    }
    else
    {
        c.ultimo->sgte = nuevo;
        c.ultimo = nuevo;
    }
}

int dequeue(Cola &c)
{
    int x = c.primero->info;
    PNodo temp = c.primero;
    c.primero = c.primero->sgte;
    delete temp;
    return x;
}

bool empty(Cola c)
{
    return (c.primero == NULL) ? true : false;
}