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

ll convertAmericus(ll cwh) {
    ll soma = 0;
    if(cwh <= 100) {
        soma += cwh*2;
    } else if(cwh <= 10000) {
        soma += 100*2;
        cwh -= 100;
        soma += cwh*3;
    } else if(cwh <= 1000000) {
        soma += 100*2;
        soma += 9900*3;
        cwh -= 10000;
        soma += cwh*5;
    } else if(cwh >1000000) {
        soma += 100*2;
        soma += 9900*3;
        soma += 990000*5;
        cwh -= 1000000;
        soma += cwh*7;
    }

    return soma;
}

ll binarySearch(int low, int high, int t, int b) {
    if (low > high) return low;
    
    int mid = (low + high) / 2;
    
    if (convertAmericus(t-mid) - convertAmericus(mid) > b) return binarySearch(mid + 1, high, t, b);
    else return binarySearch(low, mid - 1, t, b);
}

ll binarySearchPrice(int low, int high, int value) {
    if(low > high) return low;
    
    int mid = (low + high)/2;
    ll aux = convertAmericus(mid);

    if (aux == value) return mid;
    if (aux > value) return binarySearchPrice(low, mid - 1, value);
    return binarySearchPrice(mid + 1, high, value);
}

int main() {
    detachingFromC;
    int a,b;
    while(1) {
        cin >> a >> b;
        if(!a && !b) break;
        //achar cwh total
        ll p = binarySearchPrice(0, INF, a);

        cout << convertAmericus(binarySearch(0, INF, p, b)) << endl;
    }
    return 0;
}