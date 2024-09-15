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
    int j1, j2, m1, m2, card;
    cin >> j1 >> j2;
    cin >> m1 >> m2;

    vi usadas(14, 0);
    usadas[j1]++;
    usadas[j2]++;
    usadas[m1]++;
    usadas[m2]++;

    int john = (j1 > 10 ? 10 : j1) + (j2 > 10 ? 10 : j2);
    int mary = (m1 > 10 ? 10 : m1) + (m2 > 10 ? 10 : m2);

    int soma = 0;
    for (int i = 0; i < n; i++) {
        cin >> card;
        usadas[card]++;
        if (card > 10) card = 10;
        soma += card;
    }

    john += soma;
    mary += soma;

    int result = -1;
    for (int i = 1; i <= 13; i++) {
        if (usadas[i] < 4) {
            int valor = (i > 10 ? 10 : i);
            if ((mary + valor == 23 && john + valor < 23) || (john+valor > 23 && mary+valor <=23) || (mary + valor == 23 && john + valor == 23)  ) {
                result = valor;
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
  
  return 0;
}