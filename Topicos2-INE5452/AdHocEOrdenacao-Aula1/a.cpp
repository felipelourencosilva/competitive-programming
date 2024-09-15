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
  int l,c, n;
  cin >> l >> c;

  vector<string> matrix(l);
  vector<vi> visited(l, vi(c, 0));
  for(int i = 0; i < l; i++) {
    cin >> matrix[i];
  }

  cin >> n;
  vector<string> words(n);
  for(int i = 0; i < n; i++) {
    cin >> words[i];

    sort(words[i].begin(), words[i].end());
  }

  for(auto word : words) {
    vector<vi> aux(l, vi(c, 0));
    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++) {

        //verificação na linha
        string w = "";
        for(int k = j; k < c; k++) {
          w+= matrix[i][k];
          sort(w.begin(), w.end());
          if(w == word) {
            for(int q = j; q <=k; q++) {
              aux[i][q]++;
            }
          }
        }

        //verificação na coluna
        w = "";
        for(int k = i; k < l; k++) {
          w+= matrix[k][j];
          sort(w.begin(), w.end());
          if(w == word) {
            for(int q = i; q <=k; q++) {
              aux[q][j]++;
            }
          }
        }

        //verificação na diagonal pra direita
        w = "";
        int indx = i, indy = j;
        while(indx < l && indy < c) {
          w+= matrix[indx][indy];
          sort(w.begin(), w.end());
          if(w == word) {
            int auxx = i, auxy = j;
            while(auxx <= indx && auxy <= indy) {
              aux[auxx][auxy]++;
              auxx++;
              auxy++;
            }
          }
          indx++; indy++;
        }

        //verificação na diagonal pra esquerda
        w = "";
        indx = i, indy = j;
        while(indx < l && indy < c) {
          w+= matrix[indx][indy];
          sort(w.begin(), w.end());
          if(w == word) {
            int auxx = i, auxy = j;
            while(auxx <= indx && auxy >= indy) {
              aux[auxx][auxy]++;
              auxx++;
              auxy--;
            }
          }
          indx++; indy--;
        }

      }
    }

    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++) {
        if(aux[i][j] >0) visited[i][j]++;
      }
    }
  }

  int soma = 0;

  for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
      if(visited[i][j] >1) soma++;
    }
  }

  cout << soma << endl;

  return 0;
}