#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>

using namespace std;

bool prim(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i <= sqrt((double)n); i += 2)
		if (n % i == 0) return 0;
	return 1;
}
int** factor(unsigned int n, int& nr)
{
	int** descompunere = new int* [2];
	descompunere[0] = new int[n];
	descompunere[1] = new int[n];
	for (unsigned long long i = 0; i < n; i++)
		descompunere[0][i] = descompunere[1][i] = 0;
	if (n % 2 == 0)
	{
		descompunere[0][0] = 2;
		nr++;
		while (n % 2 == 0)
		{
			descompunere[1][0]++;
			n /= 2;
		}
	}
	for (unsigned long long i = 3; i <= n; i += 2)
	{
		if (n % i == 0)
		{
			descompunere[0][nr] = i;
			while (n % i == 0)
			{
				descompunere[1][nr]++;
				n /= i;
			}
			nr++;
		}
	}
	return descompunere;
}
char* citeste_din_fisier(ifstream& in)
{
	char* mesaj = new char[100];
	char c;
	int i = 0;
	if (in.good())
	{
		cout << "Fisierul a fost deschis cu succes.\nContinutul acestuia este:\n\n";
		while (!in.eof()) // cat timp nu s-a ajuns la sfarsitul fisierului sursa
		{
			in >> noskipws >> c;
			mesaj[i] = c;
			i++;
		}
		mesaj[--i] = '\0';
	}
	else
		cout << "Eroare la deschiderea fisierului.";
	return mesaj;
}
void scrie_in_fisier(const char* mesaj)
{//vom scrie caracter cu caracter
	ofstream out("destinatie.txt"); //deschidem fisierul pentru scriere
	//echivalent cu:
	//fstream out("destinatie.txt",ios::out);)
	//pentru a adauga text intr-un fisier:
	//fstream out("destinatie.txt",ios::app);
	int i = 0;
	while (mesaj[i] != '\0') // cat timp nu s-a ajuns la sfarsitul mesajului
	{
		out << mesaj[i];
		i++;
	}
	out.close();//inchidem fisierul
}
using namespace std;
struct bloc
{
	char c;
	int nr;
};
bloc character[100] = { 0 };
int N = 0;
int da_cod(char c)
{
	for (int i = 0; i < N; i++)
		if (character[i].c == c)
			return i;
	return -1;
}

char da_caracter(int cod)
{
	return character[cod % N].c;
}
void citeste_alfabet(ifstream& in)
{
	if (!in.good())
		perror("Fisier inexistent");
	char c;
	while (in >> noskipws >> c)
	{
		character[N].c = c;
		N++;
	}
	if (N == 0)
		cout << "Alfabetul dat are 0 caractere" << endl;
}
bloc* ordonareFrecvente()
{
	bloc* result = new bloc[N];
	int ordonat = 0;
	for (int i = 0; i < N; i++)
		result[i] = character[i];
	while (!ordonat)
	{
		ordonat = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (result[i].nr < result[i + 1].nr)
			{
				ordonat = 0;
				bloc temp = result[i];
				result[i] = result[i + 1];
				result[i + 1] = temp;
			}
		}
	}
	return result;
}
void frecv(ifstream& fin)
{
	if (!fin.good())
		perror("Fisier inexistent");
	char c;
	while (fin >> noskipws >> c)
	{
		int cod = da_cod(c);
		if (cod >= 0 && cod < N)
			character[cod].nr++;
	}
}

struct cheieAfina {
	int n;//dimensiunea matricilor de criptare
	int** a;
	int* b;
};

void criptareCezar(ifstream& in, ofstream& out, int k)
{
	char m;
	while (in >> noskipws >> m)
	{
		out << da_caracter(da_cod(m) + k);
	}
}

void criptareAfina(ifstream& in, ofstream& out, int a, int b)
{
	char m;
	while (in >> noskipws >> m)
	{
		out << da_caracter(da_cod(m) * a + b);
	}
}
int modulo(int k, int n) {//extindem operatorul modulo (%) si pentru numere negative
	if (k >= n)
		return k % n;
	else
		if (k < 0)
			return (n - (-k) % n)%n;
	return k;
}

int invers(int a, int n) {
	a = modulo(a, n);
	int q, r, x0 = 1, x1 = 0, copy_n = n;
	while (n != 0)
	{
		r = n;
		q = a / n;
		n = a % n;
		a = r;

		r = x1;
		x1 = x0 - q * x1;
		x0 = r;
	}
	if (a == 1)//daca numarul este inversabil
		return modulo(x0, copy_n);
	return -1;//daca numarul nu este inversabil, vom intoarce -1, pentru a putea afisa mesajul corespunzator
}
int** calcul_minor(int** matrice, int lin, int col, int n) {
	int i, j, ** a = new int* [n - 1];
	for (i = 0; i < n - 1; i++) {
		a[i] = new int[n - 1];
	}
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1; j++)
			if (i < lin) {
				if (j < col)
					a[i][j] = matrice[i][j];
				else
					a[i][j] = matrice[i][j + 1];
			}
			else {
				if (j < col)
					a[i][j] = matrice[i + 1][j];
				else
					a[i][j] = matrice[i + 1][j + 1];
			}
	return a;
}

int calcul_det(int** matrice, int n) {
	if (n <= 1) return matrice[0][0];
	int S = 0;
	for (int i = 0; i < n; i++)
		S += matrice[0][i] * (i % 2 ? -1 : 1) * calcul_det(calcul_minor(matrice, 0, i, n), n - 1);
	return S;
}

int** calcul_matr_inv_Zn(int** a, int n, int Zn) {
	int i, j, ** rez;
	rez = new int* [n];
	for (i = 0; i < n; i++)
		rez[i] = new int[n];

	int inv_determinant = invers(calcul_det(a, n), Zn);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			rez[i][j] = modulo(inv_determinant * ((i + j) % 2 ? -1 : 1) * calcul_det(calcul_minor(a, j, i, n), n - 1), Zn);
		}
	return rez;
}
void criptareAfina(ifstream& in, ofstream& out, cheieAfina k)
{
	int i = 0;
	char m;
	int* M = new int[k.n];
	int* C = new int[k.n];
	while (in >> noskipws >> m)
	{
		M[i++] = da_cod(m);
		if (i == k.n)
		{
			for (int j = 0; j < k.n; j++)
			{
				C[j] = 0;
				for (int l = 0; l < k.n; l++)
				{
					C[j] += k.a[j][l] * M[l] + k.b[l];
				}
				out << da_caracter(C[j]);
			}
			i = 0;
		};
	}
}

void spargereCezar(ifstream& in, ofstream& out, char frecvent = ' ')
{
	frecv(in);
	bloc* ordonat = ordonareFrecvente();
	int k = modulo(-da_cod(ordonat[0].c) + da_cod(frecvent), N);
	cout << k << endl;
	in.clear();
	in.seekg(0);
	criptareCezar(in, out, k);
}

void spargereAfina(ifstream& in, ofstream& out, char frecvent0 = ' ', char frecvent1 = 'e')
{
	frecv(in);
	bloc* ordonat = ordonareFrecvente();
	int a = modulo((da_cod(frecvent1) - da_cod(frecvent0)) * invers(da_cod(ordonat[1].c) - da_cod(ordonat[0].c), N), N);
	int b = modulo(da_cod(frecvent1) - a * da_cod(ordonat[1].c), N);
	in.clear();
	in.seekg(0);
	criptareAfina(in, out, a, b);
}


void spargereafina(ifstream& in, ofstream& out, char frecvent0 = ' ', char frecvent1 = 'a')
{
	frecv(in);
	bloc* ordonat = ordonareFrecvente();
	int a = modulo((da_cod(frecvent0) - da_cod(frecvent1)) * invers(da_cod(ordonat[0].c) - da_cod(ordonat[1].c), N), N);
	int b = modulo(da_cod(frecvent0) - a * da_cod(ordonat[0].c), N);
	in.clear();
	in.seekg(0);


	criptareAfina(in, out, a, b);
}

int cmmdc(int a, int b)
{
	if (a == 0 || b == 0) return a + b;
	int r;
	do
	{
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}

int a_la_b_mod_c(int a, int b, int c)
{
	int p = 1;
	a = modulo(a, c);
	while (b > 0)
	{
		if (b % 2)
			p = modulo((p * a), c);
		a = modulo((a * a), c);
		b /= 2;
	}
	return p;
}

bool test_Fermat(unsigned long long n, unsigned int nr_incercari)
{
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	for (; nr_incercari > 0; nr_incercari--) {
		int random1 = rand(), random2 = rand();
		long b = (random1 << 16) | random2;//pentru a avea numar obtinut random mare (rand intoarce un int)
		b = 2 + b % (n - 2);
		if (cmmdc(b, n) != 1)return 0;
		if (a_la_b_mod_c(b, n - 1, n) != 1)return 0;
	}
	return 1;
}

int da_prim(int min, int max, int nr)
{
	if (min > max) return -1;
	if (min == max)
		if (prim(min))
			return min;
		else
			return -1;
	int nrAleator = rand() % (max - min);
	for (int p = min+nrAleator; p < max; p++)
	{
		if (test_Fermat(p, 3))
		{
			if (prim(p) && p != nr)
				return p;
		}
	}
	for (int p = min; p < max; p++)
	{
		if (test_Fermat(p, 3))
		{
			if (prim(p) && p != nr)
				return p;
		}
	}
	return -1;
}
int log1_d(int b, int y, int p)
{
	int prod = 1;
	int x = 0;
	while (prod != y && x<=p)
	{
		prod = (prod * b) % p;
		x++;
	}
	if (prod == y)
		return x;
	return -1;
}

int log_d(int b, int y, int p)
{
	int i, j, * v, a;
	a = (int)sqrt((double)p);
	v = new int[a + 1];
	v[0] = 1;
	v[1] = a_la_b_mod_c(b, a, p);
	for (i = 2; i <= a; i++)
		v[i] = (v[i - 1] * v[1]) % p;
	y = modulo(y, p);
	for (j = 0; j < a; j++) {
		for (i = 0; i <= a; i++)
			if (y == v[i])
				return modulo(i * a - j, p - 1);
		y = (y * b) % p;
	}
	return 0;
}


struct RSA_key
{
	int n, e, d, l, j;
};
RSA_key generare_chei()
{
	RSA_key cheie;
	int p, q, n, phi, e, d;
	srand((int)time(NULL));
	p = da_prim(2, 1000, 2);//Generam numere astfel incat produsul a doua asemenea numere sa nu depaseasca domeniul pentru variabile
	q = da_prim(2, 1000, p);
	n = p * q;
	phi = (p - 1) * (q - 1);
	e = 3 + rand() % (phi - 3);
	d = invers(e, phi);
	while (d < 0)
	{//pentru ca e sa fie inversabil
		e++;
		d = invers(e, phi);
	}
	cheie.n = cheie.n = n;
	cheie.e = e;
	cheie.d = d;
	return cheie;
}


void RSA(ifstream in, ofstream out, RSA_key key)
{
	char* c = new char[key.l >= key.j ? key.l : key.j];
	int i = 0, m = 0;
	while (in >> noskipws >> c[i]) {
		m = m * N + da_cod(c[i]);
		if (i == key.j - 1) {
			m = a_la_b_mod_c(m, key.e, key.n);
			i = key.l - 1;
			while (m > 0) {
				c[i] = da_caracter(m % N);
				m = m / N;
				i--;
			}
			while (i >= 0)c[i--] = da_caracter(0);
			for (i = 0; i < key.l; i++)out << c[i];
			i = 0;
		}
		else
			i++;
	}
	out.close();
	in.close();
}