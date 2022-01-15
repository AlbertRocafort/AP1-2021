#include<vector>
#include<iostream>
using namespace std;


void pintar_permutacio(int n, const vector<int>& sol)
{
    for (int i = 0; i < n; ++i) {
    	if (i > 0) cout << ' ';
        cout << sol[i];
    }
    cout << endl;
}


// Nums sera equivalent a la nostra k de sempre
void genera(vector<int>& combinacio, vector<bool>& used, const vector<bool>& pos_obligada, int n, int k, int nums, int posicions_consecutives) {
	
	// Cas base
	if (nums == n) {
		pinta_permutacio(n, combinacio);
	}
	
	// Cas recursiu
	else {
	
		// Comprovem si podem modificar el contingut de la casella nums
		if (not pos_obligada[nums]) {
			
			// Si el podem modificar, intentarem amb tots els numeros que no han estat utilitzats encara
			for (int i = 0; i < n; i++) {
				
				// Si el num no ha estat utilitzat
				if (not used[i]) {
					
					// Comprovem si i es consecutiu del numero colocat anteriorment
					if (nums > 0 and combinacio[nums-1] != i+1 and combinacio[nums-1] != i-1) {
						
						// Si ho es, nomes podrem fer la crida recursiva si posicions_consecutives es menor que k
						if (posicions_consecutives < k) {
							
							// Crida recursiva
							genera(combinacio, used, pos_obligada, n, k, nums+1, posicions_consecutives+1);
						}
					}
					
					// Si no, nomes es fara si encara que aquest no ho sigui, es pot arribar a k amb els numeros que queden per posar
					else
				}
				
			}
			
		}
		
	}
	
}














int main() {
	
	// Llegim les dades inicials
	int n, k, m;
	while (cin >> n >> k >> m) {
		
		// Creem els vectors que necesitarem
		vector<int> combinacio(n); // Vector sobre el que construirem les combinacions
		vector<bool> used(n, false); // Vector per controlar els numeros utilitzats
		vector<bool> posicio_obligada(n, false); // Vector per controlar les posicions que no podem cambiar el contingut
		
		// Llegim els m parells
		for (int a = 0; a < m; a++) {
			
			// Llegim el parell
			int i, x;
			cin >> i >> x;
			
			// Coloquem el valor x en la posicio i
			combinacio[i] = x;
			
			// Marquem x com utilitzat
			used[x] = true;
			
			// Indiquem que la posicio i no podra variar el seu contingut
			posicio_oblidada[i] = true;	
		}
	
		genera();
		
		cout << "********************" << endl;
	
	}
	
	
	
	
}
