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
  int n, k;
  int counter = 0;
  while(1) {
    
    cin >> n >> k;

    if(!n) break;
    if(counter++) cout << endl;
    vi vitorias(n+1, 0);
    vi part(n+1, 0);
    int u, v;
    string j1, j2;
    int vezes = k*n*(n-1)/2;
    for(int i = 0; i < vezes; i++) {

      cin >> u >> j1 >> v >> j2;
      if ((j1 == "rock" && j2 == "scissors") || 
          (j1 == "scissors" && j2 == "paper") || 
          (j1 == "paper" && j2 == "rock")) {
        vitorias[u]++;
        part[u]++;
        part[v]++;
      } else if ((j2 == "rock" && j1 == "scissors") || 
                 (j2 == "scissors" && j1 == "paper") || 
                 (j2 == "paper" && j1 == "rock")) {
        vitorias[v]++;
        part[u]++;
        part[v]++;
      }
      
      
    }

    for(int i = 1; i <= n; i++) {
      if(!part[i]) cout << "-" << endl;
      else {
        double result = (double)vitorias[i]/part[i];
        cout << fixed << setprecision(3) << result << endl;
      }
    }

  }
  return 0;
}