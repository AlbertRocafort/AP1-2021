#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<char> > MatrixC;
typedef vector<vector<int> > MatrixI;

void comprovaHoritzontal(const string& paraula, const MatrixC& caracters, const MatrixI& puntuacions, int x, int y, int& puntuacio) {
	
	int suma_punts = 0;
	int k = 0; // Index per iterar totes les lletres de la paraula
	bool final = false; // El posarem a true si trobem un caracter que no coincideix
	
	// Iterem per totes les lletres de la paraula o fins que trobem un caracter diferent
	while (k < paraula.size() and not final) {
		
		// Anem comprovant que els caracters coincideixen
		if (paraula[k] == caracters[x][y+k])
			suma_punts += puntuacions[x][y+k];
		else
			final = true;
		
		k++;
	}
	
	// Si no hem trobat cap caracter diferent i la puntuacio es superior a la que teniem guardada
	if (not final and suma_punts > puntuacio)
		puntuacio = suma_punts;
}

void comprovaVertical(const string& paraula, const MatrixC& caracters, const MatrixI& puntuacions, int x, int y, int& puntuacio) {

	int suma_punts = 0;
	int k = 0; // Index per iterar totes les lletres de la paraula
	bool final = false; // El posarem a true si trobem un caracter que no coincideix
	
	// Iterem per totes les lletres de la paraula o fins que trobem un caracter diferent
	while (k < paraula.size() and not final) {
		
		// Anem comprovant que els caracters coincideixen
		if (paraula[k] == caracters[x+k][y])
			suma_punts += puntuacions[x+k][y];
		else
			final = true;
		
		k++;
	}
	
	// Si no hem trobat cap caracter diferent i la puntuacio es superior a la que teniem guardada
	if (not final and suma_punts > puntuacio)
		puntuacio = suma_punts;
}


int main() {
	
	int f, c;
	while(cin >> f >> c) {
		
		MatrixC caracters(f, vector<char>(c));
		MatrixI puntuacions(f, vector<int>(c));
		
		// LLegim les dos matrius
		for (int i = 0; i < f; i++) 
			for (int j = 0; j < c; j++)
				cin >> caracters[i][j];
				
		for (int i = 0; i < f; i++) 
			for (int j = 0; j < c; j++)
				cin >> puntuacions[i][j];
				
				
		int numParaules;
		cin >> numParaules;
		
		// A cada iteracio llegirem una paraula i buscarem la seva puntuacio
		for (int i = 0; i < numParaules; i++) {
			
			// Llegim la paraula
			string paraula;
			cin >> paraula
			
			int puntuacio = -1;
			
			// Iterem per tota les lletres de la matriu
			for (int x = 0; x < f; x++) {
				for (int y = 0; y < c; y++) {
					
					// Buquem les aparicions de la 1a lletra de la paraula
					if (caracters[x][y] == paraula[0]) {
						
						// Comprovem que hi ha espai suficient per la dreta
						if (y + paraula.size() -1 < c) {
							// Comprovem si es troba la paraula a parti de la posicio x, y
							comprovaHoritzontal(paraula, caracters, puntuacions, x, y, puntuacio);
						}
						
						// Comprovem que hi ha espai suficient per sota
						if (x + paraula.size() -1 < f) {
							// Comprovem si es troba la paraula a parti de la posicio x, y
							comprovaVertical(paraula, caracters, puntuacions, x, y, puntuacio);
						}
					}
				}
			}
			
			if (puntuacio == -1) cout << "no" << endl;
			else cout << puntuacio << endl;
		}
	}
}
