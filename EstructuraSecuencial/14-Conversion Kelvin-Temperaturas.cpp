//Convertir Grados kelvin a Celsius, Farenheit y Rankine.
#include <iostream>
using namespace std;
int main()
{
	float K, C, F, R; //K= Kelvin, C= Celsius, F=Farenheit, R = Rankine
	cout << "Convertir grados Kelvin a Celsius, Farenheit y Rankine";
	cout << "Ingrese los grados Kelvin que desee convertir: ";
	cin >> K;
	C = K - 273;
	F = (K - 273) * 9 / 5 + 32;
	R = K * 1.8;
	cout << "Grados Celsius: " << C << endl;
	cout << "Grados Farenheit: " << F << endl;
	cout << "Grados Rankine: " << R << endl;
	return 0;
}