#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int &u, int parentColor, vector<int> &visited, vector<vector<int>> &adj, vector<int> &colors, bool &isBipartite) {
    if (!isBipartite) {
        return;
    }
    visited[u] = 1;
    
    colors[u] = (parentColor + 1) % 2;
    
    for (int v : adj[u]) {
        if(colors[v] == colors[u]) {
            isBipartite = false;
            return;
        }
        if (!visited[v]){
            dfs(v, colors[u], visited, adj, colors, isBipartite);
        }
        
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int v,e;
        scanf("%d %d", &v, &e);
        int sum = 0;
        bool isBipartite = true;
        if (e == 0) {
            sum = v;
        } else {
            vector<vector<int>> adj(v);
            vector<int> visited(v, 0);
            
            int a,b;
            for(int j = 0; j < e; j++) {
                scanf("%d %d", &a, &b);
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
    
            for(int u = 0; u < adj.size(); u++) {
                if (!visited[u]) {
                    vector<int> colors(v, -1);
                    dfs(u, 0, visited, adj, colors, isBipartite);
                    int t1 = 0;
                    int t2 = 0;
                    for (int x = 0; x < colors.size(); x++) {
                        if(colors[x] == 1) {
                            t1++;
                        } else if (colors[x] == 0) {
                            t2++;
                        }
                    }
                    sum += max(1, min(t1, t2));
                }
                
            }
            
        }
        
        if (!isBipartite) {
            cout << -1 << endl;
        } else{
            cout << sum << endl;
        }
    }

    return 0;
}
