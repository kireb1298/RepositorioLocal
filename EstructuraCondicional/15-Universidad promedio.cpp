/*
Una universidad tiene como politica considerar tres notas en cada curso: la nota de
trabajo 'T', la nota del examen de medio ciclo 'M' y el examen de fin de ciclo 'F'. Cada
una tiene un peso de 50, 20 y 30 por ciento, respectivamente. Un alumno es clasificado
segun lo siguiente:

Bueno: si su promedio esta entre 16 y 20.
Regular: si su promedio esta entre 11 y 15.
Malo: si su promedio esta entre 6 y 10.
Pesimo: si su promedio esta entre 0 y 5.

Escriba un algoritmo que lea tres notas de un alumno y en un curso, y en un curso, y diga como
ha sido clasificado el alumno
*/
#include <iostream>

using namespace std;

int main(){
	float t, m, f, p;
	
	cout<<"Ingrese las 3 notas con numeros del 0 al 20.\n";
	do{
		cout<<"Ingrese nota 'T': ";
		cin>>t;
	}while(t<0 || t>20);
	do{
		cout<<"Ingrese nota 'M': ";
		cin>>m;
	}while(m<0 || m>20);
	do{
		cout<<"Ingrese nota 'F': ";
		cin>>f;
	}while(f<0 || f>20);
	
	t=t*0.5;
	m=m*0.2;
	f=f*0.3;
	p=t+m+f;
	
	if(p>=16 && p<=20)
		cout<<"Su nota es "<<p<<" y ha sido clasificado como 'Bueno'."<<endl;
	
	else if(p>=11 && p<=15)
		cout<<"Su nota es "<<p<<" y ha sido clasificado como 'Regular'."<<endl;
		
	else if(p>=6 && p<=10)
		cout<<"Su nota es "<<p<<" y ha sido clasificado como 'Malo'."<<endl;
	
	else cout<<"Su nota es "<<p<<" y ha sido clasificado como 'Pesimo'."<<endl;	
	
	system("pause");
	return 0;
}
