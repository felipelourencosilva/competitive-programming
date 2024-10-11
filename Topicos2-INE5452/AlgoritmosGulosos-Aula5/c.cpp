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
    int l, g, x, r;
    while(1) {
        cin >> l >> g;
        if(!l && !g) break;

        vector<ii> intervalos(g);
        for(int i = 0; i < g; i++) {
            cin >> x >> r;
            intervalos[i] = {x-r, x+r};
        }

        sort(intervalos.begin(), intervalos.end());

        int dist = 0;
        int distaux = 0;
        int res = 0;
        int ind = 0;
        bool flag = true;

        while (dist < l) {
            while (ind < g && intervalos[ind].first <= dist) {
                distaux = max(distaux, intervalos[ind].second);
                ind++;
            }
            if (distaux == dist) {
                flag = false;
                break;
            }
            dist = distaux; res++;
        }

        if (flag) cout << g - res << endl;
        else cout << -1 << endl;
    }
    return 0;
}