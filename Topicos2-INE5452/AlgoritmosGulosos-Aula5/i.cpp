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
    int n; cin >> n;

    vi ballons(n);
    map<int, int> used;
    for(int i = 0; i < n; i++) {
        cin >> ballons[i];
    }
    int soma = 0;
    for(int i = 0; i < n; i++) {
        if(used[ballons[i]] > 0) {
            used[ballons[i]]--;
            used[ballons[i]-1]++;
        } else {
            soma++;
            used[ballons[i]-1]++;
        }
    }

    cout << soma << endl;
    return 0;
}