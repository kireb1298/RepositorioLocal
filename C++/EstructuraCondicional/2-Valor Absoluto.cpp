//Obtenga el valor absoluto de un numero
#include <iostream>
using namespace std;
int main()
{
	float n;
	cout << "Ingrese el numero: ";
	cin >> n;
	if (n >= 0)
		cout << "El valor absoluto es: " << n;
	else
		cout << "El valor absoluto es: " << -1 * n;
	return 0;
}
