#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydwarshall(int n, vector<vector<int>> &dist, vector<vector<int>> &edges) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                        edges[i][j] = edges[k][j];
                    }
                    if (newDist == dist[i][j] && i != k and j != k) {
                        edges[i][j] = edges[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n, vector<int>(n));
    vector<vector<int>> adjAux(n, vector<int>(n));
    vector<vector<int>> edges(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges[i][j] = i;
        }   
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            adj[i][j] = x;
            adjAux[i][j] = x;
        }
    }
    
    floydwarshall(n, adj, edges);
    
    
    if (adj == adjAux) {
        int soma = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(edges[i][j] != i) soma++;
            }
        }
        
        printf("%d", soma/2);
    } else {
        printf("%d", -1);
    }

    return 0;
}