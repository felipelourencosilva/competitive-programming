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

vector<int> coins;
vector<vector<int>> dp;

int coinChange(int remCap, int ind) {
    if(remCap == 0) return 0;
    if(ind < 0 || remCap < 0) return INF;
    if(dp[remCap][ind] != -1) return dp[remCap][ind];
    return dp[remCap][ind] = min(1 + coinChange(remCap-coins[ind], ind-1), 
                                coinChange(remCap, ind-1));
}

signed main() {
    detachingFromC;
    int t, n, amount; cin >> t;
    while(t--) {
        cin >> amount;
        cin >> n;
        coins.resize(n);
        int maior = 0;
        for(int i = 0; i < n; i++) {
            cin >> coins[i];
            maior = max(maior, coins[i]);
        }
        dp.assign(amount+maior+10, vector<int>(n, -1));
        int aux2 = coinChange(amount, n-1);
        if(aux2 != INF) cout << amount << " " << aux2 << endl;
        else {
            for(int i = amount+1; i < dp.size(); i++) {
                int aux = coinChange(i, n-1);
                if(aux != INF) {
                    cout << i << " " << aux << endl;
                    break;
                }
            }
        }

        /*for(auto sla : dp) {
             cout << sla << " ";
        }
        cout << endl;*/
    }

    return 0;
}