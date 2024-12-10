#include <bits/stdc++.h>
using namespace std;

class FalsePositionMethod {
public:
    FalsePositionMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {
            generateRandomInterval();
    }

    double findRoot() {
        double c=0;
        for (int i = 0; i < maxIterations; ++i) {
            c = a - (func(a) * (b - a)) / (func(b) - func(a));
            double f_c = func(c);
            cout << "Iteration X" << iteration << " = " << c << endl;
            iteration++;

            if (fabs(f_c) < tolerance) {
                return c;
            }

            if (func(a) * f_c < 0) {
                b = c;
            } else {
                a = c;
            }
        }

        return c;
    }

private:
    double a, b, tolerance, iteration = 1;
    int maxIterations;

    double func(double x) {
        return x * x * x - x*x + 2; // Function
    }

    void generateRandomInterval() {
        srand(static_cast<unsigned>(time(0)));

        do {
            a = (rand() % 200 - 100) / 10.0; // Random double between -10 and 10
            b = (rand() % 200 - 100) / 10.0;
        } while (func(a) * func(b) > 0);
    }
};

int main() {
    double tolerance = 1e-6;
    int maxIterations = 100;

    FalsePositionMethod falsePosition(tolerance, maxIterations);
    double root = falsePosition.findRoot();

    cout << "Root: " << root << endl;

    return 0;
}
//False poosition
