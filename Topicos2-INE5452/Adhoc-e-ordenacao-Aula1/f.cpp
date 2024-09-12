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
  double n, c, d;
  cin >> n;
  int counter = 1;
  while (n--)
  {
    cin >> c >> d;

    double fahrenheit = (1.8) * c + 32 + d;

    double celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
    cout << "Case " << counter++ << ": " << fixed << setprecision(2) << celsius << endl;
  }
  return 0;
}