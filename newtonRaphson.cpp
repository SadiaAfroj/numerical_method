#include <bits/stdc++.h>

using namespace std;

class NewtonRaphson {
private:
    double tolerance;
    int maxIterations, iteration = 1;

    double function(double x) {
        return x * x * x - x*x + 2; // Function
    }


    double derivative(double x) {
        return 2 * x * x - 2 * x;
    }

public:
    NewtonRaphson(double tol = 1e-6, int maxIter = 1000) : tolerance(tol), maxIterations(maxIter) {}

    double findRoot(double initialGuess) {
        double x = initialGuess;
        for (int i = 0; i < maxIterations; ++i) {
            double fx = function(x);
            double fPrimeX = derivative(x);

            if (fabs(fPrimeX) < 1e-10) {
                cout << "Derivative is too small. No convergence." << endl;
                return x;
            }

            double xNew = x - fx / fPrimeX;
            cout << "Iteration X" << iteration << " = " << xNew << endl;
            iteration++;

            if (fabs(xNew - x) < tolerance) {
                cout << "Converged in " << i + 1 << " iterations." << endl;
                return xNew;
            }
            x = xNew;
        }

        cout << "Max iterations reached. Solution may not have converged." << endl;
        return x;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    NewtonRaphson solver(1e-6, 100);
    double initialGuess = rand() % 10 - 5;  // [-5, 4]

    cout << "Using initial guess: " << initialGuess << endl;
    double root = solver.findRoot(initialGuess);
    cout << "Estimated root: " << root << endl;
     return 0;
}
