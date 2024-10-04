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

int main()
{
    detachingFromC;
    int t;
    cin >> t;
    while(t--) {
        string num;
        cin >> num;
        if(num[0] != '1') cout << "NO" << endl;
        else if(num.size() <= 2) cout << "NO" << endl;
        else if(num.size() > 2 && num[1] != '0') cout << "NO" << endl;
        else if(num.size() == 3 && (num[2]  == '1' || num[2]  == '0')) cout << "NO" << endl;
        else if(num.size() >= 4 && num[2] == '0') cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}