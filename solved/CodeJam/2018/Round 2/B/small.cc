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

const int MN = 51;
int dp[MN * MN + 10][MN][MN];

int go(vector<pair<int, int>> &op, int id, int r, int b) {
  if (id == int(op.size())) {
    return 0;
  }

  if (dp[id][r][b] != -1)
    return dp[id][r][b];

  int best = go(op, id + 1, r, b);
  if (r >= op[id].first && b >= op[id].second) {
    best = max(best, go(op, id + 1, r - op[id].first, b - op[id].second) + 1);
  }
  return dp[id][r][b] = best;
}

void solve() {
  int r, b; cin >> r >> b;
  vector<pair<int,int>> opts;
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= b; j++) {
      if (i == 0 && j == 0) continue;
      opts.emplace_back(i, j);
    }
  }
  memset(dp, -1, sizeof dp);
  cout << go(opts, 0, r, b) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

