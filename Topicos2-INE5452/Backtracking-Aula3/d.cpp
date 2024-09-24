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

vector<int> solve(int a, int b, int c) {
    for(int x = -100; x <= 100; x++) {
        for(int y = -100; y <= 100; y++) {
            for(int z = -100; z <= 100; z++) {
                if((x != y && y != z && x != z) && x+y+z == a && x*y*z == b && x*x+y*y+z*z == c) {
                    return {x, y ,z};
                }
            }
        }
    }

    return {-1, -1, -1};
}

int main() {
    detachingFromC;
    int k, a, b, c; cin >> k;
    while(k--) {
        cin >> a >> b >> c;

        vector<int> res = solve(a, b, c);
        sort(res.begin(), res.end());

        if(res[0] == -1) cout << "No solution." << endl;
        else cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }
    return 0;
}