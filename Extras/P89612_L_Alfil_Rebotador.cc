#include <iostream>
#include <vector>
using namespace std;

// using Fila = vector<char>;
// using Matriu = vector<Fila>;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;

void escriu(const Matriu& M)
{
    int n = M.size();
    int l = M[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            cout << M[i][j];
        }
        cout << endl;
    }
}

bool cantonada(int x, int y, const Matriu& M)
{
    int n = M.size();
    int l = M[0].size();
    if (x == 0 and y == n - 1)
        return true;
    if (x == l - 1 and y == 0)
        return true;
    if (x == l - 1 and y == n - 1)
        return true;

    return false;
}

void mov_alfil(Matriu& M)
{
    /*la d diu en quina direccio va l'alfil (d=0, diagonal cap a la dreta i cap abaix,
    d=1 diagonal cap a la dreta i cap a dalt, d=2 diagonal cap a l'esquerra i cap a dalt,
    d=3, diagonal cap a l'esquerra i cap a baix)*/
    int d = 0;

    //x i y son la posicio de l'alfil
    int x = 0;
    int y = 0;

    int n = M.size();
    int l = M[0].size();

    while (not cantonada(x, y, M)) {
        
        if (d == 0) {
            while (y < n - 1 and x != l - 1) {
                M[y][x] = 'X';
                ++x;
                ++y;
            }
            M[y][x] = 'X';
            
            // Si anavem cap a baix a la dreta i toquem amb la paret de baix, anirem cap a dalt a la dreta
            if (y == n-1) d = 1;
            
            // Si anavem cap a baix a la dreta i toquem amb la paret de la dreta, anirem cap a baix a l'esquerra
			else d = 3;
        }

        else if (d == 1) {
            while (y > 0 and x != l - 1) {
                M[y][x] = 'X';
                ++x;
                --y;
            }
            M[y][x] = 'X';

			// Si anavem cap a dalt a la dreta i toquem amb la paret de dalt, anirem cap a baix a la dreta
            if (y == 0) d = 0;
            
            // Si anavem cap a dalt a la dreta i toquem amb la paret de la dreta, anirem cap a dalt a l'esquerra
			else d = 2;

        }

        else if (d == 2) {
            while (y > 0 and x != 0) {
                M[y][x] = 'X';
                --x;
                --y;
            }
            M[y][x] = 'X';

			// Si anavem cap a dalt a l'esquerra i toquem amb la paret de dalt, anirem cap a baix a l'esquerra
            if (y == 0) d = 3;
            
            // Si anavem cap a dalt a l'esquerra i toquem amb la paret de l'esquerra, anirem cap a dalt a la dreta
			else d = 1;
        }

        else {
            while (y < n - 1 and x != 0) {
                M[y][x] = 'X';
                --x;
                ++y;
            }
            M[y][x] = 'X';
            
            // Si anavem cap a baix a l'esquerra i toquem amb la paret de baix, anirem cap a dalt a l'esquerra
            if (y == 0) d = 2;
            
            // Si anavem cap a baix a l'esquerra i toquem amb la paret de l'esquerra, anirem cap a baix a la dreta
			else d = 0;
        }
    }
}

int main()
{
    int a;
    int b;
    while (cin >> a >> b) {
        Matriu M(a, Fila(b, '.'));
        mov_alfil(M);
        escriu(M);
    }
}

