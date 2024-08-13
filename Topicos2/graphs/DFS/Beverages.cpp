#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

vector<string> top_sort(string &u, map<string, vector<string>> &adj, int size) {
    vector<string> result;
    queue<string> q;
    map<string, int> indegree;
    
    for (const auto& pair : adj) {
        string node = pair.first;
        indegree[node] = 0;
    }
    
    for (const auto& pair : adj) {
        string node = pair.first;
        for (int j = 0; j < adj[node].size(); j++) {
            indegree[adj[node][j]]++;
        }
    }
    
    for (const auto& pair : indegree) {
        string node = pair.first;
        if(indegree[node] == 0) {
            q.push(node);
        }
    }
    
    while(!q.empty()) {
        string v = q.front();
        q.pop();
        result.push_back(v);
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
    
    return result;
}

int main()
{

    int n;
    while(scanf("%d", &n) != EOF) {
        map<string, vector<string>> adj;
        map<string, int> visited;
        vector<string> stack;
        
        string str;
        cin >> str;
        adj[str] = {};
        string first = str;
        n--;

        while (n--) {
            cin >> str;
            adj[str] = {};
            visited[str] = 0;
        }
        
        int m;
        scanf("%d", &m);
        
        string u,v;
        while(m--) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        vector<string> result_vector = top_sort(first, adj, adj.size());
        
        for (int i=0; i < result_vector.size(); i++){
            cout << "Case #" << i+1 << ": Dilbert should drink beverages in this order: ";
            for (int j = stack.size() - 1; j >= 0; j--) {
                if (j == 0) {
                    cout << stack[j];
                } else {
                    cout << stack[j] << " ";
                }
            }
            cout << "." << endl;
            scanf("");
        }
        
        
    }
    
    
    return 0;
}