#include <bits/stdc++.h>
using namespace std;

const int INF = 2 * 1e9;

int bfs(int l, int u, int r, vector<int> &buttons) {
    vector<int> d(10001, INF);
    queue<int> q;
    d[l] = 0;
    q.push(l);
    while(!q.empty()) {
        if(d[u] != INF){
            break;
        }
        l = q.front();
        q.pop();
        for(int i = 0; i < r; i++) {
            int v = (l+buttons[i])%10000;
            if(d[v] == INF) {
                d[v] = d[l]+1;
                q.push(v);
            }
        }
    }
    
    return d[u];
}

int main()
{
    int l,u,r;
    int counter = 1;
    while(scanf("%d %d %d", &l, &u, &r)) {
        if (l == 0 && u == 0 && r == 0) {
            break;
        }
        
        vector<int> buttons;
        int button;
        for (int i = 0; i < r; i++) {
            scanf("%d", &button);
            buttons.push_back(button);
        }
        
        printf("Case %d: ", counter);
        counter ++;
        int result = bfs(l, u, r,buttons);
        if (result != INF) {
            printf("%d\n", result);
        } else {
            printf("Permanently Locked\n");
        }
    }

    return 0;
}
