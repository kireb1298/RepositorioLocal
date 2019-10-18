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
bool emptyP(PNodo p);
bool emptyC(Cola c);
int dequeue(Cola &c);
void registroC(Cola &c, int n);
void registroP(PNodo &p, int n);
void push(PNodo &p, int x);
int pop(PNodo &p);

int main()
{
    unsigned int n;
    bool exito = true;
    Cola c;
    PNodo p = NULL;
    init(c);

    do
    {
        std::cout << "Digite un numero valido: ";
        std::cin >> n;
    } while (n < 9);

    registroP(p, n);
    registroC(c, n);

    while (!emptyP(p))
    {
        if (dequeue(c) != pop(p))
            exito = false;
    }

    if (exito)
        std::cout << "El numero es capicua.";
    else
        std::cout << "El numero no es capicua.";

    std::cout << std::endl;
    system("pause");
    return 0;
}

void registroC(Cola &c, int n)
{
    int x = n;
    while (x > 0)
    {
        enqueue(c, x % 10);
        x /= 10;
    }
}

void registroP(PNodo &p, int n)
{
    int x = n;
    while (x > 0)
    {
        push(p, x % 10);
        x /= 10;
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
    if (emptyC(c))
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

bool emptyP(PNodo p)
{
    return (p == NULL) ? true : false;
}

bool emptyC(Cola c)
{
    return (c.primero == NULL) ? true : false;
}

void push(PNodo &p, int x)
{
    PNodo nuevo;
    nuevo = new Nodo;
    nuevo->info = x;
    nuevo->sgte = p;
    p = nuevo;
}

int pop(PNodo &p)
{
    int x = p->info;
    PNodo temp = p;
    p = p->sgte;
    delete (temp);
    return x;
}