#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;

#define detachingFromC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main()
{
    detachingFromC;
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vi nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        bool flag = true;
        int minBus = nums[0];
        int maxBus = nums[0];
        for(int i = 1; i < n; i++) {
            maxBus = max(nums[i], maxBus);
            minBus = min(nums[i], minBus);
            if(maxBus - minBus != i ) {
                flag = false; break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}