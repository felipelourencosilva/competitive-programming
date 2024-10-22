#include <bits/stdc++.h>
using namespace std;

#define detachingFromC ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

string str1, str2;

int lcs(int i, int j, vector<vector<int>> &dp) {
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i-1] == str2[j-1]) return dp[i][j] = lcs(i-1, j-1, dp) + 1;
    
    return dp[i][j] = max(lcs(i, j-1, dp), lcs(i-1, j, dp));
}

int main() {
    detachingFromC;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.size()+1, vector<int> (str2.size()+1, -1));
    lcs(str1.size(), str2.size(), dp);

    string res = "";

    int i = str1.size(), j = str2.size();
    while(i >= 1 && j >= 1) {
        if(str1[i-1] == str2[j-1]){
            res = str1[i-1] + res;
            i--;j--;
        } else if(dp[i-1][j] >= dp[i][j-1]) i--;
        else j--;
    }

    cout << res << endl;
    return 0;
}