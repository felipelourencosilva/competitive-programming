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

struct Constraint {
    int u, v, value;
    Constraint(int u, int v, int value) : u(u), v(v), value(value){};
};

ll solve(vi &seats, vector<Constraint> &constraints) {
    ll soma = 0;
    vi indexs(seats.size());
    do {
        bool flag = true;
        for(int i = 0; i < seats.size(); i++) {
            indexs[seats[i]] = i;
        }

        for(auto c : constraints) {
            if(c.value >= 0) {
                if(abs(indexs[c.u] - indexs[c.v]) > c.value) {
                    flag = false;
                }
            } else {
                if(abs(indexs[c.u] - indexs[c.v]) < abs(c.value)) {
                    flag = false;
                }
            }
            
        }   

        if(flag) soma++;
    }while(next_permutation(seats.begin(), seats.end()));

    return soma;
}

int main() {
    detachingFromC;
    int n, m, u, v, value;
    while(1) {
        cin >> n >> m;
        if(!n) break;

        vi seats(n);
        for(int i = 0; i < n; i++) {
            seats[i] = i;
        }

        vector<Constraint> constraints;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> value;
            constraints.push_back(Constraint(u,v,value));
        }

        cout << solve(seats, constraints) << endl;
    }
    return 0;
}