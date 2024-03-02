#include <iostream>
using namespace std;

int r;
int cmmdc (int a, int b)
{
    if (a == 0 )
        return b;
    if(b == 0) 
        return a;

    while(b){
        r = a%b;
        a = b;
        b =r;
    }
    return a;
}

int main(){
    cout<< cmmdc(3,9);
    return 0;
}