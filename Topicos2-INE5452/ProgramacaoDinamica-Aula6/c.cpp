#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;
#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n,k,m;
vector<vector<vector<ll>>> dp;

ll solve(int n1, int k1, int m1) {
    if(n1 == n){
        if(!k1) return 1;
        return 0;
    }

    if(!k1) return 0;

    if(dp[n1][k1][m1] != -1) return dp[n1][k1][m1];

    if(m1) return dp[n1][k1][m1] = solve(n1+1, k1, m1-1) + solve(n1+1, k1-1, m-1);
    return dp[n1][k1][m1] = solve(n1+1, k1-1, m-1);
}

int main() {
    detachingFromC;
    while(cin >> n >> k >> m) {
        dp.assign(52, vector<vector<ll>>(52, vector<ll>(52, -1)));
        cout << solve(0, k, m-1) << endl;
    }

    return 0;
}