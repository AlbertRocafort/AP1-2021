#include<iostream>
#include<vector>
using namespace std;


void imprimeix_combinacio(const vector<string>& paraules, const vector<int>& combinacio, int n, int p) {
	
	// Cada iteracio imprimira un subconjunt
	for (int i = 1; i <= p; i++) {
		
		cout << "subconjunt " << i << ": {";
		bool primera_paraula = true;
		
		// Repassar tot el vector de combinacio buscant les paraules que es troben en el subconjunt que estem imprimint
		for (int j = 0; j < n; j++) {
			
			// Si la paraula j es troba en el subconjunt que imprimim
			if (combinacio[j] == i) {
				if (primera_paraula) primera_paraula = false;
				else cout << ',';
				cout << paraules[j];
			}
		}
		
		cout << "}" << endl;
	}
	cout << endl;
}


void genera(const vector<string>& paraules, vector<int>& combinacio, int n, int p, int k) {
	
	// Cas base
	if (k == n) {
		imprimeix_combinacio(paraules, combinacio, n ,p);
	}
	
	// Cas recursiu
	else {
		
		// Colocarem la paraula k en tots els subconjunts
		for (int i = 1; i <= p; i++) {
			
			// Posem la paraula k en el subconjunt i
			combinacio[k] = i;
			
			// Crida recursiva
			genera(paraules, combinacio, n, p, k+1);	
		}
	}
}


int main() {
	
	// Llegim l'input
	int n;
	cin >> n;
	
	vector<string> paraules(n);
	for (int i = 0; i < n; i++) cin >> paraules[i];
	
	int p;
	cin >> p;
	
	// A la posicio x es troba la particio en la que guardem la paraula x
	vector<int> combinacio(n);
	
	// Funcio de generacio
	genera(paraules, combinacio, n, p, 0);	
	
}
