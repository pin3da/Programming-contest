// http://codeforces.com/contest/493/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  string name[2];
  cin >> name[0] >> name[1];
  int n;
  cin >> n;
  int t, m;
  char h, color;
  vector<vector<int> > fouls(2, vector<int>(100, 0));
  for (int i = 0; i < n; ++i) {
    cin >> t >> h >> m >> color;
    int team = (h == 'h' ? 0 : 1);
    int f = (color == 'r' ? 2 : 1);
    if (fouls[team][m] >= 2)
      continue;

    fouls[team][m] += f;
    if (fouls[team][m] >= 2)
      cout << name[team] << " " << m << " " << t << endl;
  }

  return 0;
}