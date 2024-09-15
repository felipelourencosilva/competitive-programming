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
  int n; cin >> n;

  for(int i = 1;i <= n; i++) {
    vector<string> cartas(52);
    vector<int> usada(52, 0);
    for(int j = 0; j < 52; j++) {
      cin >> cartas[j];
    }

    int y = 0;
    int ind = 26;
    for(int j = 0; j < 3; j++) {
      char c = cartas[ind][0];
      int num = c - '0';

      if(num >= 10 || num <= 1) num = 10;

      y += num;
      for(int k = ind; k >= ind-(10-num); k--){
        usada[k] = 1;
      }

      ind -= (11-num);
    }

    ind = 0;
    for(int j = 0; j < 52; j++) {
      if(!usada[j]) ind++;
      if(ind == y) {
        cout << "Case " << i << ": " << cartas[j] << endl;
        break;
      }
    }
  }

  return 0;
}