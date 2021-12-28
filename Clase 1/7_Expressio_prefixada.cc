#include<iostream>
using namespace std;


int expresio_pre() {
	
	// Llegim un caracter
	char c;
	cin >> c;
	
	// Cas Base, es un numero
	// El passem de caracter a enter i el retornem
	if (c >= '0' and c <= '9') return c-'0';
	
	// Casos Recursius, es un signe d'operacio
	// Retornem el resultat de operar amb les 2 expresions que venen a continuacio
	int a = expresio_pre();
	int b = expresio_pre();
	
	if (c == '+') return a+b;
	else if (c == '*') return a*b;
	else return a-b;
	
	
}



int main() {
	
}
