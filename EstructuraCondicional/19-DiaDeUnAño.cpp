#include <iostream>
using namespace std;
int main()
{
    int dia, ano;
    cout << "Ingrese el dia: (0 - 365) ";
    cin >> dia;
    cout << "Ingrese el ano: ";
    cin >> ano;
    if (dia < 365 && dia > 0)
    {
        if (dia <= 31)
            cout << dia << "/01/" << ano << endl;
        else
        {
            if (dia <= 59)
                cout << dia - 31 << "/02/" << ano << endl;
            else
            {
                if (dia <= 90)
                    cout << dia - 59 << "/03/" << ano << endl;
                else
                {
                    if (dia <= 120)
                        cout << dia - 90 << "/04/" << ano << endl;
                    else
                    {
                        if (dia <= 151)
                            cout << dia - 120 << "/05/" << ano << endl;
                        else
                        {
                            if (dia <= 181)
                                cout << dia - 151 << "/06/" << ano << endl;
                            else
                            {
                                if (dia <= 212)
                                    cout << dia - 181 << "/07/" << ano << endl;
                                else
                                {
                                    if (dia <= 243)
                                        cout << dia - 212 << "/08/" << ano << endl;
                                    else
                                    {
                                        if (dia <= 273)
                                            cout << dia - 243 << "/09/" << ano << endl;
                                        else
                                        {
                                            if (dia <= 304)
                                                cout << dia - 273 << "/10/" << ano << endl;
                                            else
                                            {
                                                if (dia <= 334)
                                                    cout << dia - 304 << "/11/" << ano << endl;
                                                else
                                                {
                                                    if (dia <= 365)
                                                        cout << dia - 334 << "/12/" << ano << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
        cout << "Digite un dia valido (0 al 365)" << endl;
    return 0;
}