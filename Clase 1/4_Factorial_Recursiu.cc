#include<iostream>
using namespace std;

int factorial(int n) {

	// Cas Base
	if (n <= 1) {
		return 1;
	}
		
	// Cas Recursiu
	else {
		return n * factorial(n-1);
	}
	
}

int main() {
	
	cout << factorial(0) << endl;
	cout << factorial(1) << endl;
	cout << factorial(2) << endl;
	cout << factorial(3) << endl;
	cout << factorial(4) << endl;
	
}
