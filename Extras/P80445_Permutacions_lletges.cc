#include <iostream>
#include <vector>
using namespace std;

void pintar_permutacio(int n, const vector<int>& sol, int compt)
{
    for (int i = 0; i < n; ++i) {
    	if (i > 0) cout << ' ';
        cout << sol[i];
    }
    cout << endl;
}

void permutacions_lletges(int n, int d, int m, vector<int>& sol_parcial, vector<bool>& hi_es, vector<bool>& ja_def, int& compt, int k)
{
    if (k == (n - m)) {
        if (d == compt) {
            pintar_permutacio(n, sol_parcial, compt);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (compt <= d) {
                if (not hi_es[i]) {
                    sol_parcial[k] = i;
                    hi_es[i] = true;
                    if (k != 0) {
                        if (sol_parcial[k - 1] == sol_parcial[k] - 1 or sol_parcial[k - 1] == sol_parcial[k] + 1) {
                            ++compt;
                        }
                    }
                    if (sol_parcial[k + 1] != -1) {
                        if (k < n - 1) {
                            if (sol_parcial[k] == sol_parcial[k + 1] - 1 or sol_parcial[k] == sol_parcial[k + 1] + 1) {
                                ++compt;
                            }
                        }
                    }
                    permutacions_lletges(n, d, m, sol_parcial, hi_es, ja_def, compt, k + 1);
                    if (not ja_def[i]) {
                        hi_es[i] = false;
                        compt = 0;
                        sol_parcial[k] = -1;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, d, m;
    while (cin >> n >> d >> m) {
        vector<int> sol_parcial(n, -1);
        vector<bool> ja_def(n, false);
        for (int i = 0; i < m; ++i) {
            int j, x;
            cin >> j >> x;
            sol_parcial[j] = x;
            ja_def[x] = true;
        }
        int compt = 0;
        vector<bool> hi_es(n);
        hi_es = ja_def;
        permutacions_lletges(n, d, m, sol_parcial, hi_es, ja_def, compt, 0);
        cout << "********************" << endl;
    }
}
