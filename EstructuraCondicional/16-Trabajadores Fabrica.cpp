/*
Los trabajadores de una fabrica tienen tres turnos: mañana, tarde y noche. La tarifa de
los turnos de mañana y tarde son iguales, mientras que de noche son 30 por ciento mayores.
Construya un programa que lea el numero de horas laboradas por un trabajador y su tarifa.
Calcule el salario semanal. Considere que durante la semana el trabajador se encuentra
siempr el mismo turno.
*/

#include <iostream>
using namespace std;

int main(){
	float h, t, op;
	
	cout<<	"1.Manana\n"<<
			"2.Tarde\n"<<
			"3.Noche\n";
	do{
		cout<<"Digite el numero del turno a cual pertenesca: ";
		cin>>op;
	}while(op<1 || op>3);
	cout<<"Digite el numero de horas trabajadas: ";
	cin>>h;
	cout<<"Digite el precio de la tarifa por hora: ";
	cin>>t;
	
	if(op==1 || op==2){
		cout<<"Su salario semanal es: "<<(h*t)*7<<" soles."<<endl;
	}
	else cout<<"Su salario semanal es: "<<(h*(t+(t*0.3)))*7<<" soles."<<endl;
	
	system("pause");
	return 0;
}
