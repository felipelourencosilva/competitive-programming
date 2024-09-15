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
  int num;
  while(1) {
    cin >> num;
    if(!num) break;
    queue<int> q;

    for(int i = 1; i <= num; i++) {
      q.push(i);
    }

    cout << "Discarded cards:";
    while(q.size() > 1) {
      if(q.size() > 2) cout << " " << q.front() << ",";
      else cout << " " << q.front();
      q.pop();

      int aux = q.front();q.pop();
      q.push(aux);
    }

    cout << endl;

    cout << "Remaining card: " << q.front() << endl;
  }
  

  return 0;
}