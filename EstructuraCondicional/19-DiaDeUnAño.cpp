/*
Dado un numero de dia de un determinado año, encuentre el dia, mes y el año al que corresponde.
Por ejemplo, ek dia numero 300 del año 2000 es el 26/10/2000. Tenga en cuenta que el
numero de dias de cada mes es: enero 31, febrero 28 o 29, marzo 31, abril 30, mayo 31, 
junio 30, julio 31, agosto 31, septiembre 30, octubre 31, noviembre 30 y diciembre 31.
*/
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