#include <bits/stdc++.h>
using namespace std;

#define detachingFromC ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

string str1, str2;
vector<vector<int>> dp;

int editDistance(int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (dp[i][j] != -1) return dp[i][j];

    if (str1[i - 1] == str2[j - 1]) dp[i][j] = editDistance(i - 1, j - 1);
    else {
        dp[i][j] = 1 + min({
            editDistance(i, j - 1),
            editDistance(i - 1, j),
            editDistance(i - 1, j - 1)
        });
    }

    return dp[i][j];
}

int main() {
    detachingFromC;
    int t; cin >> t;
    while(t--) {
        cin >> str1 >> str2;
        dp.assign(str1.size()+1, vector<int>(str2.size()+1, -1));
        cout << editDistance(str1.size(), str2.size()) << endl;
    }
    return 0;
}