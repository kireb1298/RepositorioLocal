#include <iostream>
using namespace std;
int main(){
	float nu1, nu2;
	cout << "Ingrese el primer numero: ";
	cin >> nu1;
	cout << "Ingrese el segundo numero: ";
	cin >> nu2;
	if(nu1>=0 && nu2>=0) 
		cout << "Su producto es: " << nu1*nu2 << endl;
	else cout << "Su suma es: " << nu1+nu2; 
	return 0;
}
