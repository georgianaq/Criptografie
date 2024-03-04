#include <iostream>

using namespace std;


int modularInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

int main() {
    int a = 7; 
    int m = 11; 
    int inverse = modularInverse(a, m);
    
    if (inverse == -1)
        cout << "Invers modular nu există pentru " << a << " modulo " << m << endl;
    else
        cout << "Inversul modular al lui " << a << " modulo " << m << " este " << inverse << endl;
    
    return 0;
}
