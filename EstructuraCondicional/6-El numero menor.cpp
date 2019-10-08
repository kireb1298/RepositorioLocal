//Sin usar estructuras repetitivas leer 5 numeros y determine el menor.
#include <iostream>
using namespace std;
int main()
{
	float a, b, c, d, e;
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
	cout << "Ingrese el tercer numero: ";
	cin >> c;
	cout << "Ingrese el cuarto numero: ";
	cin >> d;
	cout << "Ingrese el quinto numero: ";
	cin >> e;

	if (a < b && a < c && a < d && a < e)
		cout << "El menor numero es: " << a;
	else if (b < a && b < c && b < d && b < e)
		cout << "El menor numero es: " << b;
	else if (c < a && c < b && c < d && c < e)
		cout << "El menor numero es: " << c;
	else if (d < a && d < b && d < c && d < e)
		cout << "El menor numero es: " << d;
	else if (e < a && e < b && e < c && e < d)
		cout << "El menor numero es: " << e;
	else
		cout << "No existe un solo numero menor.";

	cout << endl;
	return 0;
}
