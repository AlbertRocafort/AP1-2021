#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

//Parametres:
//	persones, manies i n: Informacio donada per l'entrada.
//	millor_combinacio i mania_menor: Ens ajuden a trobar la millor solucio
// 	combinacio, used i k: Ens ajuden a generar les combinacions
void genera(const vector<string>& persones, const Matrix& manies, int n, vector<int>& millor_combinacio, int& mania_menor, vector<int>& combinacio, vector<bool>& used, int mania, int k) {
	
	//Comprovem si la combinació que acabem de fer es millor que la millor que haviem trobat
	//Si ho es, actualitzem els valors de millor_combinacio i mania_menor
	if (k == n) {
		if (mania < mania_menor or mania_menor == -1) {
			millor_combinacio = combinacio;
			mania_menor = mania;
		}
	}
	
	//No hem acabat de fer la combinació
	else {
		for (int i = 1; i < n; i++) {
			//Mirem si ja hem colocat la persona i
			if (not used[i]) {
				//Si afegim aquesta persona, la nova suma de manies será menor a //	la millor que em trobat?
				//Si és així, la afegim i fem la crida recursiva
				//Si no és així, ja no fa falta que provem aquesta persona
				if (mania + manies[i][combinacio[k-1]] < mania_menor or mania_menor == -1) {
					combinacio[k] = i;
					used[i] = true;
					mania += manies[i][combinacio[k-1]];

					//Crida recursiva
					genera(persones, manies, n, millor_combinacio, mania_menor, combinacio, used, mania, k+1);
					
					//Indiquem que no hem utilitzat aquesta persona per seguir  //	provant les diferents combinacions
					used[i] = false;
					mania -= manies[i][combinacio[k-1]];
				}
			}
		}
	}
}



int main () {
	int n;
	
	while (cin >> n) {
		
		//Vector que contindrá el nom de les diferents persones
		vector<string> persones(n);
		for (int i = 0; i < n; i++) cin >> persones[i];
		
		//Matriu amb les manies de cada persona
		//A la posicio i,j hi ha la mania entre la persona i, i la persona j
		Matrix manies(n, Row(n));
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) cin >> manies[i][j];
		
		
		//Cas especial on n=1
		//Evitem crear molts vectors i fer crides innecessaries
		if (n == 1) {
			cout << 0 << endl;
			cout << persones[0] << endl;
		}
		
		//n>1
		else {
			//Vector que utilitzarem per provar les combinacions
			//Es de enters degut a que no guardarem la combinació com a tal
			//Si per exemple, en la posicio 3 del vector hi ha un 6, vol dir que en la 3a     //	posició de la combinació va la 6a persona
			vector<int> combinacio(n);
			combinacio[0] = 0;
			
			//Vector per controlar quines persones hem colocat en la combinacio
			vector<bool> used(n);
			used[0] = true;
			
			//Vector i enter on guardarem la informació de la millor combinació trobada fins el moment
			vector<int> millor_combinacio(n);
			int mania_menor = -1;
			
			//Backtracking
			genera(persones, manies, n, millor_combinacio, mania_menor, combinacio, used, 0, 1);
			//Imprimim la resposta
			cout << mania_menor << endl;
			cout << persones[0];
			for (int i = 1; i < n; i++) 
				cout << ' ' << persones[millor_combinacio[i]];
			cout << endl;
		}
	}
}
