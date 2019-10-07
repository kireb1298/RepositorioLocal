/*
A un trabajador se le paga una tarifa fija las horas normales de labores. Se consideran
horas normales a todas las horas trabajadas hasta un total de 140 al mes. Las horas
adicionales a 140 se consideran extras. Por una hora extra se paga el equivalente a 1.5
horas normales. Los impuestos varian segun el monto obtenido por el trabajador. Si el
sueldo es menor o igual a 2000 nuevos soles y no paga impuestos, por los siguientes 
2000 nuevos soles paga el 10 por ciento, mientras que para montos mayores a 4000
nuevos soles paga el 15 por ciento sobre el adicional, ¿cual es el suelo neto del trabajador
y cual es el monto en impuestos que debe pagar?
*/

#include <iostream>

using namespace std;

int main(){
	int h, he; // horas
	float trfa, sldo; // tarifa y suelo
	
	cout<<"Digite el numero de horas normales trabajadas: ";
	cin>>h;
	cout<<"Digite el precio de la tarifa por hora: ";
	cin>>trfa;
	
	if(h>140){
		he=h-140;
		sldo=140*trfa+(trfa*1.5)*he;
	}else sldo=h*trfa;
	
	if(sldo<=2000)
		cout<<"Su salario neto es s/."<<sldo<<" sin impuestos"<<endl;
	
	else if(sldo>2000 && sldo<=4000)
		cout<<"Su salario neto es s/."<<sldo*0.9<<" y su impuesto fue s/."<<sldo*0.1<<endl;
	
	else cout<<"Su salario neto es s/."<<sldo*0.85<<" y su impuesto fue s/."<<sldo*0.15<<endl;
		
	system("pause");
	return 0;
}
