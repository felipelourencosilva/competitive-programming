#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int s, vector<vector<pair<int,int>>> &adj) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> distTo(adj.size(), INF);
    pq.push(make_pair(0, s));
    distTo[s] = 0;
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (dist > distTo[u]) continue;
        
        for (int i = 0; i < adj[u].size(); i++) {
            int weight = adj[u][i].first;
            int v = adj[u][i].second;
            
            if (distTo[u] + weight < distTo[v]) {
                distTo[v] = distTo[u] + weight;
                pq.push(make_pair(distTo[v], v));
            }
        }
    }
    
    return distTo;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int,int>>> adj(n);
    
    int u, v, p;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &p);
        u--;
        v--;
        adj[u].push_back(make_pair(p, v));
        adj[v].push_back(make_pair(p, u));
    }
    
    int s;
    scanf("%d", &s);
    s--;
    vector<int> dist = dijkstra(s, adj);
    
    int minimo = INF, maximo = -INF;
    for (int i = 0; i < n; i++) {
        if (i != s) {
            minimo = min(minimo, dist[i]);
            maximo = max(maximo, dist[i]);
        }
    }
    
    int result = maximo - minimo;

    cout << result << endl;
    
    return 0;
}