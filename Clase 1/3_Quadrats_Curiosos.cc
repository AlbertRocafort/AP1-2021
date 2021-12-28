#include<iostream>
using namespace std;


int main() {
	
	int n;
	bool primer = true;
	
	while (cin >> n) {
		
		if (primer) primer = false;
		else cout << endl;
		
		// Algoritme que imprimeix el quadrat
		
		for (int i = 0; i < n; i++) {
			
			// Bucle del numero que es repeteix
			for (int j = 0; j <= i; j++) {
				cout << (n-i-1) % 10;
			}
			
			// Bucle per la compta enrere
			for (int j = i+1; j < n; j++) {
				cout << (n-j-1) % 10;
			}
			
			cout << endl;
		}
		
	}
	
}
