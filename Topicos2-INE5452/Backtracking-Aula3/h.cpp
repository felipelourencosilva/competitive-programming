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

vector<string> res;

void solve(map<string, char> &strings, string frase, string word, int ind) {
    if(ind >= frase.size()) {
        res.push_back(word);
        return;
    }

    while(ind < frase.size() && frase[ind] == '0') ind++;

    if(ind >= frase.size()) return;
    
    for(int i = ind; i < frase.size(); i++) {
        string aux = "";
        for(int j = ind; j <= i; j++) {
            aux += frase[j];
        }

        if(strings.find(aux) != strings.end()) {
            solve(strings, frase, word+strings[aux], i+1);
        } else if(aux == "0"){
            solve(strings, frase, word, i+1);
        }
    }

    return;
}

int main() {
    detachingFromC;
    int n;
    char c;
    string str, frase;
    int counter = 1;
    while(1) {
        cin >> n;
        if(!n) break;
        map<string, char> strings;
        for(int i = 0; i < n; i++) {
            cin >> c >> str;
            strings[str] = c;
        }
        cin >> frase;
        res.resize(0);
        solve(strings, frase, "", 0);
        sort(res.begin(), res.end());
        cout << "Case #" << counter++ << endl;
        for(int i = 0; i < min((int)res.size(), 100); i++) {
            cout << res[i] << endl;
        }

        cout << endl;
    }
    return 0;
}