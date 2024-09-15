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

int main()
{
  detachingFromC;
  string str;
  while(1) {
    cin >> str;
    if(str == "#") break;

    string aux = str;
    next_permutation(aux.begin(), aux.end());

    if(aux <= str) {
      cout << "No Successor" << endl;
    } else cout << aux << endl;
  }

  
  return 0;
}