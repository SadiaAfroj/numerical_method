// Newton_Forward_Interpolation

#include <bits/stdc++.h>
using namespace std;

class Newton_Forward_Interpolation
{
private:

    float value = 1895;
    float find_p(float p, int n)
    {
        float temp = p;
        for (int i = 1; i < n; i++)
            temp = temp * (p - i);
        return temp;
    }

    int fact(int n)
    {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }
public:
    Newton_Forward_Interpolation(float value){
        value = value;
    }
    void find(){
        int n = 5;
        float x[] = { 1891, 1901, 1911, 1921, 1931};
        float ini_y[] = { 46, 66, 81, 93, 101};
        float y[n][n];
        for(int i = 0; i < n; i++) {
        y[i][0] = ini_y[i];
    }

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}

	for (int i = 0; i < n; i++) {
		cout << setw(4) << x[i] << "\t";
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << y[i][j] << "\t";
		cout << endl;
	}



	float sum = y[0][0];
	float p = (value - x[0]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
		sum = sum + (find_p(p, i) * y[0][i]) / fact(i);
	}

	cout << "Value at " << value << " is " << sum << endl;
    }
};


int main()
{
	Newton_Forward_Interpolation newton_Forward_Interpolation(1895);
    newton_Forward_Interpolation.find();
	return 0;
}
