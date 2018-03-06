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

const int MN = 501;

int data[MN][MN];
int dp[MN][MN];
int memo[MN][MN];
const int inf = 1e8;
int n, m, k;


int cost(int row, int skip) {
  if (memo[row][skip] == -1) {
    int last = -1, ones = 0;
    deque<int> dist;
    for (int i = 0; i < m; i++) {
      if (data[row][i] == 1) {
        if (ones) {
          dist.push_back(i - last + 1);
        }
        last = i;
        ones++;
      }
    }

    if (ones <= skip)
      memo[row][skip] = 0;
    else if (ones == (skip - 1)) {
      memo[row][skip] = 1;
    } else {
      int rem = ones - skip - 1;
      int ans = inf;
      int acc = accumulate(dist.begin(), dist.begin() + rem, 0);
      ans = min(ans, acc);
      for (int i = 0; i + rem < int(dist.size()); i++) {
        ans = min(ans, acc);
        acc += dist[i + rem];
        acc -= dist[i];
      }
      ans = min(ans, acc);
      memo[row][skip] = ans - rem + 1;
    }
  }
  return memo[row][skip];
}

void solve() {
  read(n, m, k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char t; cin >> t;
      data[i][j] = t - '0';
    }
  }

  memset(memo, -1, sizeof memo);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = inf;
      for (int a = 0; a <= j; a++) {
        dp[i][j] = min(dp[i][j], cost(i, a) + dp[i + 1][j - a]);
      }
    }
  }

  cout << dp[0][k] << endl;
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

