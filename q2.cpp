#include <iostream>
#include <cmath>

float recursiveSquareRoot(float x, int n) {
    if (n == 0) {
        return x;
    } else {
        return sqrt(recursiveSquareRoot(x, n - 1));
    }
}

int main() {
    float x = 100.0f;
    int ns[] = {2, 5, 10, 20, 30, 40};

    std::cout << "Original value of x: " << x << std::endl;

    for (int n : ns) {
        float result = x;
        result = recursiveSquareRoot(result, n);

        std::cout << "After applying square root recursively " << n << " times: " << result << std::endl;

        // Reconstructing the original value by multiplying x * x n times
        for (int i = 0; i < n; ++i) {
            result *= result;
        }

        std::cout << "Reconstructed value of x after multiplying " << n << " times: " << result << std::endl;
    }

    return 0;
}
