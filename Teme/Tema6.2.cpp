#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Citirea alfabetului din fisier
    ifstream in("alfabet.txt");
    if (!in.is_open()) {
        cerr << "Nu s-a putut deschide fisierul alfabet.txt!" << endl;
        return 1;
    }
    citeste_alfabet(in);
    in.close();

    // Deschiderea fisierului destinatie pentru rezultatul decriptat
    ofstream out("mesaj-decriptat3.txt");
    if (!out.is_open()) {
        cerr << "Nu s-a putut deschide fisierul mesaj-decriptat3.txt!" << endl;
        return 1;
    }

    // Deschiderea fisierului sursa pentru textul criptat
    ifstream in2("mesaj-criptat3.txt");
    if (!in2.is_open()) {
        cerr << "Nu s-a putut deschide fisierul mesaj-criptat3.txt!" << endl;
        return 1;
    }

    // Cheile de decriptare (a și b)
    int a = 5; // Exemplu de valoare pentru a
    int b = 8; // Exemplu de valoare pentru b

    // Decriptarea mesajului
    spargereAfina(in2, out, a, b);

    in2.close();
    out.close();

    cout << "Decriptare completă. Verifică fisierul 'mesaj-decriptat3.txt'." << endl;

    return 0;
}
