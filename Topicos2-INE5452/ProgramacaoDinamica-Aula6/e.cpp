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

vector<vector<unsigned long long>> dp;

unsigned long long trib(int n, int back) {
    if(n<=1) return 1;
    if(dp[n][back] != -1) return dp[n][back];

    unsigned long long sum=1;
    
    for(int i = 1; i <= back; i++)
        sum += trib(n - i, back);

    return dp[n][back] = sum;
}

int main() {
    detachingFromC;
    dp.assign(62, vector<unsigned long long>(62, -1));
    int a,b;
    int c = 1;
    while(1) {
        cin >> a >> b;
        if(a > 60) break;
        
        cout << "Case " << c++ << ": " << trib(a,b) << endl;
    }

    return 0;
}