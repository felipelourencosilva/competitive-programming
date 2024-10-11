#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, r;
    while(1) {
        cin >> n >> d >> r;
        if(!n && !d && !r) break;

        vector<int> morning(n), evening(n);
        for(int i = 0; i < n; i++) {
            cin >> morning[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> evening[i];
        }

        sort(morning.begin(), morning.end());
        sort(evening.rbegin(), evening.rend());

        long long soma = 0;

        for(int i = 0; i < n; i++) {
            soma += max(0, morning[i]+evening[i] - d);
        }

        cout << soma*r << endl;
    }
    return 0;
}