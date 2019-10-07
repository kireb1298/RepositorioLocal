#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	float c1, c2, h, p; // c1 = cateto1, c2 = cateto2, h = hipotenusa, p = perimetro
	cout << "Ingrese el valor del cateto 1: ";
	cin >> c1;
	cout << "Ingrese el valor del cateto 2: ";
	cin >> c2;
	h = sqrt(pow(c1,2)+pow(c2,2));
	p = c1 + c2 + h;
	cout << "El perimetro es p: " << p << endl;
	return 0;
}

