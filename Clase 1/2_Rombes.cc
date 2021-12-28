#include<iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	// Bucle per la 1a meitat
	for (int i = 1; i <= n; i++) {
		
		// Bucle pels espais en blanc
		for (int j = 0; j < n-i; j++) {
			cout << ' ';
		}
		
		// Bucle pels asteriscos
		for (int j = 0; j < 2*i-1; j++) {
			cout << '*';
		}
		
		cout << endl;		
	}
	
	
	// Bucle per la 2a meitat
	for (int i = n-1; i > 0; i--) {
		
		// Bucle pels espais en blanc
		for (int j = 0; j < n-i; j++) {
			cout << ' ';
		}
		
		// Bucle pels asteriscos
		for (int j = 0; j < 2*i-1; j++) {
			cout << '*';
		}
		
		cout << endl;
		
	}
	
}
