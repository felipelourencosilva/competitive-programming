#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const int LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n, m;
vi milks;

bool fillContainers(int tam) {
    vi containers(m, tam);

    int indCont = 0;
    for (int i = 0; i < n; i++) {
        if (milks[i] > tam) return false;
        while (indCont < m && containers[indCont] < milks[i]) indCont++;
        if (indCont == m) return false;
        containers[indCont] -= milks[i];
    }

    return true;
}

int binarySearch(int low, int high) {
    if(low >= high) return low;

    int mid = (low+high)/2;

    if(fillContainers(mid)) return binarySearch(low, mid);
    else return binarySearch(mid+1, high);
}

int main() {
    detachingFromC;
    
    while(cin >> n >> m) {
        milks.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> milks[i];
        }

        cout << binarySearch(0, INF) << endl;
    }
    
    return 0;
}