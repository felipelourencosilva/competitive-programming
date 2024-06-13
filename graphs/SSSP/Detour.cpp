#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edges{
    int i, k, j;
    
    Edges(int _i, int _k, int _j) : i(_i), k(_k), j(_j) {}
};

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
                }
            }
        }
    }
}

int dijkstra(int src, int dest, vector<vector<pair<int,int>>> &adj, vector<vector<int>> &edges, vector<vector<int>> &distMatrix) {
    vector<int> distTo(adj.size(), INF);
    distTo[src] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    
    while(!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        
        if (dist > distTo[u]) continue;
        
        
        for (auto [length, v] : adj[u]) {
            if (u == src && v == dest) continue;
            int edge = edges[v][dest];
            if(edge != src) {
                if (distMatrix[v][dest] == INF)
                    return INF;
                int newDist = dist + length + distMatrix[v][dest];
                if (newDist < distTo[dest]) {
                    pq.push({newDist, dest});
                    distTo[dest] = newDist;
                }
            }    
            
            else {
                int newDist = dist + length;
                if (newDist < distTo[v]) {
                    distTo[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }
    
    return distTo[dest];
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    
    vector<pair<int,int>> inputs(m);
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> edges(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (int j = 0; j < n; j++) {
            edges[i][j] = i;
        }   
    }
    
    int u,v,l;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &l);
        u--;
        v--;
        
        adj[u].push_back({l, v});
        adj[v].push_back({l, u});
        
        dist[u][v] = l;
        dist[v][u] = l;
        
        inputs[i] = {u,v};
    }
    
    floydwarshall(n, dist, edges);
    
    for (auto [inputU, inputV] : inputs) {
        int edge = edges[inputU][inputV];
        
        int result;
        if(edge == inputU){
            result = dijkstra(inputU, inputV, adj, edges, dist);
        }
        else result = dist[inputU][inputV];
        
        if(result == INF) printf("%d\n", -1);
        else printf("%d\n", result);
        
    }

    return 0;
}