/*
Dadas tres longitudes, comprube si pueden formar un triangulo y luego clasifique el triangulo segun sus angulos
(acutangulo, rectangulo y obtusangulo).
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, c;

	cout << "Ingrese el lado 'a': ";
	cin >> a;
	cout << "Ingrese el lado 'b': ";
	cin >> b;
	cout << "Ingrese el lado 'c': ";
	cin >> c;

	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		cout << "Si se puede formar un triangulo" << endl;
		if (a >= b && a >= c)
		{
			if (pow(a, 2) < (pow(b, 2) + pow(c, 2)))
			{
				cout << "Es un triangulo acutangulo." << endl;
			}
			if (pow(a, 2) == (pow(b, 2) + pow(c, 2)))
			{
				cout << "Es un triangulo rectangulo." << endl;
			}
			if (pow(a, 2) > (pow(b, 2) + pow(c, 2)))
			{
				cout << "Es un triangulo obtusangulo." << endl;
			}
		}
		else if (b >= a && b >= c)
		{
			if (pow(b, 2) < (pow(a, 2) + pow(c, 2)))
			{
				cout << "Es un triangulo acutangulo." << endl;
			}
			if (pow(b, 2) == (pow(a, 2) + pow(c, 2)))
			{
				cout << "Es un triangulo rectangulo." << endl;
			}
			if (pow(b, 2) > (pow(a, 2) + pow(c, 2)))
			{
				cout << "Es un triangulo obtusangulo." << endl;
			}
		}
		else if (c >= a && c >= b)
		{
			if (pow(c, 2) < (pow(a, 2) + pow(b, 2)))
			{
				cout << "Es un triangulo acutangulo." << endl;
			}
			if (pow(c, 2) == (pow(a, 2) + pow(b, 2)))
			{
				cout << "Es un triangulo rectangulo." << endl;
			}
			if (pow(c, 2) > (pow(a, 2) + pow(b, 2)))
			{
				cout << "Es un triangulo obtusangulo." << endl;
			}
		}
	}

	else
	{
		cout << "No se puede formar un triangulo." << endl;
	}

	system("pause");
	return 0;
}
