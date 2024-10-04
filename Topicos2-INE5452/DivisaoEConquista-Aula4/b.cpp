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

int main() {
    detachingFromC;
    int n, value; 
    while(cin >> n) {
        vi books(n);
        map<int,int> nums;
        for(int i = 0; i < n; i++) {
            cin >> books[i];
            nums[books[i]]++;
        }
        sort(books.begin(), books.end());

        cin >> value;
        int n1;
        int n2;
        int dif = INF;
        for(int i = 0; i < n; i++) {
            int val = abs(books[i] - value);
            if(binary_search(books.begin(), books.end(), val)) {
                if(books[i] == val && nums[books[i]] <= 1) continue;
                if(abs(books[i] - val) < dif) {
                    n1 = books[i];
                    n2 = val;
                    dif = abs(books[i] - val);
                }
            }
        }

        cout << "Peter should buy books whose prices are " << n1 << " and " << n2 << "." << endl;
        cout << endl;
    }
    return 0;
}