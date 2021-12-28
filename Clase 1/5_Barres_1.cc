#include<iostream>
using namespace std;

void barres(int n) {
	
	// Cas Base
	if (n == 1) {
		cout << '*' << endl;
	}
	
	// Cas Recursiu
	else {
		
		// Patro de n-1
		barres(n-1);
		
		// n asteriscos
		for (int i = 0; i < n; i++) cout << '*';
		cout << endl;
		
		// Patro de n-1
		barres(n-1);
	}
	
}

int main() {
	int n;
	cin >> n;
	barres(n);
}
