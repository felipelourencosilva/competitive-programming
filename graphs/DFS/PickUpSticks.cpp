#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isNotCyclic;

void dfs(int u, vector<int>& visited, stack<int> &st, vector<vector<int>> &adj){
    if(!isNotCyclic){
        return;
    };
    
    visited[u] = 1;
    
    for (auto v : adj[u]){
        if (!visited[v]) {
            dfs(v, visited, st, adj); 
        } else if(visited[v] == 1) {
            isNotCyclic = false;
            return;
        }
    }
    
    st.push(u);
    visited[u] = 2;
}

int main()
{
    while(true) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1, 0);
        stack<int> st;
        isNotCyclic = true;
        
        int c, d;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &c, &d);
            
            adj[c].push_back(d);
        }
        
        for (int i = 1; i <= n && isNotCyclic; i++) {
            if (!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }
        
        if (!isNotCyclic) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            vector<int> result;
            while(!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
            
            for (int i = 0; i < adj.size() - 1; i++) {
                cout << result[i] << endl;
            }
        }
    }
    return 0;
}