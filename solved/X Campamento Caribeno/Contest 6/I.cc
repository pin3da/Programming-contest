#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  read(g);
  vector<int> best(m), second(m);

  if (n == 1) {
    sort(g[0].begin(), g[0].end());
    g[0][m - 1] *= 2;
    cout << accumulate(g[0].begin(), g[0].end(), 0LL) << endl;
    return;
  }
  for (int j = 0; j < m; j++) {
    vector<int> cur;
    for (int i = 0; i < n; i++) {
      cur.emplace_back(g[i][j]);
    }
    sort(cur.begin(), cur.end());
    best[j] = cur[0];
    second[j] = cur[1];
  }

  long long ans = 0,
       total = accumulate(best.begin(), best.end(), 0LL);
  debug(total);
  for (int j = 0; j < m; j++) {
    long long opt = min(2 * best[j], second[j]);
    opt = total - best[j] + opt;
    ans = max(ans, opt);
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

