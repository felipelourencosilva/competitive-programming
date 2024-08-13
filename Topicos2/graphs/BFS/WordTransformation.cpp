#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

bool diferenca(string &p1, string &p2) {
    if (p1 == p2 || p1.size() != p2.size()) {
        return false;
    }
    
    int dif = 0;
    
    for (int i = 0; i < p1.size(); i++) {
        if (p1[i] != p2[i]) {
            dif++;
        }
    }
    
    return dif == 1;
}

int bfs(int &s, int &res, vector<vector<int>> &adj) {
    vector<int> d(adj.size(), INF);
    d[s] = 0;
    queue<int> q; 
    q.push(s);
    
    while(!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j]; 
            if (d[v] == INF) { 
                d[v] = d[u] + 1;
                if (v == res) {
                    return d[res];
                }
                q.push(v); 
        }}
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        vector<string> words;
        map<int, string> int_word;
        map<string, int> word_int;
        
        int tamanho = 0;
        string word;
        cin >> word;
        while(word != "*") {
            words.push_back(word);
            int_word[tamanho] = word;
            word_int[word] = tamanho;
            tamanho ++;
            cin >> word;
        }
        
        vector<vector<int>> adj(tamanho);
        for (int i = 0; i < words.size(); i++) {
            for (int j = i; j < words.size(); j++) {
                if (diferenca(words[i], words[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        cin.ignore();
        
        string line;
        while (getline(cin, line) && line != "") {
            
            stringstream ss(line);
            string u, v;
            ss >> u >> v;
            int result = bfs(word_int[u], word_int[v], adj);
            cout << u << " " << v << " " << result << endl;
        }
        
        if (n){
            cout << endl;
        }
    }

    return 0;
}

