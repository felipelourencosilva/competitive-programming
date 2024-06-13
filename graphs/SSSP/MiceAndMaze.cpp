#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int floydwarshall(int n, int e, int t, vector<vector<int>> &matrix) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
           
    int sum = 0;     
    for (int i = 0; i < n; i++) {
        if (matrix[i][e] <= t) {
            sum++;
        }
    }
    
    return sum;
}

int main()
{
    int c;
    scanf("%d", &c);
    while(c--) {
        int n,e,t;
        scanf("%d", &n);
        scanf("%d", &e);
        scanf("%d", &t);
        e--;
        
        int m;
        scanf("%d", &m);
        
        vector<vector<int>> matrix(n, vector<int>(n, INF));
        
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
                
        int x,y,d;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &d);
            x--;
            y--;
            matrix[x][y] = d;
        }
        
        int result = floydwarshall(n, e, t, matrix);
        
        printf("%d\n", result);
        if(c != 0) printf("\n");
        
    }

    return 0;
}