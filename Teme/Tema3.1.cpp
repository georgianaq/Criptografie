#include <iostream>
#include <cstdlib>
#include <ctime>


long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}


bool is_prime_fermat(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    srand(time(0));
    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 4); 
        if (power(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int main() {
    int n = 11317;
    int k = 3; 

    if (is_prime_fermat(n, k))
        std::cout << n << " este prim.\n";
    else
        std::cout << n << " este compus.\n";

    return 0;
}
