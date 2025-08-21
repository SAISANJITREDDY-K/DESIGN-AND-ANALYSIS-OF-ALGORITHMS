O(1) summation:-

#include <iostream>

#include <cmath>

using namespace std;

double SumSeriesFormula(double a, double r, int n) {

if (r == 1) return a * n;

return a * (pow(r, n) - 1) / (r - 1);

}

int main() {

double a, r;

int n;

cout << "Enter first term (a): ";

cin >> a;

cout << "Enter common ratio (r): ";

cin >> r;

cout << "Enter number of terms (n): ";

cin >> n;

cout << "Sum using O(1) formula: " << SumSeriesFormula(a, r, n) << endl;

return 0;

}
