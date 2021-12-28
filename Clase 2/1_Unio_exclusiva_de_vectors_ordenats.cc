#include<iostream>
#include<vector>
using namespace std;


vector<int> ex_union(const vector<int>& v1, const vector<int>& v2) {
	
	// Indexs per recorrer els vector
	int i = 0;
	int j = 0;
	
	// Vector amb el resultat
	vector<int> res;
	
	// Tamanys dels vectors
	int n1 = v1.size();
	int n2 = v2.size();
	
	
	// Iterem fins acabar un dels dos vectors
	while (i < n1 and j < n2) {
		
		int x = v1[i];
		int y = v2[j];
		
		// Controlem la 1a condicio: Que no sigui un element repetit en els 2 vectors
		if (x == y) {
			
			// Si son iguals, avancem i i j fins que apuntin a uns elements diferents
			while (i < n1 and v1[i] == x) i++;
			while (j < n2 and v2[j] == y) j++;
		}
		
		// Mirem quin dels dos es menor i l'afegim al vector resultant
		else if (x < y) {
			
			// Si x es menor l'afegim al vector resultant
			res.push_back(x);
			
			// Avancem i fins que trobem un nou element
			while (i < n1 and v1[i] == x) i++;
		}
		else {
			
			// Si x es menor l'afegim al vector resultant
			res.push_back(y);
			
			// Avancem i fins que trobem un nou element
			while (j < n2 and v2[j] == y) j++;
		}
	}
	
	
	while (i < n1) {
		
		// Afegim l'element de v1 a res
		int x = v1[i];
		res.push_back(x);
		
		// Avancem i fins trobar un element nou
		while (i < n1 and v1[i] == x) i++;
	}
	
	while (j < n2) {
		
		// Afegim l'element de v1 a res
		int y = v2[j];
		res.push_back(y);
		
		// Avancem i fins trobar un element nou
		while (j < n2 and v2[j] == y) j++;
	}
	
	return res;
}
