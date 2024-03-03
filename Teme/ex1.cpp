#include <iostream>
using namespace std;

//int r;
//int cmmdc (int a, int b)
//{
   // if (a == 0 )
     //   return b;
    //if(b == 0) 
      //  return a;

    //while(b){
      //  r = a%b;
        //a = b;
        //b =r;
    //}
    //return a;
//}

//int bezoutt(int a, int b)
//{
    // int xr[2], xq[2], xa[2], xb[2];
    // xa[1] = 1;
    // xa[2] = 0;
    // xb[1] = 0;
    // xb[2] = 1;
    // xq 
   // int x;
   // x = cmmdc(a,b);
    //for (int i = 1; i<=10000; i++)
       // for(int j = -10000; j <= 10000; j++){
               // if (((i*a) + (j*b)) == x){
                //cout<< i;
               // cout<<" ";
               // cout <<j<<endl;
               // return 1;
            //}
        //}
       // return 0;

//}
int modulo(int k, int n){//extindem operatorul modulo (%) si pentru numere
negative
if (k < 0)k = n - (-k) % n;
if (k >= n) return k%n;
return k;
int invers(int a, int n)
{
int q, r, x0 = 1, x1 = 0, copy_n = n;
a = modulo(a, n);
while (n != 0)
{
r = n;
q = a / n;
n = a%n;
a = r;
r = x1;
x1 = x0 - q*x1;
x0 = r;
}
if (a == 1)//daca numarul este inversabil
    return modulo(x0, copy_n);
    return -1;//daca numarul nu este inversabil, vom intoarce -1, pentru a putea afisa mesajul corespunzator

int main(){
    bezoutt(360,294);
    return 0;
}