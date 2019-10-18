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

int main()
{
    Cola c;
    init(c);
    int n, x;
    std::cout << "Digite un numero: ";
    std::cin >> n;
    while (n > 0)
    {
        enqueue(c, n % 10);
        n /= 10;
    }
    std::cout << "Al reves se escribe: ";
    while (!empty(c))
    {
        x = dequeue(c);
        std::cout << x;
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

void enqueue(Cola &C, int x)
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

int dequeue(Cola &C)
{
    int x = C.primero->info;
    PNodo temp = C.primero;
    C.primero = C.primero->sgte;
    delete temp;
    return x;
}

bool empty(Cola c)
{
    return (c.primero == NULL) ? true : false;
}