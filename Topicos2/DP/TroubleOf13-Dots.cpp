#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int capacity, n;

int knapsack(vector<int> &weights, vector<int> &values) {
    int aux = capacity;
    if (aux > 1800) aux += 200;
    vector<int> dp(aux + 1, 0);
    
    for (int i = 0; i < n; ++i)
        for (int j = aux; j >= weights[i]; --j) 
        {
            if (dp[j - weights[i]] > 0 || j == weights[i])
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
            
    int result = 0;
    if (capacity >= 1801 && capacity <= 2000){
        result = *max_element(dp.begin(), dp.begin() + capacity);
        for (int j = 2001; j <= aux; ++j)
            result = max(result, dp[j]);
    } else
        result = *max_element(dp.begin(), dp.end());
    
    return result;
}

int main()
{
    while(scanf("%d %d", &capacity, &n) != EOF){
        vector<int> weights(n);
        vector<int> values(n);
        int w,v;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &w, &v);
            weights[i] = w;
            values[i] = v;
        }
        
        int result;
        result = knapsack(weights, values);
        
        cout << result << endl;
    }

    return 0;
}