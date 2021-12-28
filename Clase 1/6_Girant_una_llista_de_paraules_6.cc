#include<iostream>
using namespace std;

void guarda_paraula(int& contador_paraules) {
	
	string s;
	if (cin >> s and s != "A") {
		
		contador_paraules++;
		int posicio_paraula = contador_paraules;
		
		guarda_paraula(contador_paraules);
	
		if (posicio_paraula <= contador_paraules / 2) {
			cout << s << endl;
		}
	}
}


int main() {
	int contador = 0;
	guarda_paraula(contador);
}
