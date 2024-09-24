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

int m= 0;
vi elements;

void solve(int n, int k, vi nums) {
    int mask = 1 << k;

    for(int i = 0; i < mask; i++) {
        int max_aux = 0;
        vi elements_aux;
        for(int j = 0; j < k; j++) {
            if(i & (1 << j)) {
                max_aux += nums[j];
                elements_aux.push_back(nums[j]);
            }
        }
        if(max_aux > m && max_aux <= n) {
            m = max_aux;
            elements = elements_aux;
        } else if(max_aux == m && elements.size() < elements_aux.size()) {
            elements = elements_aux;
        }
        
    }
}

int main() {
    detachingFromC;
    int n, k;
    while(cin >> n) {
        cin >> k;
        m = 0;
        elements.resize(0);
        vi nums(k);
        for(int i = 0; i < k; i++) {
            cin >> nums[i];
        }

        solve(n, k, nums);
        int soma = 0;
        for(auto r : elements) {
            soma += r;
            cout << r << " ";
        }

        cout << "sum:" << soma << endl;
    }
    return 0;
}