#include <iostream>
#include <cmath>

int main() {
    double x;
    double z1, z2;

    std::cout << "x\tz1\tz2" << std::endl;
    std::cout.precision(15);

    for (int i = 5; i <= 15; ++i) {
        x = pow(10, -i);

        z1 = (exp(x) - 1) / x;

        double y = exp(x);
        if (y == 1)
            z2 = 1;
        else
            z2 = (y - 1) / log(y);

        std::cout << x << "\t" << z1 << "\t" << z2 << std::endl;
    }

    return 0;
}
