#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

double floydwarshall(int n, vector<vector<double>> &adj) {
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
            }
        }
    }
    
    return adj[0][1];
}

int main()
{
    int c = 1;
    int n;
    scanf("%d", &n);
    while(n != 0) {
        map<int, pair<int,int>> int_points;
        vector<vector<double>> adj(n, vector<double>(n));
        
        int x,y;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            int_points[i] = {x,y};
        }
        
        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                double distance = sqrt(pow(int_points[i].first-int_points[j].first, 2) + pow(int_points[i].second-int_points[j].second,2));
                adj[i][j] = distance;
                adj[j][i] = distance;
            }
        }
        
        double result = floydwarshall(n, adj);
        
        printf("Scenario #%d\n", c);
        printf("Frog Distance = %.3f\n", result);
        printf("\n");
        
        c++;
        scanf("%d", &n);
    }

    return 0;
}