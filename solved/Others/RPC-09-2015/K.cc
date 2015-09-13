#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl

typedef pair<int, int> state;

const int MN = 2002;
int seen[MN][MN];
state dp[MN][MN];
state go(string &line, vector<int> &c, int i, int j) {
  if (i >= j) {
    return make_pair((i == j && c[i]), i == j);
  }

  if (seen[i][j])
    return dp[i][j];

  state op = max(go(line, c, i + 1, j), go(line, c, i, j - 1));
  if (line[i] == line[j]) {
    state p = go(line, c, i + 1, j - 1);
    p.second += 2;
    if (c[i]) p.first++;
    if (c[j]) p.first++;
    op = max(op, p);
  }

  seen[i][j] = true;
  return dp[i][j] = op;
}

int main() {

  string line;
  while (cin >> line) {
    int t, p; cin >> t;
    vector<int> cool(line.size());
    for (int i = 0; i < t; ++i) {
      cin >> p;
      cool[p - 1] = 1;
    }
    memset(seen, 0, sizeof seen);
    cout << go(line, cool, 0, line.size() - 1).second << endl;
  }
  return 0;
}
