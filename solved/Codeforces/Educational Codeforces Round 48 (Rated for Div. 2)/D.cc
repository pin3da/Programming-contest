#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

bool solve(vector<long long> &r, vector<long long> &c, vector<vector<long long>> &ans, long long mask) {
  long long acc = 0;
  for (auto it : r)  acc ^= (it & mask);
  for (auto it : c)  acc ^= (it & mask);
  if (acc != 0) return false;

  int n = r.size(), m = c.size();

  long long acc_row = 0;

  for (int i = 0; i < n - 1; i++) {
    ans[i][0] |= (r[i] & mask);
    acc_row ^= (ans[i][0] & mask);
  }

  ans[n - 1][0] |= (c[0] & mask) ^ acc_row;

  long long acc_col = ans[n - 1][0];
  for (int j = 1; j < m; j++) {
    ans[n - 1][j] |= (c[j] & mask);
    acc_col ^= (ans[n - 1][j] & mask);
  }

  return true;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  vector<long long> rows(n), cols(m);
  for (auto &it : rows) cin >> it;
  for (auto &it : cols) cin >> it;

  vector<vector<long long>> ans(n, vector<long long> (m));
  long long mask = 1;
  int ok = true;
  while (ok && (mask < (1LL << 33))) {
    ok &= solve(rows, cols, ans, mask);
    mask <<= 1;
  }

  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (auto r : ans) {
      for (auto c : r) {
        cout << c << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
