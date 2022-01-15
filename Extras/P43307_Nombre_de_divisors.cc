#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// En aquest exercici s'han de tenir moltes coses en compte.

// Comencem per la creació del garbell:
//		Els bucles son els mateixos que el de crear el garbell original, pero en lloc de booleans, afegim enters
//		Es molt important la condicio "if (garbell[j] == 0)", ja que fa que a cada casella es trobi el divisor primer mes petit del numero
//		Aixo necessitarem que sigui aixi per contar correctament mes tard

vector<int> crea_garbell() {
	
	vector<int> garbell(1000001, 0);
	garbell[1] = 1;
	
	// Iterem pels sqrt(1000001) primers nums
	// Totes les caselles dels numeros no primers guardaran el seu divisor primer mes petit
	// Les caselles dels numeros primers contrindran un 0
	for (int i = 2; i*i < 1000001; i++) {
		
		// Comprobem que i es un nombre primer
		// Ho sabem pq si no ho fos, no tindria un 0, tindria el valor del seu divisor mes petit
		if (garbell[i] == 0) {
			
			// Emplenem les caselles del garbell que puguem amb i
			for (int j = i * 2; j > 0 and j < 1000001; j += i) {
				
				// Nomes emplenem la posició j amb i si aquest es el divisor mes petit
				// Si no es el mes petit, garbell[j] no guardara un 0
				if (garbell[j] == 0) garbell[j] = i;
			}
		}
	}
	
	return garbell;
}


// Per contar els divisors tindrem en compte una regla matemática:
//		Si n = a^x * b^y * c^z, essent a, b i c factors, i x, y, i z el número de cops que apareixen
//		el nombre de divisors ve donat per (x+1)*(y+1)*(z+1)

// Per tant el que farem es veure quants cops es repeteix cada factor, i aplicarem la formula
// Es important que, per no haver de guardar moltes dades, haguem creat be el garbell
// Si ho hem fet com he indicat a dalt, ens sortiran els factors en ordre de mes petit a mes gran, i els podrem comptar com en un exercici de tractament en sequencia.


int main() {
	
	// Creem el garbell
	vector<int> garbell = crea_garbell();
	
	// Llegim els nums
	int x;
	while (cin >> x) {
		
		// El comptador, com que l'anirem multiplicant, l'inicialitzem a 1
		int contador = 1;
		
		// Variables per portar el compte dels cops que apareix cada factor
		int aparicions_factor = 0;
		int factor = -1;
		
		while (x > 1)	{
			
			// Llegim del garbell el divisor mes petit de x
			int divisor;
			if (garbell[x] != 0) divisor = garbell[x];
			else divisor = x;
			
			// Si el divisor llegit es el mateix del que portavem el compte, augmentem el comptador
			if (divisor == factor) {
				aparicions_factor++;
			}
			
			// Si es diferent (com que surten de manera ordenada, sera mes gran)
			// llavors "acumulem" el recompte a contador i actualitzem les variables per portar el compte del nou factor
			else {
				contador *= (aparicions_factor+1);
				factor = divisor;
				aparicions_factor = 1;
			}
			
			// Dividim x pel divisor per anar a buscar el seguent
			x /= divisor;
		}
		
		// Es important no oblidarse "d'acumular" el recompte de l'ultim factor trobat
		contador *= (aparicions_factor+1);
		
		cout << contador << endl;
		
	}
	
}
