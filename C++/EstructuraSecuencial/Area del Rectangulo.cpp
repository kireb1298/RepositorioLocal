//Area del rectangulo
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	float h, b, p;
	cout << "Ingrese la altura: ";
	cin >> h;
	cout << "Ingrese la base: ";
	cin >> b;
	p = h * 2 + b * 2;
	cout << "El perimetro del rectangulo es: " << p << endl;
	return 0;
}
