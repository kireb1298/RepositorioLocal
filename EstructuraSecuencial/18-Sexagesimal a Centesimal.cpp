//Grados, minutos y segundos sexagesimales a Centesimales.
#include <iostream>
using namespace std;
int main()
{
	int graS, minS, segS;
	float Sxg, Cnt, aux;
	cout << "Ingrese los grados Sexagesimales: ";
	cin >> graS;
	cout << "Ingrese los minutos Sexagesimales: ";
	cin >> minS;
	cout << "Ingrese los segundos Sexagesimales: ";
	cin >> segS;
	aux = segS / 60;
	aux = minS + aux;
	Sxg = aux / 60 + graS;
	Cnt = Sxg * 200 / 180;
	cout << "Grados Centesimales: " << Cnt;
	return 0;
}
