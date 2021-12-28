#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;


bool comprovaSubmatriu(const Matrix& M, int i, int j) {
	
	// La 1a posicio guardara si hem trobat un 1
	// La 2a posicio guardara si hem trobat un 2
	// ...
	vector<bool> nums(9, false);
	
	for (int x = i; x < i+3; x++) {
		for (int y = j; y < j+3; y++) {
			
			int numero = M[x][y];
			
			// El numero ja l'hem trobat abans
			if (nums[numero-1])
				return false;
			
			// El numero no l'haviem trobat aixi que el marquem con trobat
			else
				nums[numero-1] = true;
		}
	}
	
	return true;
}




int main() {
	
	int f, c;
	while (cin >> f >> c) {
		
		Matrix M(f, Row(c));
		
		// Llegir la matriu
		for (int i = 0; i < f; i++)
			for (int j = 0; j < c; j++)
				cin >> M[i][j];
				
				
		int contador_submatrius = 0;
		
		for(int i = 0; i < f-2; i++) {
			for (int j = 0; j < c-2; j++) {
				
				if (comprovaSubmatriu(M, i, j))
					contador_submatrius++;
			}
		}
		cout << contador_submatrius << endl;
	}
	
}
