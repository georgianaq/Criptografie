#include "header.h"



int main(){
ifstream in("alfabet.txt");
citeste_alfabet(in);
in.close();
ofstream out("destinatie.txt");
ifstream in2("sursa.txt");//fisierul cu textul sursa
criptareCezar(in2, out, 1);//pe ultima poziție trebuie cheia de criptare
in2.close(); out.close();
}