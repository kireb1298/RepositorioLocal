#include <iostream>
using namespace std;
int main(){
	int n, suma, op1; // n = numero de elementos, op1= el primer sumando
	cout << "Calcular la suma de 1*2+2*3+3*4+...+n*(n+1)";
	cout << "\nIngrese n: ";
	cin >> n;
	for (int i=1; i<=n; i++){
		op1=i*(i+1);
		suma=suma+op1;
	}
	cout << "La suma es: " << suma;
	return 0;
}
