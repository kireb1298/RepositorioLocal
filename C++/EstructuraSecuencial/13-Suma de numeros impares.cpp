//Calcule la siguiente suma: s=1+3+5+7+...+(2n-1)
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, suma; // n = numero de elementos
    cout << "Calcular la siguiente suma: 1+3+5+7+...+(2n-1)";
    cout << "\nIngrese el numero de elementos: ";
    cin >> n;
    suma = pow(n, 2);
    cout << "La suma es: " << suma << endl;
    return 0;
}
