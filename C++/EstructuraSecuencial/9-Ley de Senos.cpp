/*
En todo triangulo se cumple que cada lado es proporcional al seno del angulo opuesto. Esta ley se llama 'ley de los senos'.
a/senA = b/senB = c/senC
Si se conoce los lados a ,b ,c y C ¿Cuanto valen los otros dos angulos? 
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a, b, c, anguloA, anguloB, anguloC, sinA, x; // a=lado1, b=lado2, c=lado3, sinA=Seno de a, x=ArcoSeno
	const float PI = 3.14159265;
	cout << "Ingrese el lado a: ";
	cin >> a;
	cout << "Ingrese el lado b: ";
	cin >> b;
	cout << "Ingrese el lado c: ";
	cin >> c;
	cout << "Ingrese el angulo opuesto a c: ";
	cin >> anguloC;
	sinA = a * sin(anguloC * 2.0 * PI / 360) / c;
	x = asin(sinA);
	anguloA = x * 180 / PI;
	anguloB = 180 - anguloA - anguloC;
	cout << "Los angulos son: " << anguloA << " y " << anguloB << endl;
	return 0;
}