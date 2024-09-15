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
const int MAX_TIME = 1e6;

int main()
{
  detachingFromC;
  int n,m, u, v, rep;
  
  while (true) {
    cin >> n >> m;
    if (!n && !m) break;

    vector<int> time(MAX_TIME + 1, 0);
    bool conflict = false;

    for (int i = 0; i < n; i++) {
      cin >> u >> v;

      if (!conflict) {
        for (int j = u; j < v; j++) {
          if (time[j]) {
            conflict = true;
            break;
          }
          time[j] = 1;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      cin >> u >> v >> rep;

      if (!conflict) {
        while (u < MAX_TIME) {
          for (int j = u; j < min(v, MAX_TIME); j++) {
            if (time[j]) {
              conflict = true;
              break;
            }
            time[j] = 1;
          }
          if (conflict) break;

          u += rep;
          v += rep;
        }
      }
    }

    if (conflict) cout << "CONFLICT" << endl;
    else cout << "NO CONFLICT" << endl;
  }

  return 0;
}