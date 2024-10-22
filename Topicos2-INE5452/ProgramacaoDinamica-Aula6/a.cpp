#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> nums;

const int INF = 1e9+10;

int recursion(int ind) {
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int op1 = (ind-1 >= 0 ? abs(nums[ind-1] - nums[ind]) : 0) + recursion(ind-1);
    int op2 = (ind-2 >= 0 ? abs(nums[ind-2] - nums[ind]) : INF) + recursion(ind-2);
    dp[ind] = min(op1, op2);
    return dp[ind];
}

signed main() {
    int n; cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dp.assign(n+1, -1);
    int res = recursion(nums.size()-1);
    printf("%d\n", res);
    return 0;
}