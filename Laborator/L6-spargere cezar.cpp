#include "header.h"



int main(){
ifstream in("alfabet.txt");
citeste_alfabet(in);
in.close();
ofstream out("destinatie.txt");
ifstream in2("sursa.txt");//fisierul cu textul sursa
spargereCezar(in2, out, 'A');//pe ultima poziție trebuie cheia de criptare
in2.close(); out.close();
}