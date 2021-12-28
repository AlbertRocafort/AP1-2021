#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;


bool comp (pair<int, int> r1, pair<int, int> r2) {
	
	//Comparem les areas
	int a1 = r1.first * r1.second;
	int a2 = r2.first * r2.second;
	if (a1 < a2) return true;
	if (a1 > a2) return false;
	
	//Comparem els perimetres
	int p1 = r1.first + r1.second;
	int p2 = r2.first + r2.second;
	if (p1 > p2) return true;
	if (p1 < p2) return false;

	//Comparem les amplades
	return (r1.first < r2.first);
}

int main () {
	int n;
	while (cin >> n) {
		vector<pair<int, int> > rectangles(n);
		int x, y;
		
		//LLegim n rectangles definits com x = amplada i y = alçada
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			rectangles[i] = {x,y};
		}
		
		//Els ordenem segons el criteri definit en la funcio comp
		sort(rectangles.begin(), rectangles.end(), comp);
		
		//Els imprimim per pantalla
		for (int i = 0; i < n; i++) cout << rectangles[i].first << ' ' << rectangles[i].second << endl;
		cout << "----------" << endl;
	}
}