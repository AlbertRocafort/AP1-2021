#include<iostream>
using namespace std;


// Donades dues cadenes de caràcters x i y que representen dos naturals en base b
// i un natural b amb 2= b= 36
// retorna una cadena de caràcters z que representa la suma de x i y, també en base b.
string suma(int b, string x, string y) {
	
	// Tamany dels dos strings d'entrada
	int size_x = x.size();
	int size_y = y.size();
	
	string z = "";
	
	int carry = 0;
	
	
	// Iterarem per l'string mes curt
	int i = 1;
	while (i <= size_x and i <= size_y) {
		
		// Traduim els nums a sumar de carácter a enter
		int num_1, num_2;
		
		if (x[size_x - i] >= '0' and x[size_x - i] <= '9') num_1 = x[size_x - i] - '0';
		else num_1 = x[size_x - i] + 10 - 'A';
		
		if (y[size_y - i] >= '0' and y[size_y - i] <= '9') num_2 = y[size_y - i] - '0';
		else num_2 = y[size_y - i] + 10 - 'A';
		
		
		// Valor de la suma dels dos nums i la que "ens emportavem"
		int suma = num_1 + num_2 + carry;
		
		// Mirem si ens emportem una
		if (suma < b) {
			carry = 0;
		}
		else {
			carry = 1;
			suma = suma % b;
		}
		
		// Traduim el valor de la suma dels dos dígits a caracter
		if (suma <= 9) {
			z = (char)(suma + '0') + z;
		}
		else {
			z = (char)(suma - 10 + 'A') + z;
		}
		
		i++;
	}
	
	// Acabem de completar amb el num mes llarg
	for (; i <= size_x; i++) {
		
		int num;
		if (x[size_x - i] >= '0' and x[size_x - i] <= '9') num = x[size_x - i] - '0';
		else num = x[size_x - i] + 10 - 'A';
		
		int suma = num + carry;
		
		// Mirem si ens emportem una
		if (suma < b) {
			carry = 0;
		}
		else {
			carry = 1;
			suma = suma % b;
		}
		
		// Traduim el valor de la suma dels dos dígits a caracter
		if (suma <= 9) {
			//cout << "Caracter Afegit: " << (char)(suma + '0') << endl;
			z = (char)(suma + '0') + z;
		}
		else {
			//cout << "Caracter Afegit: " << (char)(suma - 10 + 'A') << endl;
			z = (char)(suma - 10 + 'A') + z;
		}
	}
	for (; i <= size_y; i++) {
		
		int num;
		if (y[size_y - i] >= '0' and y[size_y - i] <= '9') num = y[size_y - i] - '0';
		else num = y[size_y - i] + 10 - 'A';
		
		int suma = num + carry;
		
		// Mirem si ens emportem una
		if (suma < b) {
			carry = 0;
		}
		else {
			carry = 1;
			suma = suma % b;
		}
		
		// Traduim el valor de la suma dels dos dígits a caracter
		if (suma <= 9) {
			z = (char)(suma + '0') + z;
		}
		else {
			z = (char)(suma - 10 + 'A') + z;
		}
	}
	
	if (carry == 1) z = '1' + z;
	
	return z;
}

int main() {
	int b;
	string x, y;
	while (cin >> b >> x >> y) {
		cout << suma(b, x, y) << endl;
	}
}
