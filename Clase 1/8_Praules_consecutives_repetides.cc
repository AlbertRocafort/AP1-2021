#include<iostream>
using namespace std;


int main() {
	
	// s1 servira per guardar la paraula mes gran de les dos que tenim
	string s1, s2;
	
	cin >> s1;
	while (cin >> s2 and s2 != "END") {
		
		// La paraula que acabem de llegir (s2) es mes petita que la que tenim guardada (s1)
		if (s2 < s1) {
			cout << s2 << endl
		}
		
		// La que teniem guardada (s1) es mes petita que la que acabem de llegir (s2)
		else {
			cout << s1 << endl;
			
			// Guardem la paraula que acabem de llegir
			s1 = s2;
		}
		
	}
	
}
