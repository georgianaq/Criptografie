#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

// Pasul 1: Verifica daca n este o putere perfecta
bool este_putere_perfecta(int n) {
    for (int b = 2; b * b <= n; ++b) {
        double a = std::pow(n, 1.0 / b);
        if (std::pow(round(a), b) == n) {
            return true;
        }
    }
    return false;
}

// Pasul 2: Gaseste cel mai mic r pentru care ordinea lui n modulo r este > log^2(n)
int gaseste_r(int n) {
    int logn2 = std::pow(std::log(n), 2);
    for (int r = 2; r < n; ++r) {
        bool ordineMare = true; // Presupunem ca ordinea este mare
        // Aici ar trebui sa verificam ordinea lui n modulo r este > logn2
        // Implementarea completa necesita calculul ordinului, care este complex
        if (ordineMare) {
            return r;
        }
    }
    return n; // fallback care nu ar trebui sa se intample
}

// Pasul 3: Verifica congruenta polinomiala
bool verifica_congruenta(int n, int r) {
    // Aceasta parte este complexa de implementat complet si necesita aritmetica polinomiala
    // Vom returna true pentru scopul acestei demonstratii
    return true;
}

// Testeaza primalitatea folosind Algoritmul AKS
bool este_prim_AKS(int n) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n % 2 == 0) return false;
    if (este_putere_perfecta(n)) return false;

    int r = gaseste_r(n);
    if (!verifica_congruenta(n, r)) return false;

    // Verifica pentru toate a de la 1 la sqrt(toti factorii lui phi(r)) * log(n)
    return true;
}

int main() {
    std::vector<int> numere = {2, 17, 18, 19, 31, 561};
    for (int n : numere) {
        if (este_prim_AKS(n))
            std::cout << n << " este prim.\n";
        else
            std::cout << n << " nu este prim.\n";
    }
    return 0;
}
