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

vector<vi> solve(int t, int n, vi &nums) {
    vector<vi> res;
    map<vi, int> exist;
    int mask = 1 << n;

    for(int i = 0; i < mask; i++) {
        vi aux;
        int soma = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                soma += nums[j];
                aux.push_back(nums[j]);
            }
        }

        if(soma == t && exist[aux] != 1) {
            exist[aux] = 1;
            res.push_back(aux);
        }
    }

    return res;
}

int main() {
    detachingFromC;
    int t, n;
    while(1) {
        cin >> t;
        if(!t) {
            cin >> n;
            break;
        }

        cin >> n;
        vi nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<vi> res = solve(t, n, nums);

        sort(res.rbegin(), res.rend());
        cout << "Sums of " << t << ":" << endl;
        if(res.size() >0) {
            for(int i = 0; i < res.size(); i++) {
                cout << res[i][0];
                for(int j = 1; j < res[i].size(); j++) {
                    cout << "+" << res[i][j];
                }
                cout << endl;
            }
        } else cout << "NONE" << endl;
        
    }
    return 0;
}