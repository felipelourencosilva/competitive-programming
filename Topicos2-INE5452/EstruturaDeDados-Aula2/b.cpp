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
  ll num;
  vector<ll> nums;
  while(cin >> num) {
    nums.push_back(num);
    sort(nums.begin(), nums.end());

    int tam = nums.size();

    if(nums.size() % 2 == 1) {
      cout << nums[tam/2] << endl; 
    } else {
      ll aux = (nums[tam/2] + nums[tam/2-1]) / 2;
      cout << aux << endl;
    }
  }

  
  return 0;
}