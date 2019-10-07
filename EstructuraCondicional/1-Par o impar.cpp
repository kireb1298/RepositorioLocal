#include <iostream>
using namespace std;
int main(){
	int n; // n= numero
	cout << "Ingrese el numero que desee evaluar: ";
	cin >> n;
	if (n%2 == 0){
		cout << "El numero es par";
	}else cout << "el numero es impar";
	return 0;
}