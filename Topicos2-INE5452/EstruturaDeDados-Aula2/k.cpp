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
  int n,m,num;
  int counter = 1;
  while(1) {
    cin >> n;
    if(!n) break;
    set<int> c;
    for(int i = 0; i < n; i++) {
      cin >> num;
      c.insert(num);
    }

    cout << "Case " << counter++ << ":" << endl;
    cin >> m;
    for(int i = 0; i < m; i++) {
      cin >> num;
      int dif = INF;
      ll soma = INF;

      for(int s : c) {
        for(int l : c) {
          if(s != l) {
            if(abs((s+l)-num) < dif) {
              dif = abs((s+l)-num);
              soma = abs(s+l);
            }
          }
        }
      }

      cout << "Closest sum to " << num << " is " << soma << "." << endl;
    }
  }

  
  return 0;
}