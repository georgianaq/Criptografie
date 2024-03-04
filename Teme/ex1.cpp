#include <iostream>
using namespace std;

int extendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    int a = 12345, b = 54321; 
    int x, y;
    int gcd = extendedEuclid(a, b, x, y);
    cout << "CMMDC: " << gcd << endl;
    cout << "Coeficientii Bezout: x = " << x << ", y = " << y << endl;

    return 0;
}
