#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const int LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct Domino{
    int esquerda, direita;

    Domino() : esquerda(0), direita(0) {}
    Domino(int esquerda, int direita) : esquerda(esquerda), direita(direita) {}
};

int n, m, esq, dir;
vector<Domino> dominos;

bool ehCompativel(int ind, int i, Domino domino, map<int,int> &usadas) {
    if(usadas[i] == 1) return false;

    if(ind == n-2) {
        return (domino.esquerda == dominos[ind - 1].direita && domino.direita == dominos[n - 1].esquerda);
    } else {
        return (domino.esquerda == dominos[ind - 1].direita);
    }
}

bool solve(vector<Domino> &pecas, int ind, map<int,int> &usadas) {
    if(ind == n-1) return true;
    
    for(int i = 0; i < pecas.size(); i++) {
        if(ehCompativel(ind, i, pecas[i], usadas)) {
            dominos[ind] = pecas[i];
            usadas[i] = 1;
            if(solve(pecas, ind+1, usadas)) return true;
            usadas[i] = 0;
        }

        Domino invertido = pecas[i];
        swap(invertido.direita, invertido.esquerda);
        if (ehCompativel(ind, i, invertido, usadas)) {
            dominos[ind] = invertido;
            usadas[i] = 1;
            if (solve(pecas, ind + 1, usadas)) return true;
            usadas[i] = 0;
        }
    }

    return false;
}

int main() {
    detachingFromC;

    while(1) {
        cin >> n;
        if(!n) break;
        n += 2;
        cin >> m;

        map<int,int> usadas;
        dominos.resize(n);

        cin >> esq >> dir;
        dominos[0] = Domino(esq, dir);
        cin >> esq >> dir;
        dominos[n-1] = Domino(esq, dir);

        vector<Domino> pecas(m);
        for(int i = 0; i < m; i++) {
            cin >> esq >> dir;
            pecas[i] = Domino(esq, dir);
        }

        if(solve(pecas, 1, usadas)) cout << "YES" << endl;
        else cout << "NO" << endl;

        /*for(int i = 0; i < n; i++) {
            cout << "[" << dominos[i].esquerda << " " << dominos[i].direita << "] ";
        }

        cout << endl;*/
    }
    return 0;
}