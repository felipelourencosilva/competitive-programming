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

vector<pair<string,string>> solve(int n) {
    vector<pair<string,string>> res;

    for(int i = 12345; i <= 99999; i++) {

        bool flag = false;
        string str1 = to_string(i);
        vector<int> aux(10, 0);

        for(auto s : str1) {
            if(aux[s-'0'] != 0) {
                flag = true;
                break;
            } else aux[s-'0'] = 1;
        }

        if(!flag) {
            int y = i/n;

            flag = false;
            string str2 = to_string(y);
            
            for(int i = 0; i < (5-str2.size()); i++) str2 = "0"+str2;

            for(auto s : str2) {
                if(aux[s-'0'] != 0) {
                    flag = true;
                    break;
                } else aux[s-'0'] = 1;
            }
            if(i % n != 0) flag = true;
            if(y < 1234) flag = true;
            if(!flag) res.push_back({str1, str2});
        }
        
    }

    return res;
}

int main() {
    detachingFromC;
    int n;
    int first = false;
    while(1) {
        cin >> n;
        if(!n) break;
        if(first) {
            cout << endl;
        }
        first = true;
        
        vector<pair<string,string>> res = solve(n);

        if(res.size() == 0) cout << "There are no solutions for " << n << "." << endl;
        else {
            for(auto r : res) {
                cout << r.first << " / " << r.second << " = " << n << endl;;
            }
        }
    }
    return 0;
}