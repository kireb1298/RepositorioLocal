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
void eComun(Cola &a, Cola &b);

int main()
{
    Cola a, b;
    init(a);
    init(b);
    std::cout << "Elementos de la cola 1" << std::endl;
    registro(a);
    std::cout << "Elementos de la cola 2" << std::endl;
    registro(b);
    std::cout << "Elementos en Comun:" << std::endl;
    eComun(a,b);
    std::cout << std::endl;
    system("pause");
    return 0;
}

void registro(Cola &c)
{
    int n, x;

    std::cout << "Digite el numero de elementos: ";
    std::cin >> n;

    for(int i = 1; i<=n; i++)
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

void eComun(Cola &a, Cola &b)
{
    int elemento;
    PNodo aux1, aux2;
    aux1 = a.primero;

    while (aux1 != NULL)
    {
        aux2 = b.primero;
        while (aux2 != NULL)
        {
            if(aux1->info == aux2->info)
                std::cout << aux1->info << "    ";

            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
}