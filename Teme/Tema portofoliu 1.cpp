#include <iostream>
#include <cmath>

// Funcția pentru a calcula cel mai mare divizor comun (CMMD) folosind algoritmul lui Euclid
int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funcția pentru a calcula numărul maxim de pași
int maxSteps(int a, int b) {
    int steps = 0;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        steps++;
    }
    return steps;
}

// Funcția pentru a calcula numărul minim de pași
int minSteps(int a, int b) {
    int steps = 0;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        steps++;
    }
    // Calculăm logaritmul în baza 1.618 (proportia de aur)
    int minSteps = ceil(log(b) / log((1 + sqrt(5)) / 2));
    return minSteps;
}

int main() {
    int a, b;
    std::cout << "Introduceți cele două numere întregi pozitive: ";
    std::cin >> a >> b;

    // Verificăm dacă a este într-adevăr mai mare decât b
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int gcd = euclideanGCD(a, b);
    int max = maxSteps(a, b);
    int min = minSteps(a, b);

    std::cout << "Cel mai mare divizor comun al celor două numere este: " << gcd << std::endl;
    std::cout << "Numărul maxim de pași pentru algoritmul lui Euclid: " << max << std::endl;
    std::cout << "Numărul minim de pași pentru algoritmul lui Euclid: " << min << std::endl;

    return 0;
}
