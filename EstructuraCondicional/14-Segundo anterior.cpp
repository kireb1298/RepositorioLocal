/*
Dada la hora en horas, minutos y segundos, encuentre la hora del segundo anterior.
*/

#include <iostream>

using namespace std;

int main()
{
	int h, m, s;

	cout << "Ingrese horas, minutos y segundos\n";
	cin >> h >> m >> s;
	s = s - 1;

	if (s == -1)
	{
		s = 59;
		m = m - 1;
		if (m == -1)
		{
			m = 59;
			h = h - 1;
			if (h == -1)
				h = 23;
		}
	}
	cout << "La hora correspondiente al segundo anterior [" << h << ":" << m << ":" << s << "]" << endl;

	system("pause");
	return 0;
}
