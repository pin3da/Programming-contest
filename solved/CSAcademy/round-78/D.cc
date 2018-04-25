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

const int N = 6, M = 1e5;

long long dp[N][M];

void solve() {
  int n, m, q;
  read(n, m, q);

  vector<vector<int>> data(n, vector<int>(m));
  read(data);

  for (int j = m - 1; j >= 0; j--) {
    for (int i = n - 1; i >= 0; i--) {
      dp[i][j] = dp[i][j + 1] + data[i][j];
      if (i > 0)
        dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + data[i][j]);
      if ((i + 1) < n)
        dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + data[i][j]);
    }
  }

  long long extra = 0;
  while (q--) {
    int r, c, t;
    read(r, c, t);
    r--; c--;
    data[r][c] = t;

    for (int j = c; j >= 0; j--) {
      set<long long> diffs;
      for (int i = n - 1; i >= 0; i--) {
        long long cur = dp[i][j + 1] + data[i][j];
        if (i > 0)
          cur = max(cur, dp[i - 1][j + 1] + data[i][j]);
        if ((i + 1) < n)
          cur = max(cur, dp[i + 1][j + 1] + data[i][j]);

        diffs.insert(cur - dp[i][j]);
        dp[i][j] = cur;
      }
      if (diffs.size() == 1) {
        extra += *diffs.begin();
        break;
      }
    }

    long long best = 0;
    for (int i = 0; i < n; i++) {
      best = max(best, dp[i][0]);
    }
    cout << best + extra << endl;
  }
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

