#include <iostream>

struct Nodo
{
    int info;
    int proriedad;
    Nodo *sgte;
};
typedef Nodo *PNodo;

struct Cola
{
    PNodo primero;
    PNodo ultimo;
};

void init(Cola &c);
void enqueue(Cola &c, int x, int pr);
void prority(Cola &c);
bool empty(Cola c);
int dequeue(Cola &c);
void encolarP(Cola &c, int x, int pr); //Encolamiento con prioridad

int main()
{
    Cola c;
    init(c);
    int n, x, pr;

    std::cout << "Numero de elementos: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        std::cout << "Elemento " << i << ": ";
        std::cin >> x;
        std::cout << "Prioridad: ";
        std::cin >> pr;
        encolarP(c, x, pr);
    }

    std::cout << "La cola prioridad es: " << std::endl;

    while (!empty(c))
        std::cout << dequeue(c) << "    ";

    std::cout << std::endl;

    system("pause");
    return 0;
}

void init(Cola &C)
{
    C.primero = NULL;
    C.ultimo = NULL;
}

void enqueue(Cola &c, int x, int pr)
{
    PNodo nuevo = new Nodo;
    nuevo->info = x;
    nuevo->proriedad = pr;
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

void prority(Cola &c)
{
    PNodo aux1, aux2;
    int prAux, infoAux;

    aux1 = c.primero;

    while (aux1->sgte != NULL)
    {
        aux2 = aux1->sgte;

        while (aux2 != NULL)
        {
            if (aux1->proriedad > aux2->proriedad)
            {
                prAux = aux1->proriedad;
                infoAux = aux1->info;

                aux1->proriedad = aux2->proriedad;
                aux1->info = aux2->info;

                aux2->proriedad = prAux;
                aux2->info = infoAux;
            }
            aux2 = aux2->sgte;
        }

        aux1 = aux1->sgte;
    }
}

void encolarP(Cola &c, int x, int pr)
{
    enqueue(c, x, pr);
    prority(c);
}