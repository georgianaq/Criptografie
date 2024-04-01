#include "header.h"



int main(){
ifstream in("alfabet.txt");
citeste_alfabet(in);
in.close();
ofstream out("destinatie.txt");
ifstream in2("sursa.txt");//fisierul cu textul sursa


int** a = new int* [2];
int* b = new int[2];
for (int i = 0; i < 2; i++)
a[i] = new int[2];
a[0][0] = 27;
a[0][1] = 7;
a[1][0] = 1;
a[1][1] = 20;
b[0] = 0;
b[1] = 0;
cheieAfina k;
k.n = 2;
k.a = calcul_matr_inv_Zn(a,2,N);
k.b = b;
criptareAfina(in2, out, k);
}