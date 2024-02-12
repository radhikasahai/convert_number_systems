#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float computeSeriesForward(int N) {
    float sum = 0.0f;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) {
            sum -= 1.0f / i;
        } else {
            sum += 1.0f / i;
        }
    }
    return sum;
}

float computeSeriesBackward(int N) {
    float sum = 0.0f;
    for (int i = N; i >= 1; --i) {
        if (i % 2 == 0) {
            sum -= 1.0f / i;
        } else {
            sum += 1.0f / i;
        }
    }
    return sum;
}

int main() {
    int terms[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    cout << "N\tForward Sum\tBackward Sum\tForward Error\tBackward Error" << endl;
    cout.precision(8);

    for (int N : terms) {
        float forwardSum = computeSeriesForward(N);
        float backwardSum = computeSeriesBackward(N);

        float forwardError = fabs(forwardSum - log(2));
        float backwardError = fabs(backwardSum - log(2));

        cout << N << "\t" << forwardSum << "\t" << backwardSum << "\t" << forwardError << "\t" << backwardError << endl;
    }

    return 0;
}
