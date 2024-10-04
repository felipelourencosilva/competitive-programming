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

double exp(double base, ll exp) {
    double b = base, res = 1.0;
    while (exp) {
        if (exp & 1) res = (res * b);
        b = (b * b);
        exp /= 2;
    }
    return res;
}

vector<double> cfs;

double binarySearch(double low, double high) {
    if ((high - low) < EPS) return high;

    double mid = (low+high) / 2.0;

    double soma = cfs[0];

    for(int i = 1; i < cfs.size(); i++) {
        double divisor = exp(1+mid, i);

        soma += cfs[i]/divisor;
    }

    if (soma > 0.0) return binarySearch(mid, high);
    else return binarySearch(low, mid);
}

int main() {
    detachingFromC;
    int n;
    while(1) {
        cin >> n;
        if(!n) break;
        cfs.resize(n + 1);
        for(int i = 0; i < n+1; i++) {
            cin >> cfs[i];
        }
        double res = binarySearch(-0.99, 1000000000.0);
        if (abs(res + 1.0) <= EPS) cout << "No" << endl;
        else cout << fixed << setprecision(2) << res << endl;
            
    }
    return 0;
}