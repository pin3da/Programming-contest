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

int is_set(int mask, int i, int j, int n) {
  int id = i * n + j;
  return (mask >> id) & 1;
}

bool valid(vector<vector<int>> &g, int mask) {
  int n = g.size();
  for (int i = 0; i < n; i++) {
    vector<int> row, col;
    for (int j = 0; j < n; j++) {
      if (!is_set(mask, i, j, n)) {
        row.push_back(g[i][j]);
      }
      if (!is_set(mask, j, i, n)) {
        col.push_back(g[j][i]);
      }
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    for (int j = 1; j < int(row.size()); j++) {
      if (row[j] == row[j - 1])
        return false;
    }
    for (int j = 1; j < int(col.size()); j++) {
      if (col[j] == col[j - 1])
        return false;
    }
  }
  return true;
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  read(g);

  int total = n * n;
  int best = n * n;
  for (int mask = 0; mask < (1 << total); mask++) {
    if (valid(g, mask)) {
      best = min(best, __builtin_popcount(mask));
    }
  }
  cout << best << endl;
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

