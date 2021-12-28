#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	
	int n;
	while (cin >> n) {
		
		// LLegim les n paraules i les guardem al vector
		vector<string> paraules(n);
		for (int i = 0; i < n; i++) cin >> paraules[i];
		
		// Ordenem el vector
		sort(paraules.begin(), paraules.end());
		
		// La posicio 1 tindra el numero de lletres que acumulen les paraules que es repeteixen 1 cop
		// La posicio 2 tindra el numero de lletres que acumulen les paraules que es repeteixen 2 cop
		// ...
		vector<int> num_lletres(n+1, 0);
		
		// Contarem el numero d'aparicions de cada paraula
		// I sumarem el numero de lletre que te a la posicio del vector que toqui
		
		// Variables per contar el numero de repeticions
		string paraula_de_referencia = paraules[0];
		int repeticions = 1;
		
		// Iterem per tot el vector
		for (int i = 1; i < n; i++) {
			
			// Si la paraula que es troba a la posicio i es la que teniem guardada, augmentem les repeticions
			if (paraules[i] == paraula_de_referencia) {
				repeticions++;
			}
			
			// Si es diferent, guardarem les dades i actualitzarem les variables
			else {
				
				// Sumem a la casella que toca el numero de lletres de la paraula
				num_lletres[repeticions] += paraula_de_referencia.size();
				
				// Guardem la nova paraula i resetejem el contador de repeticions
				paraula_de_referencia = paraules[i];
				repeticions = 1;
			}
		}
		
		// Sumem les lletres de la ultima paraula de referencia
		num_lletres[repeticions] += paraula_de_referencia.size();
		
		// Mostrem les dades per pantalla
		for (int i = 1; i <= n; i++) {
			
			// Evitarem imprimir les caselles que tenen un total de 0 lletres
			if (num_lletres[i] != 0) 
				cout << i << " : " << num_lletres[i] << endl;
		}
		
		cout << endl;
	}
	
	
	
	
	
}
