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
double p,q,r,s,t,u;

double formula(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t*x*x + u;
}

double binarySearch(double low, double high) {
    if(high-low <= EPS) return (low + high) / 2.0;

    double mid = (low + high) / 2.0;
    double res = formula(mid);

    if (abs(res) < EPS) return mid;

    if (res > 0) return binarySearch(mid, high);
    else return binarySearch(low, mid);

}

int main() {
    detachingFromC;
    while(cin >> p >> q >> r >> s >> t >> u) {

        if (formula(0.0) * formula(1.0) > 0) {
            cout << "No solution" << endl;
            continue;
        }

        double res = binarySearch(0.0, 1.0);
        cout << fixed << setprecision(4) << res << endl;
    }
    return 0;
}