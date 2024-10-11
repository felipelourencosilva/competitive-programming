#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    while(1) {
        cin >> n;
        if(!n) break;
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            cin >> num;
            if(num != 0) nums.push_back(num);
        }

        if(nums.size() == 0) {
            cout << 0 << endl;
            continue;
        } else {
            cout << nums[0];
            for(int i = 1; i < nums.size(); i++) {
                cout << " " << nums[i];
            }
            cout << endl;
        }

        
    }
    return 0;
}