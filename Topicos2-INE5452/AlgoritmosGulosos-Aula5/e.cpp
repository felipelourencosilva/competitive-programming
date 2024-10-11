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

int main() {
    detachingFromC;
    int n;
    while(1) {
        cin >> n;
        if(!n) break;
        vi bagagens(n);
        map<int,int> b;
        int maior = 0;
        for(int i = 0; i < n; i++) {
            cin >> bagagens[i];
            b[bagagens[i]]++;
            maior = max(maior, b[bagagens[i]]);
        }

        sort(bagagens.begin(), bagagens.end());

        vector<vector<int>> mochilas(maior);

        int ind = 0;
        for(int i = 0; i < n; i++) {
            mochilas[ind].push_back(bagagens[i]);
            ind = (ind+1) % maior;
        }

        cout << maior << endl;
        for(int i = 0; i < maior; i++) {
            cout << mochilas[i][0];
            for(int j = 1; j < mochilas[i].size(); j++) {
                cout << " " << mochilas[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}