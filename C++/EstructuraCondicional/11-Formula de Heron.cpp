/*
Muestre un algoritmo que lea tres numeros a,b,c y determine si pueden formar un
triangulo comprobando que p>a,p>b y p>c, donde 'p' es el semiperimetro y equivale a
p=(a+b+c)/2.Luego, calcule el area del triangulo usando la formaula de Heron:
A=sqrt(p(p-a)(p-b)(p-c)).
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, c, p, area; // Lados, semiperimetro, area

	cout << "Ingrese el lado 'a': ";
	cin >> a;
	cout << "Ingrese el lado 'b': ";
	cin >> b;
	cout << "Ingrese el lado 'c': ";
	cin >> c;

	p = (a + b + c) / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));

	if (p > a && p > b && p > c)
	{
		cout << "Se puede formar un triangulo."
			 << "\nEl area del triangulo es: " << area << "cm^2" << endl;
	}

	system("pause");
	return 0;
}
