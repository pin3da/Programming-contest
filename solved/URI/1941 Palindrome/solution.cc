#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 2222;
pair<int, int> dp[MN][MN];
bool seen[MN][MN];

pair<int, int> go(string &line, vector<int> &s, int i, int j) {
  if (j < i) return make_pair(0, 0);
  if (j == i) return make_pair(s[i], 1);
  if (seen[i][j])
    return dp[i][j];
  seen[i][j] = true;
  pair<int, int> ans = go(line, s, i + 1, j - 1);
  if (line[i] == line[j]) {
    pair<int, int> op = go(line, s, i + 1, j - 1);
    op.first += s[i] + s[j];
    op.second += 2;
    ans = max(ans, op);
  }
  ans = max(ans, go(line, s, i + 1, j));
  ans = max(ans, go(line, s, i, j - 1));
  return dp[i][j] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    int n;cin >> n;
    vector<int> s(line.size());
    int t;
    while (n--) {
      cin >> t;
      s[t - 1] = 1;
    }
    memset(seen, 0, sizeof seen);
    cout << go(line, s, 0, line.size() - 1).second << endl;
  }
  return 0;
}
