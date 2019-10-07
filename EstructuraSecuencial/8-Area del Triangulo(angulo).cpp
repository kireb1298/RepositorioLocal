#include <iostream>
using namespace std;
int main(){
	float b, c, angulo, A; // b = lado1, c = lado2, A = area
	const float PI = 3.14159265;
	cout << "Ingrese un lado del triangulo: ";
	cin >> b;
	cout << "Ingrese otro lado del triangulo: ";
	cin >> c;
	cout << "Ingrese el angulo: ";
	cin >> angulo;
	A = (b*c*(sin(angulo*2.0*PI/360))) / 2; //se multipica por pi porque el angulo esta en radianes, para pasarlo a sexagesimal
	cout << "El area del triangulo es: " << A << endl;
	return 0;
}
