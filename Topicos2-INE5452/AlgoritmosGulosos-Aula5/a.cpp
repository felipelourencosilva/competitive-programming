#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n;
    for(int i = 0; i < n; i++) {

        cin >> m;
        vector<int> nums(m);
        for(int j = 0; j < m; j++) {
            cin >> nums[j];
        }

        long long soma = 1;

        int res = 1;
        if(nums.size() == 1) res = 1;
        else res = 2;
        for(int j = 1; j < m-1; j++) {
            soma+= nums[j];
            if(soma < nums[j+1]) {
                res++;

            } else {
                soma -= nums[j];
            }
            
            
        }

        cout << res << endl;
    }
    return 0;
}