#include <iostream>

int main()
{
    int A, a, b, c, d, e;

    while (std::cin >> A)
    {
        a = A%19;
        b = A%4;
        c = A%7;
        d = (19*a+24)%30;
        e = (2*b+4*c+6*d+5)%7;
        if (d+e < 10)
            std::cout << d+e+22 << " de marzo" << std::endl;
        else
            std::cout << d+e-9 << " de abril" << std::endl;
    }
    return 0;
}
