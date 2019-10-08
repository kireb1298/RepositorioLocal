//¿Cual es el volumen de un paralelepipedo de largo, ancho y altura conocidos?
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	float largo, ancho, h, a; // h = altura, a = area
	cout << "Ingrese el valor del largo: ";
	cin >> largo;
	cout << "Ingrese el valor del ancho: ";
	cin >> ancho;
	cout << "Ingrese el valor de la altura: ";
	cin >> h;
	a = 2 * largo * ancho + 2 * largo * h + 2 * ancho * h;
	cout << "El area del paralelepipedo es: " << a << endl;
	return 0;
}
