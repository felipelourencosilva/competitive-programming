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
  int n,escalator,comando;
  cin >> n;

  vector<ll> direita;
  vector<ll> esquerda;
  for(int i = 0; i < n; i++) {
    cin >> escalator >> comando;

    if(comando) esquerda.push_back(escalator);
    else direita.push_back(escalator);
  }

  ll time = 0;

  int indd = 0;
  int inde = 0;
  while(indd < direita.size() && inde < esquerda.size()) {
    if(direita[indd] <= esquerda[inde]) {
      time = max(direita[indd]+10, time + 10);
      indd++;
      while(indd < direita.size() && direita[indd] <= time) {
        time = max(time, direita[indd] + 10);
        indd++;
      }
    } else {
      time = max(esquerda[inde]+10, time + 10);
      inde++;
      while(inde < esquerda.size() && esquerda[inde] < time) {
        time = max(time, esquerda[inde] + 10);
        inde++;
      }
    }
  }

  while(indd < direita.size()) {
    time = max(direita[indd]+10, time + 10);
    indd++;
    while(indd < direita.size() && direita[indd] < time) {
      time = max(time, direita[indd] + 10);
      indd++;
    }
  }

  while(inde < esquerda.size()) {
    time = max(esquerda[inde]+10, time + 10);
    inde++;
    while(inde < esquerda.size() && esquerda[inde] < time) {
      time = max(time, esquerda[inde] + 10);
      inde++;
    }
  }

  cout << time << endl;

  return 0;
}