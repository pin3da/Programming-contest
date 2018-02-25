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

const long long inf = 1LL << 60;

const int MN = 4000 + 10;
long long c[MN][MN];
long long dp[2][MN + 10];
int cur = 0;

long long cost(int i, int j) {
  return c[j][j] - c[i - 1][j] - c[j][i - 1] + c[i - 1][i - 1];
}

void comp(int l, int r, int le, int re) {
  if (l > r) return;

  int mid = (l + r) >> 1;

  int best = max(le, mid);
  for (int i = best; i <= re; i++) {
    if (dp[cur ^ 1][best + 1] + cost(mid, best) > dp[cur ^ 1][i + 1] + cost(mid, i))
      best = i;
  }

  dp[cur][mid] = dp[cur ^ 1][best + 1] + cost(mid, best);

  comp(l, mid - 1, le, best);
  comp(mid + 1, r, best, re);
}

void init(int n) {
  for (int i = 0; i <= n; i++)
    dp[cur][i] = inf;
  dp[cur][n + 1] = 0;
}

void solve() {
  int n, k;
  read(n, k);

  vector<vector<int>> tmp(n, vector<int>(n));
  read(tmp);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      c[i][j] = tmp[i - 1][j - 1] + c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];


  init(n);

  for (int i = 0; i < k; i++) {
    cur ^= 1;
    comp(1, n, 1, n);
  }

  cout << dp[cur][1] / 2 << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}

