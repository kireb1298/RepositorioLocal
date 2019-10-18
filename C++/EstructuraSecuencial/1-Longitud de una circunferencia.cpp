// Calcule la longitud de una circunferencia de radio conocido.
#include <iostream>
//#define PI 3.1416; Definimos una constante llamada PI
using namespace std;

int main(int argc, char *argv[])
{
	float radio, longitud;
	const float PI = 3.1416; // Aca se aplica la constante PI
	cout << "Ingrese el radio de la circunferencia: ";
	cin >> radio;
	longitud = 2 * (radio)*PI;
	cout << "la longitud es " << longitud << endl;
	return 0;
}
