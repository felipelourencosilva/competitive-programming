#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e6+1;
const int LLINF = 4e18;
const double EPS = 1e-9;

#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int soma(int x) {
    int res = 0;
    while(x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    detachingFromC;
    int n,k, num;
    cin >> n >> k;
    vi vezes(INF, 0);

    for(int i = 0; i < n; i++) {
        cin >> num;
        vezes[num]++;
    }

    bool flag = false;
    for(int i = INF; i > 0; i--) {
        if(vezes[i]) {
            int s = soma(i);
            if(k > vezes[i]) {
                k -= vezes[i];
                vezes[i-s] += vezes[i];
            } else {
                cout << s << endl;
                flag = true;
                break;
            }
        }
    }

    if(!flag) cout << 0 << endl;
    return 0;
}