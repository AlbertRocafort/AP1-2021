#include<iostream>
#include<string>
using namespace std;


void traduir_escriure(const string& linea, const string& traduccio) {
	
	int n = linea.size();
	for (int i = 0; i < n; i++) {
		
		// Es un espai en blanc
		if (linea[i] == '_') {
			cout << ' ';
		}
		
		// Es un caracter
		else {
			
			int j = 0;
			bool caracter_trobat = false;
			
			while (not caracter_trobat) {
				
				// Busquem el caracter i de la linea en el string de traduccio
				if (linea[i] == traduccio[j]) {
					
					// Imprimim el caracter traduit
					cout << char('a' + j);
					caracter_trobat = true;
				}
				
				j++;
			}
			
			
		}
		
	}
	
}


int main() {
	
	string traduccio;
	while (cin >> traduccio) {
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			
			string linea;
			cin >> linea;
			
			traduir_escriure(linea, traduccio);
			cout << endl;
		}
		
	}
	
}
