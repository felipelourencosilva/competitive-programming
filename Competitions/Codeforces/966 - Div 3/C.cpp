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
    int t, n, num;
    string str;
    cin >> t;
    while(t--) {
        cin >> n;
        vi nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cin >> num;
        for(int i = 0; i < num; i++) {
            bool flag = false;
            map<char, int> charInt;
            map<int, char> intChar;
            cin >> str;
            if(str.size() == n) {
                flag = true;
                for(int j = 0; j < str.size(); j++) {
                    if(charInt.find(str[j]) != charInt.end() && charInt[str[j]] != nums[j]) {
                        flag = false;
                        break;
                    } 
                    if(intChar.find(nums[j]) != intChar.end() && intChar[nums[j]] != str[j]) {
                        flag = false;
                        break;
                    } 
                    charInt[str[j]] = nums[j];
                    intChar[nums[j]] = str[j];
                }
            }
            
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}