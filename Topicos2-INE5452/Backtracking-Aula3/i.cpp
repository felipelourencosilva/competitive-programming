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

bool ehValido(int linha, int coluna, vi &indexs) {
    for (int i = 0; i < linha; i++) {
        if (indexs[i] == coluna || abs(i - linha) == abs(indexs[i] - coluna)) return false;
    }
    
    return true;
}

int solve(int linha, vi &indexs) {
    if (linha >= 8) return 0;

    int res = INF;
    int aux = indexs[linha];

    for (int i = 0; i < 8; i++) {
        if (ehValido(linha, i, indexs)) {
            indexs[linha] = i;
            int sla = (i != aux) ? 1 : 0;
            res = min(res, sla + solve(linha + 1, indexs));
        } 
    }

    indexs[linha] = aux;
    return res;
}

int main() {
    detachingFromC;
    int n;
    int counter = 1;
    while(cin >> n) {
        vector<int> indexs(8);
        indexs[0] = n-1;

        for(int i = 1; i <= 7; i++) {
            cin >> n;
            indexs[i] = n-1;
        }   

        cout << "Case " << counter++ << ": " << solve(0, indexs ) << endl;
    }
    return 0;
}