#include<iostream>
#include<vector>
using namespace std;


void print(const vector<vector<bool> >& taulell) {
	
	int n = taulell.size();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (taulell[i][j]) cout << 'K';
			else cout << '.';
		}
		cout << endl;
	}
	
	cout << "----------" << endl;
}


bool casella_amenacada (const vector<vector<bool> >& taulell, int i, int j) {
	
	int n = taulell.size();
	
	if (i > 0) {
		if (j > 0 and taulell[i-1][j-1]) return true;
		if (taulell[i-1][j]) return true;
		if (j < n-1 and taulell[i-1][j+1]) return true; 
	}
	if (j > 0 and taulell[i][j-1]) return true;
	if (j < n-1 and taulell[i][j+1]) return true;
	if (i < n-1) {
		if (j > 0 and taulell[i+1][j-1]) return true;
		if (taulell[i+1][j]) return true;
		if (j < n-1 and taulell[i+1][j+1]) return true;
	}
	
	return false;
}


void genera(vector<vector<bool> >& taulell, int reisMax, int reisColocats, int i, int j) {
	
	int n = taulell.size();
	
	//Hem colocat tots els reis
	if (reisColocats == reisMax) print(taulell);
	
	//No hem colocat i evaluem una posicio dintre del taulell
	else if (i < n and j < n){
		
		if (not casella_amenacada(taulell, i, j)) {
			taulell[i][j] = true;
			genera(taulell, reisMax, reisColocats+1, i, j+1);
			taulell[i][j] = false;
		}
		
		genera(taulell, reisMax, reisColocats, i, j+1);
	}
	
	//La casella que evaluem no esta dintre del taulell pero la podem recolocar
	else if (i < n) {
		genera(taulell, reisMax, reisColocats, i+1, 0);
	}
}


int main() {
	
	int n, r;
	cin >> n >> r;
	
	vector<vector<bool> > taulell(n, vector<bool>(n, false));
	
	genera(taulell, r, 0, 0, 0);
	
}