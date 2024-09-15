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
  int n,m, num;
  while(1) {
    cin >> n;
    if(!n) break;
    ll soma = 0;
    multiset<int> ms;
    for(int i = 0; i < n; i++) {
      cin >> m;
      
      for(int j = 0; j < m; j++) {
        cin >> num;
        ms.insert(num);
      }
      
      auto menor = ms.begin();
      auto maior = prev(ms.end());

      soma += *maior - *menor;
      ms.erase(menor);
      ms.erase(maior);
    }

    cout << soma << endl;
  }

  
  return 0;
}