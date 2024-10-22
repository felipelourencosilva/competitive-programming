#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;
#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n;
vector<int> decreasing, increasing, heightI, lengthI, heightD, lengthD;

pair<int,int> LIS() {
    int inc = 0;
    int dec = 0;

    for(int i = 0; i < n; i++) {
        increasing[i] = lengthI[i];
        decreasing[i] = lengthD[i];
        for(int j = 0; j < i ; j++) {
            if(heightI[j] < heightI[i]) increasing[i] = max(increasing[i], lengthI[i]+increasing[j]);
            if(heightD[j] < heightD[i]) decreasing[i] = max(decreasing[i], lengthD[i]+decreasing[j]);
        }
        dec = max(decreasing[i], dec);
        inc = max(increasing[i], inc);
    }

    return {inc, dec};
}

int main() {
    detachingFromC;
    int t; cin >> t;
    for(int k = 1; k <= t; k++) {
        cin >> n;
        decreasing.resize(n);
        increasing.resize(n);
        heightI.resize(n);
        lengthI.resize(n);
        heightD.resize(n);
        lengthD.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> heightI[i];
            heightD[n-i-1] = heightI[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> lengthI[i];
            lengthD[n-i-1] = lengthI[i];
        }

        pair<int,int> res = LIS();
        
        cout << "Case " << k << ". ";
        if(res.first >= res.second) 
            cout << "Increasing ("<< res.first << "). Decreasing (" << res.second<<")." << endl;
        else cout << "Decreasing ("<< res.second << "). Increasing (" << res.first<<")." << endl;
    }

    return 0;
}