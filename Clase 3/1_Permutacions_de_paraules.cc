#include<iostream>
#include<vector>
using namespace std;


void imprimeix_permutacio(const vector<string>& permutacio, int n) {
	cout << '(';
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ',';
		cout << permutacio[i];
	}
	cout << ')' << endl;
}


void genera(const vector<string>& paraules, vector<string>& permutacio, vector<bool>& used, int n, int k) {
	
	// Cas base
	// Quan hem completat una permutacio
	if (k == n) {
		imprimeix_permutacio(permutacio, n);
	}
	
	// Cas recursiu
	// Quan encara estem construint la permutacio
	else {
		
		// Fem un bucle per probar totes les paraules en la posicio k
		// A cada iteracio, coloca a la posicio k una nova paraula de les que no han estat utilitzades
		for (int i = 0; i < n; i++) {
			
			// Comprovem que la paraula no ha estat utilitzada en la part de la permutacio que ja esta feta
			if (not used[i]) {
				
				// Si no ha estat utilitzada encara
				// La coloquem en la permutacio, la marquem com utilitzada i fem una crida recursiva
				permutacio[k] = paraules[i];
				used[i] = true;
				genera(paraules, permutacio, used, n, k+1);
				
				// Desmarquem la paraula com utilitzada, pq en la seguent iteracio la sustituirem per una altre
				used[i] = false;
			}
		}
	}
}


int main() {
	
	// Numero de paraules
	int n;
	cin >> n;
	
	// Vector per guardar les n paraules
	vector<string> paraules(n);
	for (int i = 0; i < n; i++) cin >> paraules[i];
	
	// Vector on crearem les permutacions
	vector<string> permutacio(n);
	
	// Vector per controlar quines paraules hem colocat ja a la permutacio
	vector<bool> used(n, false);
	
	
	// Funcio recursiva de generacio
	genera(paraules, permutacio, used, n, 0);
}
