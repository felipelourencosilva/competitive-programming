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



struct Team{
  bool submission = false;
  int contestant;
  int problemsSolved = 0;
  ll totalTime = 0;
  vi questionsTime;

  Team(){}
  Team(int contestant) : contestant(contestant), questionsTime(10, 0) {}

  bool operator<(const Team& other) const {
    if (problemsSolved == other.problemsSolved) {
      if (totalTime == other.totalTime) {
        return contestant < other.contestant;
      }
      return totalTime < other.totalTime;
    }
    return problemsSolved > other.problemsSolved;
  }
};

int main()
{
  detachingFromC;
  int contestant, problem, time, n;
  char status;
  string line;
  cin >> n;
  cin.ignore();
  cin.ignore();

  while (n--) {
    vector<Team> teams(101);
    for (int i = 0; i <= 100; i++) {
      teams[i] = Team(i);
    }

    while (getline(cin, line) && line.length() != 0) {
      sscanf(line.c_str(), "%d %d %d %c", &contestant, &problem, &time, &status);

      if (status == 'C') {
        if (teams[contestant].questionsTime[problem] != -1) {
          teams[contestant].questionsTime[problem] += time;
          teams[contestant].totalTime += teams[contestant].questionsTime[problem];
          teams[contestant].questionsTime[problem] = -1;
          teams[contestant].problemsSolved++;
        }
      } else if (status == 'I') {
        if (teams[contestant].questionsTime[problem] != -1) {
          teams[contestant].questionsTime[problem] += 20;
        }
      }

      teams[contestant].submission = true;
    }

    sort(teams.begin(), teams.end());

    for (int i = 0; i <= 100; i++) {
      if (teams[i].submission) {
        cout << teams[i].contestant << " " << teams[i].problemsSolved << " " << teams[i].totalTime << endl;
      }
    }

    if(n) cout << endl;
  }

  return 0;
}