#include <iostream>
using namespace std;
int main(){
	float a, b, c, d ,e;
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
	cout << "Ingrese el tercer numero: ";
	cin >> c;
	cout << "Ingrese el cuarto numero: ";
	cin >> d;
	cout << "Ingrese el quinto numero: ";
	cin >> e;
	if (a<b && b<c && c<d && d<e) cout << "Estan ordenados ascendentemente";
	else cout << "No estan ordenados ascendentemente";
	return 0;
}