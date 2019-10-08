// Calcule la siguiente suma: s=1*2+2*3+3*4+...+n*(n+1)
#include <iostream>
using namespace std;
int main()
{
	int n, suma; // n = numero de elementos, op1= el primer sumando
	cout << "Calcular la suma de 1*2+2*3+3*4+...+n*(n+1)";
	cout << "\nIngrese n: ";
	cin >> n;
	suma = (n*(n+1)*(n+2))/3;
	cout << "La suma es: " << suma << endl;
	return 0;
}
