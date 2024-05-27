#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>


int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}


bool is_perfect_power(int n) {
    for (int b = 2; b <= std::log2(n); b++) {
        int a = std::pow(n, 1.0 / b);
        if (std::pow(a, b) == n || std::pow(a + 1, b) == n)
            return true;
    }
    return false;
}


int find_smallest_r(int n) {
    int max_k = std::log2(n) * std::log2(n);
    for (int r = 2; ; r++) {
        bool found = true;
        for (int k = 1; k <= max_k; k++) {
            if (power(n, k, r) == 0 || std::gcd(n, r) != 1) {
                found = false;
                break;
            }
        }
        if (found) return r;
    }
}


bool polynomial_check(int n, int r) {
    for (int a = 1; a <= std::sqrt(r) * std::log2(n); a++) {
        std::vector<int> lhs(r, 0), rhs(r, 0);
        lhs[0] = rhs[0] = a % n;
        lhs[1] = rhs[1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = std::min(i, r-1); j >= 0; j--) {
                lhs[j] = (lhs[j] * a) % n;
                if (j > 0) lhs[j] = (lhs[j] + lhs[j-1]) % n;
            }
        }
        if (lhs != rhs) return false;
    }
    return true;
}


bool is_prime_aks(int n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;

    if (is_perfect_power(n)) return false;

    int r = find_smallest_r(n);
    for (int a = 2; a <= std::sqrt(r) * std::log2(n); a++) {
        if (std::gcd(a, n) > 1 && a < n)
            return false;
    }

    if (n <= r) return true;

    return polynomial_check(n, r);
}

int main() {
    int n;
    std::cout << "Introduceti un numar pentru a verifica daca este prim: ";
    std::cin >> n;

    if (is_prime_aks(n))
        std::cout << n << " este prim.\n";
    else
        std::cout << n << " nu este prim.\n";

    return 0;
}
