#include <iostream>
using namespace std;
int main(){
	int n, m;
	cout << "Determinar si n es multiplo de m";
	cout << "\nIngrese n: ";
	cin >> n;
	cout << "Ingrese m: ";
	cin >> m;
	if (n%m == 0) cout << n << " si es multiplo de " << m;
	else if (n == 1) cout << n << " si es multiplo de " << m;
	else cout << n << " no es multiplo de " << m; 
	return 0;
}
