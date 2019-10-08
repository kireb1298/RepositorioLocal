//Convertir Grados Celsius, Farenheit y Rankine a Kelvin.
#include <iostream>
using namespace std;
int main()
{
	float kc, kf, kr, C, F, R; //k(c-f-r)= Kelvin, C= Celsius, F=Farenheit, R = Rankine
	cout << "Convertir grados Celsius, Farenheit y Rankine a Kelvin";
	cout << "\n--------------------------------------------------------";
	cout << "\nIngrese los grados Celsius que desee convertir: ";
	cin >> C;
	cout << "Ingrese los grados Farenheit que desee convertir: ";
	cin >> F;
	cout << "Ingrese los grados Rankine que desee convertir: ";
	cin >> R;
	kc = C + 273;
	kf = (F - 32) * 5 / 9 + 273;
	kr = R * 5 / 9;
	cout << "Conversion a Kelvin";
	cout << "\n--------------------";
	cout << "\nGrados Celsius: " << kc << endl;
	cout << "Grados Farenheit: " << kf << endl;
	cout << "Grados Rankine: " << kr << endl;
	return 0;
}
