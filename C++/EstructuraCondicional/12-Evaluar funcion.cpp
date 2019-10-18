/*
Muestre un algoritmo que evalue la funcion
x^2+1		si	x<=0
x^2+3x+2	si	0<x<3
x+1			si	x>=3
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x; //Valor de x

	cout << "x^2+1		si	x<=0"
		 << "\nx^2+3x+2	si	0<x<3"
		 << "\nx+1		si	x>=3" << endl
		 << "\nIngrese 'x': ";
	cin >> x;

	if (x <= 0)
		cout << "F(x)= " << pow(x, 2) + 1 << endl;

	else if (x > 0 && x < 3)
		cout << "F(x)= " << pow(x, 2) + 3 * x + 2 << endl;

	else
		cout << "F(x)= " << x + 1 << endl;

	system("pause");
	return 0;
}
