#include<iostream>
#include<vector>
using namespace std;


void imprimeix_combinacio(const vector<int>& combinacio, int n) {
	
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		cout << combinacio[i];
	}
	cout << endl;
}


void genera(vector<int>& combinacio, int n, int u, int uns_colocats, int k) {

	// Cas base
	if (k == n) {
		imprimeix_combinacio(combinacio, n);
	}
	
	// Cas recursiu
	else {
		
		// Intentarem possar un 0 en la posicio k
		// Hem de comprovar que colocant un 0 encara es posible asolir el nombre de 1s que ens demanen
		// 0s colocats = k - uns_colocats
		// 0s que podem colocar = n - u
		if (k-uns_colocats < n-u) {
			
			// Coloquem el 1 i fem la crida recursiva
			combinacio[k] = 0;
			genera(combinacio, n, u, uns_colocats, k+1);
		}
		
		// Intentarem possar un 1 en la posicio k
		// Hem de comprovar que no ens passem en la quantitat de 1s colocats
		if (uns_colocats < u) {
			
			// Coloquem el 1 i fem la crida recursiva
			combinacio[k] = 1;
			genera(combinacio, n, u, uns_colocats+1, k+1);
		}
		
	}
}


int main() {
	
	int n, u;
	cin >> n >> u;
	
	// Vector per fer les combinacions
	vector<int> combinacio(n);
	
	genera(combinacio, n, u, 0, 0);
}
