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
  int k, n, m; 
  double num;
  cin >> k;
  for(int l = 1; l <= k; l++) {
    cin >> n;
    map<double, set<int>> nums;
    for(int i = 0; i < n; i++) {
      cin >> m;
      for(int j = 0; j < m; j++) {
        cin >> num;
        nums[num].insert(i);
      }
    }

    vector<double> quant(n, 0);
    double total = 0;
    for(auto& pair : nums) {
      if(pair.second.size() == 1) {
        quant[*pair.second.begin()] += 1;
        total++;
      }
    }
    if(!total) total = 1;

    cout << "Case " << l << ":";
    for(int i = 0; i < n; i++) {
      double aux = quant[i]/total;
      cout << " " << fixed << setprecision(6) << aux*100 << "%";
    }
    cout << endl;
  }
  return 0;
}