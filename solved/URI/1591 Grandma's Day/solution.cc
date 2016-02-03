#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n), p(n);
  vector<string> g2(m), p2(m);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }

  for (int j = 0; j < m; ++j) {
    string cur;
    for (int i = 0; i < n; ++i) {
      cur.push_back(g[i][j]);
    }
    g2[j] = cur;
  }
  int q;
  cin >> q;
  string line;
  while (q--) {
    cin >> line;
    string rr = line;
    reverse(rr.begin(), rr.end());
    int ans = 0;
    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i)
        if (i + line.size() <= m) {
          if (g[j].substr(i, line.size()) == line)
            ans++;
          // if (line != rr && g[j].substr(i, line.size()) == rr)
          //  ans++;
        }



    for (int j = 0; j < m; ++j)
      for (int i = 0; i < n; ++i)
        if (i + line.size() <= n) {
          if (line.size() > 1 && g2[j].substr(i, line.size()) == line)
            ans++;
          //if (line.size() > 1 && line != rr && g2[j].substr(i, line.size()) == rr)
          //  ans++;
        }



    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = 0;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}

