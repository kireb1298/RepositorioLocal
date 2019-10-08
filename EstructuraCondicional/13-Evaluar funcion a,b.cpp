/*
Lea dos enteros 'a','b' y obtenga el valor de la funcion
2a+b	si	a^2-b^2<0
a^2-2b	si	a^2-b^2=0
a+b		si	a^2-b^2>0
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, aux;

	cout << "2a+b	si	a^2-b^2<0\n"
		 << "a^2-2b	si	a^2-b^2=0\n"
		 << "a+b	si	a^2-b^2>0\n"
		 << "\nIngrese 'a': ";
	cin >> a;
	cout << "Ingrese 'b': ";
	cin >> b;

	aux = pow(a, 2) - pow(b, 2);

	if (aux < 0)
		cout << "F(x)= " << 2 * a + b << endl;

	else if (aux == 0)
		cout << "F(x)= " << pow(a, 2) - 2 * b << endl;

	else
		cout << "F(x)= " << a + b << endl;

	system("pause");
	return 0;
}
