// Calcule el area de un trapecio cuyas base menor, base mayor y altura son conocidas
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	float baseMenor, baseMayor, h, a;
	cout << "Ingrese la base menor: ";
	cin >> baseMenor;
	cout << "Ingrese la base mayor: ";
	cin >> baseMayor;
	cout << "Ingrese la altura: ";
	cin >> h;
	a = ((baseMayor + baseMenor) / 2) * h;
	cout << "El area del trapecio es: " << a << endl;
	return 0;
}
