#include <iostream>
#include <math.h>
using namespace std;
int main(){
int n, suma; // n = numero de elementos
cout << "Calcular la siguiente suma: 1+3+5+7+...+(2n-1)";
cout << "\nIngrese el numero de elementos: ";
cin >> n;
suma= pow(n,2);
cout << "La suma es: " << suma;
return 0;
}
