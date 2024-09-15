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
  int n, num;
  while(1) {
    cin >> n;
    if(!n) break;
    while(1) {
      cin >> num;
      if(!num) break;
      vector<int> vagoes(n);
      vagoes[0] = num;

      for(int i = 1; i < n; i++) {
          cin >> vagoes[i];
      }
      stack<int> st;
      int ind_st = 1;
      int ind_vagoes = 0;
      while(ind_vagoes < n && ind_st <= n) {
        st.push(ind_st++);
        while(!st.empty() && st.top() == vagoes[ind_vagoes]) {
          st.pop(); ind_vagoes++;
        }
      }

      if(!st.size()) cout << "Yes" << endl;
      else cout << "No" << endl;

    }

    cout << endl;
    
  }

  
  return 0;
}