//Calcule la suma de los n primeros numeros pares.
#include <iostream>
using namespace std;
int main()
{
	int n, suma; // n=numero de elementos
	cout << "Suma de n primeros numeros pares";
	cout << "\n-------------------------------";
	cout << "\nIngresar numero: ";
	cin >> n;
	suma = n * (n + 1);
	cout << "La suma es: " << suma << endl;
	return 0;
}
