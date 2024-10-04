#include <bits/stdc++.h>
using namespace std;
#define double long double
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const int LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-6;

#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)


double t, n, A,B,C, x, y;
vector<pair<double,double>> warehouses;

double dist(pair<double,double> p1, pair<double,double> p2) {
    return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

double distSum(double x) {
    double y = -(C+A*x) / B;
    double soma = 0.0;

    for (int i = 0; i < n; i++) {
        soma += dist({x, y}, warehouses[i]);
    }
    return soma;
}

double minDist;
void ternarySearch(double low, double high) {
    if (high - low <= EPS) {
        minDist = min(distSum((low+high)/2), minDist);
        return;
    }

    double a = (2 * low + high) / 3;
    double b = (low + 2 * high) / 3;

    double distA = distSum(a);
    double distB = distSum(b);

    if (distA > distB) {
        minDist = min(distB, minDist);
        return ternarySearch(a, high);
    } else {
        minDist = min(distA, minDist);
        return ternarySearch(low, b);
    }
}

int main() {
    detachingFromC;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> A >> B >> C;
        warehouses.resize(n);
        minDist = 1000000000000.0;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            warehouses[i] = {x,y};
        }
        ternarySearch(-10000000.0, 10000000.0);
        cout << fixed << setprecision(6) << minDist << endl;
    }
    return 0;
}