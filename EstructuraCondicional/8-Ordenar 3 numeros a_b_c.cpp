//Ordene 3 numeros 'a', 'b' y 'c' de tal manera que 'a' siempre sea el mayor, 'b' el intermedio y 'c' el menor.
#include <iostream>
using namespace std;
int main()
{
	float n1, n2, n3, a, b, c;
	cout << "Ingrese el primer numero: ";
	cin >> n1;
	cout << "Ingrese el segundo numero: ";
	cin >> n2;
	cout << "Ingrese el tercer numero: ";
	cin >> n3;
	if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		a = n1;
		b = n2;
		c = n3;
	}
	else if (n1 > n2 && n1 > n3 && n3 > n2)
	{
		a = n1;
		b = n3;
		c = n2;
	}
	else if (n2 > n1 && n2 > n3 && n1 > n3)
	{
		a = n2;
		b = n1;
		c = n3;
	}
	else if (n2 > n1 && n2 > n3 && n3 > n1)
	{
		a = n2;
		b = n3;
		c = n1;
	}
	else if (n3 > n1 && n3 > n2 && n2 > n1)
	{
		a = n3;
		b = n2;
		c = n1;
	}
	else if (n3 > n1 && n3 > n2 && n1 > n2)
	{
		a = n3;
		b = n1;
		c = n2;
	}
	else
		cout << "No se puede ordenar";
	cout << "el orden es: " << a << " " << b << " " << c << endl;
	return 0;
}
