#include <bits\stdc++.h>
using namespace std;

class BisectionMethod {
public:
    BisectionMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {
        generateRandomInterval();
    }

    double findRoot() {
        double c;
        for (int i = 0; i < maxIterations; ++i) {
            c = (a + b) / 2;
            cout << "Iteration X" << iteration << " = " << c << endl;
            iteration++;
            double f_c = func(c);

            if (fabs(f_c) < tolerance || (b - a) / 2 < tolerance) {
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
    double a, b, tmp, tolerance,iteration = 1;
    int maxIterations;

    double func(double x) {
        return x * x * x - x*x + 2; // Function
    }

    void generateRandomInterval() {
        srand(static_cast<unsigned>(time(0)));

        do {
            a = (rand() % 200 - 100) / 10.0; // Random double between -10 and 10
            tmp = (rand() % 200 - 100) / 10.0;
            a = min(a,tmp);
            b = max(a,tmp);
        } while (func(a) * func(b) > 0);
    }
};

int main() {
    double tolerance = 1e-6;
    int maxIterations = 100;

    BisectionMethod bisection(tolerance, maxIterations);
    double root = bisection.findRoot();

    cout << "Root: " << root << endl;

    return 0 ;
}
