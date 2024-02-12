#include <iostream>
#include <cmath>
#include <cstdint>

double estimateExponent(double f) {
    uint64_t* bits = reinterpret_cast<uint64_t*>(&f); // Interpret the double as uint64_t
    int biasedExponent = ((*bits >> 52) & 0x7FF) - 1023; // Extract biased exponent
    double x = biasedExponent * log10(2); // Convert biased exponent to real exponent
    return x;
}

int main() {
    double numbers[] = {1234.5678, 7.49e-8, 7547, 52500.5, 6.7854, 3408944};

    std::cout << "Number\t\tEstimate\t\tActual\t\t\tDifference" << std::endl;
    std::cout.precision(8);

    for (double num : numbers) {
        double estimatedExponent = estimateExponent(num);
        double actualExponent = log10(fabs(num));
        double difference = fabs(estimatedExponent - actualExponent);

        std::cout << num << "\t" << estimatedExponent << "\t\t" << actualExponent << "\t\t" << difference << std::endl;
    }

    return 0;
}
