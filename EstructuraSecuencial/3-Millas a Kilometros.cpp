#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float m, k; //m = millas, k = kilometros
	const float MILLA = 1.609; // 1 milla = 1.609 kilometros
	cout << "Ingrese la cantidad de millas: ";
	cin >> m;
	k = m*MILLA;
	cout << m << " Contiene " << k << " kilometros.";  
	return 0;
}

