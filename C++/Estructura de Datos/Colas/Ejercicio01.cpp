#include <iostream>
using namespace std;

struct Doncella
{
    char nombre[40];
    int talla;
};

struct Nodo
{
    Doncella info;
    Nodo *sgte;
};

typedef Nodo *PNodo;

struct Cola
{
    PNodo primero;
    PNodo ultimo;
};

void inicializar(Cola &C);
void encolar(Cola &C, Doncella x);
Doncella desencolar(Cola &C);

int main(int argc, char *argv[])
{
    Cola C;
    inicializar(C);
    int n, i, talla;
    Doncella x;
    cout << "Numero de doncellas: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "Doncella " << i << endl;
        cout << "Nombre: ";
        cin >> x.nombre;
        cout << "talla: ";
        cin >> x.talla;
        encolar(C, x);
    }

    cout << "Talla de la cenicienta: ";
    cin >> talla;
    bool enc = false;
    while (C.primero != NULL && enc == false)
    {
        x = desencolar(C);
        if (x.talla == talla)
        {
            cout << "La cenicienta se llama " << x.nombre << endl;
            enc = true;
        }
    }
    if (enc == false)
        cout << "La cencienta no salio, tuvo miedo " << endl;

    return 0;
}

void inicializar(Cola &C)
{
    C.primero = NULL;
    C.ultimo = NULL;
}
void encolar(Cola &C, Doncella x)
{
    PNodo nuevo = new Nodo;
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (C.primero == NULL && C.ultimo == NULL)
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
Doncella desencolar(Cola &C)
{
    Doncella x = C.primero->info;
    PNodo temp = C.primero;
    C.primero = C.primero->sgte;
    delete temp;
    return x;
}