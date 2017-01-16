#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct spell {
  int x, y, z;
  spell() {}
  void read() {
    string line; cin >> line;
    if (line.find("+") != string::npos ||
        line.find("-") != string::npos) {

      size_t id = line.find("+");
      if (id == string::npos)
        id = line.find("-");

      string first = line.substr(0, id);
      string second = line.substr(id);
      x = stoi(first.substr(0, first.find("d")));
      y = stoi(first.substr(first.find("d") + 1));
      z = stoi(second);
    } else {
      x = stoi(line.substr(0, line.find("d")));
      y = stoi(line.substr(line.find("d") + 1));
      z = 0;
    }
  }
  void print() {
    cout << x << ' ' << y << ' ' << z << endl;
  }
};

const int MN = 22;
double dp[MN][MN * MN];

double go(spell &dice, const int &H, int x, int cur) {
  if (x == 0)
    return cur + dice.z >= H;

  if (dp[x][cur] > -0.5) return dp[x][cur];

  double ans = 0, prob = 1.0 / dice.y;
  for (int i = 1; i <= dice.y; ++i) {
    ans += go(dice, H, x - 1, cur + i) * prob;
  }
  return dp[x][cur] = ans;
}

void solve() {
  int h, s; cin >> h >> s;
  vector<spell> p(s);
  for (spell &i : p) {
    i.read();
    // i.print();
  }
  double best = 0;
  for (spell &i : p) {
    for (int i = 0; i < MN; ++i)
      for (int j = 0; j < MN * MN; ++j)
        dp[i][j] = -1.0;
    best = max(best, go(i, h, i.x, 0));
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  cout << fixed << setprecision(12);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
