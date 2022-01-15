#include<iostream>
#include<vector>
using namespace std;

int abs(int x) {
	if (x < 0) return -x;
	return x;
}

void genera(int n, int d, int uns, int zeros, int k, int& contador) {
	
	// Cas base
	if (k == n) contador++;
	
	// Cas recursiu
	else {
		
		// Comprovar si al posar un 1 es segueix complint que la diferencia es menor o igual a d
		if (abs((uns+1) - zeros) <= d) {
			genera(n, d, uns+1, zeros, k+1, contador);
		}
		
		if (abs(uns - (zeros+1)) <= d) {
			genera(n, d, uns, zeros+1, k+1, contador);
		}
	}
}



int main() {
	
	int n, d;
	while (cin >> n >> d) {
		
		int contador = 0;
		
		// Cridem a la funcio de generacio
		genera(n, d, 0, 0, 0, contador);
		
		// Mostrem el resultat
		cout << contador << endl;
	}
}
