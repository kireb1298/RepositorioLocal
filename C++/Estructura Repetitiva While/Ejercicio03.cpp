/*
Para simplificar una fraccion, basta con divir su numerador y denominador entre el
'mcd' de ambos. Implemente un algoritmo que simplifique una fraccion haciendo uso de 
esta idea. 
*/

#include <iostream>

int main()
{
    int n, d, ns, ds, mcd, temp1, temp2;
    std::cout
        << "Simplificacion de una fraccion. (n/d) \n"
        << "Digite el numerador(n) y denominador(d) "
        << std::endl;
    std::cin >> n >> d;

    if (n > d)
    {
        temp1 = n;
        temp2 = d;
    }
    else if (n < d)
    {
        temp1 = d;
        temp2 = n;
    }
    else
    {
        std::cout << "La fraccion " << n << "/" << d << " simplificada es 1." << std::endl;
        return 0;
    }

    while (temp2 != 0)
    {
        mcd = temp1 % temp2;
        temp1 = temp2;
        temp2 = mcd;
    }

    mcd = temp1;
    ns = n / mcd;
    ds = d / mcd;

    if (ds != 1)
        std::cout << "La fraccion " << n << "/" << d << " simplificada es " << ns << "/" << ds << std::endl;
    else
        std::cout << "La fraccion " << n << "/" << d << " simplificada es " << ns << std::endl;

    system("pause");
    return 0;
}
