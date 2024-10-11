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

int moreUseful(int ind, string str) {
    int soma = 0;
    if(ind < m && ind >= 0 && str[ind] == '.') soma++;
    if(ind+1 < m && ind+1 >= 0 && str[ind+1] == '.') soma++;
    if(ind-1 < m && ind-1 >= 0 && str[ind-1] == '.') soma++;
    return soma;
}

int main() {
    detachingFromC;
    string crops;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        cin >> crops;
        int res = 0;
        for(int i = 0; i < m; i++) {
            if(crops[i] == '#') continue;
            int primeiro = moreUseful(i, crops);
            int segundo = moreUseful(i+1, crops);
            int terceiro = moreUseful(i+2, crops);

            if(primeiro>= segundo && primeiro >= terceiro) {
                res++;
                crops[i] = '#';
                if(i-1 >= 0) crops[i-1] = '#';
                if(i+1 < m) crops[i+1] = '#';
                continue;
            }

            if(segundo >= primeiro && segundo >= terceiro) {
                res++;
                if(i+1 < m) crops[i+1] = '#';
                if(i >= 0) crops[i] = '#';
                if(i+2 < m) crops[i+2] = '#';
                continue;
            }

            if(terceiro >= primeiro && terceiro >= segundo) {
                res++;
                if(i+2 < m) crops[i+2] = '#';
                if(i+1 >= 0) crops[i+1] = '#';
                if(i+3 < m) crops[i+3] = '#';
                continue;
            }
        }
        cout << "Case " << i << ": " << res << endl;
    }
    return 0;
}