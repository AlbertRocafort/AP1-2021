#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	
	int n;
	while (cin >> n and n != 0) {
		
		vector<string> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		
		string referencia = v[0];
		string palabra_moda = v[0];
		int contador = 1;
		int max = 1;
		
		for (int i = 1; i < n; i++) {
			
			if (v[i] == referencia) contador++;
			
			else {
				if (contador > max) {
					palabra_moda = referencia;
					max = contador;
				}
				else if (contador == max) {
					if (referencia > palabra_moda) palabra_moda = referencia;
				}
				
				referencia = v[i];
				contador = 1;
			}
		}
		
		if (contador > max) palabra_moda = referencia;
		else if (contador == max and referencia > palabra_moda) palabra_moda = referencia;
		
		cout << palabra_moda << endl;
	}
}