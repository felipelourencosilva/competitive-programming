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

int value = 0;
int n;

int solve(vector<int> &nums, int num, int ind) {
    if(num > value) return 0;
    if(num == value) return 1;

    int res = 0;
    for(int i = ind; i < n; i++) {
        res = max(res, solve(nums, nums[i] + num, i+1));
    }

    return res;
}

int main() {
    detachingFromC;
    int k; cin >> k;
    while(k--) {
        cin >> value;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n;i++) {
            cin >> nums[i];
        }

        if(solve(nums, 0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}