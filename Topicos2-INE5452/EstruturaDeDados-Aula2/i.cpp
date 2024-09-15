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
    map<vector<int>, int> pop;
    for(int i = 0; i < n; i++) {
      vi nums(5);
      for(int j = 0; j < 5; j++) {
        cin >> nums[j];
      }

      sort(nums.begin(), nums.end());
      pop[nums]++;
    }
    int maior = 0;
    int vezes = 0;
    for(auto pair : pop) {
      if(pair.second == maior) vezes+= pair.second;
      if(pair.second > maior) {
        maior = pair.second;
        vezes = pair.second;
      }
    }

    cout << vezes << endl;
  }

  
  return 0;
}