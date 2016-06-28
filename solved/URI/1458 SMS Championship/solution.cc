#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string g[4][3];
pair<int, int> find_p(char a) {
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 3; ++j)
      if (g[i][j].find(a) != string::npos)
        return make_pair(i, j);
  assert(false);
}

double dis(pair<int, int> &a, pair<int, int> &b) {
  double x = a.first - b.first, y = a.second - b.second;
  return sqrt(x * x + y * y);
}

double dp[500][15][15];
int rd[500][15][15];
int cur_round = 1;
double dt[15][15];

double go(string &s, int id, int a, int b) {
  if (s.size() <= id) return 0;

  if (rd[id][a][b] >= cur_round)
    return dp[id][a][b];

  rd[id][a][b] = cur_round;

  pair<int, int> l(a / 3, a % 3), r(b / 3, b % 3);
  pair<int, int> t = find_p(s[id]);
  int tt = t.first * 3 + t.second;
  double ans = 1e100;
  if (b != tt)
    ans = min(ans, go(s, id + 1, tt, b) + dt[a][tt]);
  if (a != tt)
    ans = min(ans, go(s, id + 1, a, tt) + dt[tt][b]);
  return dp[id][a][b] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  g[0][1] = "abc";
  g[0][2] = "def";
  g[1][0] = "ghi";
  g[1][1] = "jkl";
  g[1][2] = "mno";
  g[2][0] = "pqrs";
  g[2][1] = "tuv";
  g[2][2] = "wxyz";
  g[3][1] = " ";
  g[3][2] = "#";

  for (int i = 0; i < 12; ++i)
    for (int j = 0; j < 12; ++j) {
      double x = i / 3 - j / 3, y = i % 3 - j % 3;
      dt[i][j] = sqrt(x * x + y * y);
    }

  string line;
  cout << fixed << setprecision(2);
  while (getline(cin, line)) {
    string target;
    for (int i = 0; i + 1 < line.size(); ++i) {
      target.push_back(line[i]);
      if (find_p(line[i]) == find_p(line[i + 1]))
        target.push_back('#');
    }
    target.push_back(line.back());
    double extra = 0;
    for (auto &i : target) {
      auto tt = find_p(i);
      extra += (g[tt.first][tt.second].find(i) + 1);
    }
    cout << extra * 0.2 + go(target, 0, 3, 5) / 30.0 << endl;
    cur_round++;
  }
  return 0;
}
