#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Paraula {
	string s;
	int f;
};


bool ordena (const Paraula& a, const Paraula& b) {
	if (a.f > b.f) return true;
	if (b.f > a.f) return false;
	
	return a.s < b.s;
}


int main() {
	
	int n, k;
	while (cin >> n >> k) {
		
		//Llegim totes les paraules
		vector<string> paraules(n);
		for (int i = 0; i < n; i++) {
			cin >> paraules[i];
		}
		
		//Ordenem el vector de paraules
		sort(paraules.begin(), paraules.end());
		
		//Fem un vector buit de paraules i les seves repeticions
		vector<Paraula> frequencies(0);
		
		Paraula aux = {paraules[0], 1};
		for (int i = 1; i < n; i++) {
			
			if (aux.s == paraules[i]) aux.f++;
			else {
				frequencies.push_back(aux);
				aux = {paraules[i], 1};
			}
		}
		frequencies.push_back(aux);
		
		//Ordenem el vector en funcio de les repeticions
		sort(frequencies.begin(), frequencies.end(), ordena);
		
		//Imprimim les k paraules mes repetides
		for (int i = 0; i < k; i++)
			cout << frequencies[i].s << endl;
		cout << "----------" << endl;
	}
	
}