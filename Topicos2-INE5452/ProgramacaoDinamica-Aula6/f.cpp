#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;
#define int long long
#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n, a;
vector<vector<int>> dp;

int solve(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i >= j) {
        int op1 = 0;
        int op2 = 0;
        int m;
        if(i < n) {
            m = 0;
            for(int k = i+1; k <= n; k++) {
                m = max(m, solve(k, 1) + solve(k, j));
            }
            op1 = m;
        };

        if(j > 0) {
            m = 0;
            for(int k = 1; k < j; k++) {
                m = max(m, solve(i, k) + solve(n, k));
            }
            op2 = m;
        };

        return dp[i][j] = op1+op2;
    } else {
        int m = -1;
        for(int k = i; k < j; k++) {
            m = max(m, solve(i, k) + solve(k+1, j));
        }
        return dp[i][j] = m;
    }
}

signed main() {
    detachingFromC;
    while(cin >> n >> a) {
        dp.assign(n+2, vector<int>(n+2, -1));
        dp[n][1] = a;
        cout << solve(1, n) << endl;
    }

    return 0;
}