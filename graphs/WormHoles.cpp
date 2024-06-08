#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

bool bellmanford(vector<vector<int>> values, int &n) {
    vector<int> distTo(n, INF);
    distTo[0] = 0;
    
    for (int i = 0; i < n-1; i++) {
        for (auto value : values) {
            int u = value[0];
            int v = value[1];
            int val = value[2];
            if (distTo[u] != INF && distTo[u] + val < distTo[v]) {
                distTo[v] = distTo[u] + val;
            }
        }
    }
    
    for (auto value : values) {
        int u = value[0];
        int v = value[1];
        int val = value[2];
        if (distTo[u] != INF && distTo[u] + val < distTo[v]) {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int c;
    scanf("%d", &c);
    for(int i = 0; i < c; i++) {
        int n,m;
        scanf("%d %d", &n,&m);
    
        vector<vector<int>> values(m);
        int u,v,value;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u,&v,&value);
            values[i].push_back(u);
            values[i].push_back(v);
            values[i].push_back(value);
        }
        
        if(bellmanford(values, n)) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }
    return 0;
}