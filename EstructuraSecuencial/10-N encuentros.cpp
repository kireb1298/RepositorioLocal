#include <iostream>
using namespace std;
int main(){
	int nEquipos, nEncuentros;
	cout << "Ingrese el numero de equipos: ";
	cin >> nEquipos;
	nEncuentros = nEquipos/2;
	if (nEncuentros%2 == 0){
		cout << "El numero de encuentros son: " << nEncuentros << endl;
	}else {
		cout << "El numero de encuentros son: " << nEncuentros << " y un equipo se queda sin rival";
	}
	return 0;
}
