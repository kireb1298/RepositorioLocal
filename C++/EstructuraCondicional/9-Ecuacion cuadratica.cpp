/*
Elabore un algoritmo que obtenga la raices de una ecuacion de segundo grado. 
En caso de tener raices imaginarias, calculelas y muestrelas.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;		// Constantes de la ecuacion
	int dc;				// Discriminante
	float x1, x2, i, x; // Resultados de la ecuacion

	cout << "ax^2 + bx + c" << endl;

	cout << "Ingrese a: ";
	cin >> a;
	cout << "Ingrese b: ";
	cin >> b;
	cout << "Ingrese c: ";
	cin >> c;

	dc = pow(b, 2) - 4 * a * c;

	if (dc > 0)
	{

		x1 = (-b + sqrt(dc)) / 2 * a;
		x2 = (-b - sqrt(dc)) / 2 * a;
		x1 = x1 * x1;
		x2 = x2 * x2;

		cout << "X1: V" << x1 << endl;
		cout << "X2: V" << x2 << endl;
	}
	else if (dc == 0)
	{
		x1 = -b / 2 * a;
		x1 = x1 * x1;

		cout << "X: V" << x1 << endl;
	}
	else if (dc < 0)
	{
		x = -b / 2 * a;
		i = (sqrt(-dc)) / 2 * a;

		cout << "X1: -" << b << "+V" << dc << ")/" << 2 * a << "	" << x << " + " << i << "i" << endl;
		cout << "X2: -" << b << "-V(" << dc << ")/" << 2 * a << "	" << x << " - " << i << "i" << endl;
	}

	system("pause");
	return 0;
}
