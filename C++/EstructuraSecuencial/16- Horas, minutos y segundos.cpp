//Lea la hora y diga a cuantas horas, minutos y segundos equivale
#include <iostream>
using namespace std;
int main()
{
	float cantidad, aux;
	int h, m, s;
	cout << "Ingrese la cantidad de horas: ";
	cin >> cantidad;
	h = cantidad;
	aux = (cantidad - h) * 60;
	m = aux;
	s = (aux - m) * 60;
	cout << "Horas: " << h << endl;
	cout << "Minutos: " << m << endl;
	cout << "Segundos: " << s << endl;
	return 0;
}
