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
    string str;
    int t, n, d; cin >> t;
    for(int c = 1; c <= t; c++) {
        cin >> n >> d;
        vi pedras(n+2);
        vector<char> tam(n+2);
        vector<char> usado(n+2, false);
        for(int i = 0; i < n; i++) {
            cin >> str;
            tam[i] = str[0];
            pedras[i] = stoi(str.substr(2,str.size()-2));
        }
        pedras[n] = d;
        tam[n] = 'B';

        /*for(auto p : pedras) {
            cout << p << " ";
        }
        cout << endl;
        for(auto p : tam) {
            cout << p << " ";
        }
        cout << endl;*/

        int maior = pedras[0];
        for(int i = 0; i < n; i++) {
            usado[i] = true;
            if(tam[i+1] == 'B') maior = max(maior, pedras[i+1] - pedras[i]);
            else {
                maior = max(maior, pedras[i+2] - pedras[i]); i++;
            }
        }

        for(int i = n; i > 0; i--) {
            if(!usado[i-1] || tam[i-1] == 'B') maior = max(maior, pedras[i] - pedras[i-1]);
            else {
                maior = max(maior, pedras[i] - pedras[i-2]); i--;
            }
        }

        cout << "Case " << c << ": " << maior << endl;
    }
    return 0;
}