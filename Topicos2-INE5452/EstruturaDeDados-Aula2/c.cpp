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
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        pq.push(num);
    }
    ll soma = 0;
    while (pq.size() > 1) {
        ll aux1 = pq.top(); pq.pop();
        ll aux2 = pq.top(); pq.pop();
        ll sum = aux1 + aux2;
        soma += sum;
        pq.push(sum);
    }

    cout << soma << endl;
  }

  
  return 0;
}