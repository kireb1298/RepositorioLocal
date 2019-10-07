#include <iostream>
using namespace std;
int main(){
	float rad,sgmal, aux; // rad= radianes, sgmal= sexagesimal, aux = variable auxiliar
	int grd, min, seg;
	const float PI=3.1416;
	cout << "Ingrese los radianes: ";
	cin >> rad;
	sgmal=rad*180/PI;
	grd=sgmal;
	aux=(sgmal-grd)*60;
	min=aux;
	seg=(aux-min)*60;
	cout << "Grados: " << grd << endl;
	cout << "Minutos: " << min << endl;
	cout << "Segundos: " << seg;
	return 0;
}
