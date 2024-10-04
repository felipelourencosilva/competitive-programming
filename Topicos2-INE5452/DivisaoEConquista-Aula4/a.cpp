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

int main() {
    detachingFromC;
    string str, str2;
    int n;
    cin >> str;
    map<char, vector<int>> letras;
    for(int i = 0; i < str.size(); i++) {
        letras[str[i]].push_back(i);
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str2;

        int first = -1;
        int last = -1;
        bool flag = true;
        for (int j = 0; j < str2.size(); j++) {
            char letra = str2[j];
            
            if (letras.find(letra) == letras.end()) {
                flag = false;
                break;
            }

            auto ind = lower_bound(letras[letra].begin(), letras[letra].end(), last+1);
            
            if (ind == letras[letra].end()) {
                flag = false;
                break;
            }
            if (first == -1) first = *ind;
            last = *ind;
        }

        if(flag) cout << "Matched " << first << " " << last << endl;
        else cout << "Not matched" << endl;
    }
    return 0;
}