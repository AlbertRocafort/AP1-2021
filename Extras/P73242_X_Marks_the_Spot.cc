#include<iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	
	// Part de dalt
	for(int i = 0; i < n/2; i++) {
		
		// Espais en blanc
		for (int j = 0; j < i; j++) cout << ' ';
			
		cout << '\\';
		
		// Escriure espais en blanc
		// Cada cop menys
		for (int j = 0; j < n-((i+1)*2); j++) cout << ' ';
		
		cout << '/' << endl;
	}
	
	
	// X del mig
	if (n % 2 == 1) {
		for (int i =0; i < n/2; i++) cout << ' ';
		cout << 'X' << endl;
	}
	
	
	// Part de baix
	for(int i = n/2-1; i >= 0; i--) {
		
		// Espais en blanc
		for (int j = 0; j < i; j++) cout << ' ';
			
		cout << '/';
		
		// Escriure espais en blanc
		// Cada cop menys
		for (int j = 0; j < n-((i+1)*2); j++) cout << ' ';
		
		cout << '\\' << endl;
	}
	
	
	
}
