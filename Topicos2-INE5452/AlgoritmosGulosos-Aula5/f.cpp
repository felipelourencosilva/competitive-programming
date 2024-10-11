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
    int b, s, num;
    int c = 1;
    while(1) {
        cin >> b >> s;
        if(!b && !s) break;
        int menor = INF;
        for(int i = 0; i < b; i++) {
            cin >> num;
            menor = min(menor, num);
        }
        for(int i = 0; i < s; i++) {
            cin >> num;
        }
        if(b > s) {
            cout << "Case " << c++ << ": " << b-s << " " << menor << endl;
        } else cout << "Case " << c++ << ": " << 0 << endl;

        
    }
    return 0;
}