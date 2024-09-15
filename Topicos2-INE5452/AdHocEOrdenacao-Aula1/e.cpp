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
  int n;
  cin >> n;
  cin.ignore();cin.ignore();
  while (n--)
  {
    string line;
    vector<string> words;
    while (1)
    {
      getline(cin, line);
      if(line.empty()) break;

      words.push_back(line);
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++)
    {
      for (int j = i + 1; j < words.size(); j++)
      {
        string str1 = words[i];
        str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
        sort(str1.begin(), str1.end());

        string str2 = words[j];
        str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());
        sort(str2.begin(), str2.end());
        if (str1 == str2)
          cout << words[i] << " = " << words[j] << endl;
      }
    }

    if (n)
      cout << endl;
  }
  return 0;
}