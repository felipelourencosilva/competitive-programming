#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    
    UnionFind(int n) {
        parent.reserve(n);
        size.assign(n, 1);
        
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }
    
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionSets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a; // subordinate b to a (smaller to bigger)
            size[a] += size[b];
        }
    }
};

struct Edge {
    double u, v, weight;
    
    Edge(double _u, double _v, double _weight) : u(_u), v(_v), weight(_weight) {}
    
    bool operator<(Edge &other) const {
        return weight < other.weight;
    }
};

struct Point {
    double x,y;
    
    Point(double _x, double _y) : x(_x), y(_y) {}
    
    double dist(Point &p2) {
        return sqrt(pow(x-p2.x,2) + pow(y-p2.y,2));
    }
};

int main()
{  
    int counter;
    scanf("%d", &counter);
    
    for (int x = 0; x < counter; x++) {
        vector<Edge> edges;
        vector<Point> freckles;
        
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            freckles.push_back(Point(x, y));
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double freckleDist = freckles[i].dist(freckles[j]);
                edges.push_back(Edge(i, j, freckleDist));
            }
        }
        
        sort(edges.begin(), edges.end());
        
        UnionFind uf = UnionFind(n);
        vector<Edge> mst;
        mst.reserve(n-1);
        double mstWeight = 0;
        
        for (Edge e : edges) {
            if (uf.find(e.u) != uf.find(e.v)) {
                mst.push_back(e);
                mstWeight += e.weight;
                uf.unionSets(e.u, e.v);
            }
            
            if (mst.size() == n-1)
                break;
        }
        
        cout << setprecision(2) << fixed << mstWeight << endl;
        if (x != counter-1) cout << endl;
    }

    return 0;
}
