using namespace std;
#include <bits/stdc++.h>

const long long inf = 1LL << 40;
const int MN = 33;

pair<long long, long long> dp[MN][MN];

pair<long long, long long> go(const string &a, const string &b, int i, int j) {

  if (dp[i][j].first != -1)
    return dp[i][j];

  if (i >= a.size() && j < b.size())
    return dp[i][j] = make_pair(b.size() - j, 1);
  if (i < a.size() && j >= b.size())
    return dp[i][j] = make_pair(a.size() - i, 1);
  if (i >= a.size() && j >= b.size())
    return dp[i][j] = make_pair(0, 1);


  long long best = inf;
  if (a[i] == b[j])
    best = min(best, go(a, b, i + 1, j + 1).first);
  best = min(best, go(a, b, i + 1, j).first);
  best = min(best, go(a, b, i, j + 1).first);

  long long ways = 0;

  if (a[i] == b[j]) {
    if (go(a, b, i + 1, j + 1).first == best)
      ways += go(a, b, i + 1, j + 1).second;
  }
  else {
    if (go(a, b, i + 1, j).first == best)
      ways += go(a, b, i + 1, j).second;

    if (go(a, b, i, j + 1).first == best)
      ways += go(a, b, i, j + 1).second;
  }
  return dp[i][j] = make_pair(best + 1, ways);
}

void solve() {
  string a, b;
  cin >> a >> b;
  cout << go(a, b, 0, 0).first << " " << go(a, b, 0, 0).second << endl;
}


int main() {
  int n;
  cin >> n;
  for (int tc = 0; tc < n; ++tc) {
    cout << "Case " << tc + 1 << ": ";
    for (int i = 0; i < MN; ++i) {
      for (int j = 0; j < MN; ++j) {
        dp[i][j] = make_pair(-1, -1);
      }
    }
    solve();
  }
  return 0;
}
