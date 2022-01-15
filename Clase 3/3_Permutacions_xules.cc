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


void genera(vector<int>& combinacio, vector<bool>& used, int n, int k) {
	
	// Cas base
	if (k == n) {
		imprimeix_combinacio(combinacio, n);
	}
	
	// Cas recursiu
	else {
		
		// Probem tots els numeros en la posicio k
		for (int i = 0; i < n; i++) {
			
			// Comprovem que encara no l'hem colocat
			if (not used[i]) {
				
				// Comprovem que el numero colocat en la posicio anterior
				// no sigui consecutiu al que anem a possar
				// Hem de vigilar quan k = 0, pq si accedim a la posicio -1 petara
				if (k == 0  or  (combinacio[k-1] != i-1 and combinacio[k-1] != i+1)) {
					
					combinacio[k] = i;
					used[i] = true;
					genera(combinacio, used, n, k+1);
					
					// Un cop acabada la crida, desmarquem el numero com utilitzat
					used[i] = false;
				}
			}
		}
	}
}


int main() {
	
	int n;
	while (cin >> n) {
		
		vector<int> combinacio(n);
		vector<bool> used(n, false);
		
		genera(combinacio, used, n, 0);
		cout << "********************" << endl;
	}
	
	
	
	
	
}
