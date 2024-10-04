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

int n,m; 
vi andares;

bool verifica(int k) {
    for(int i = 1; i < andares.size(); i++) {
        if(andares[i] - andares[i-1] > k) return false;
        else if(andares[i] - andares[i-1] == k) k--;
    }

    return true;
}

int binarySearch(int low, int high) {
    if(high - low == 0) return high; 

    int mid = (low+high) /2;
    if(verifica(mid)) return binarySearch(low, mid);
    else return binarySearch(mid+1, high);
}

int main() {
    detachingFromC;
    cin >> n;
    for(int k = 1; k <= n; k++) {
        cin >> m;
        andares.assign(m+1, 0);
        for(int i = 1; i <= m; i++) {
            cin >> andares[i];
        }

        cout << "Case " << k << ": " << binarySearch(1,INF) << endl;
    }
    return 0;
}