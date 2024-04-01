#include <iostream>

int simbolJacobi(int a, int n) {
    if (a == 0) return 0; // Cazul de bază 0
    if (a == 1) return 1; // Cazul de bază 1

    int ans;
    if (a % 2 == 0) {
        // Calculează simbolul (2/n) separat
        if (n % 8 == 1 || n % 8 == 7) ans = 1;
        else if (n % 8 == 3 || n % 8 == 5) ans = -1;
        return ans * simbolJacobi(a / 2, n);
    } else {
        // Aplică legea reciprocității cuadratice dacă a > 1
        if (a >= n) return simbolJacobi(a % n, n);
        if (a % 4 == 3 && n % 4 == 3) ans = -1;
        else ans = 1;
        return ans * simbolJacobi(n, a);
    }
}

int main() {
    int a, n;
    std::cout << "Introduceti a si n (n impar): ";
    std::cin >> a >> n;
    std::cout << "Simbolul lui Jacobi (" << a << "/" << n << ") este " << simbolJacobi(a, n) << std::endl;
    return 0;
}
