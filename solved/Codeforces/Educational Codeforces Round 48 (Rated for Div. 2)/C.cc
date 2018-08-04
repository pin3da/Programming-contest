#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

pair<vector<long long>, vector<long long>> right(vector<vector<int>> &g) {
  int n = g[0].size();
  vector<long long> up(n), s(n);
  long long sum = 0, acc = 0, items = 0;
  for (int i = n - 1; i >= 0; i--) {
    items++;
    acc += g[1][i] * items;
    acc += sum;
    up[i] = acc;
    items++;
    sum += g[0][i] + g[1][i];
    s[i] = sum;
  }
  return {up, s};
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n; cin >> n;
  vector<vector<int>> g(2, vector<int> (n));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      cin >> g[i][j];

  auto tmp = right(g);
  auto up = tmp.first;
  auto sum_up = tmp.second;

  swap(g[0], g[1]);
  tmp = right(g);
  auto down = tmp.first;
  auto sum_down = tmp.second;

  swap(g[0], g[1]);

  long long best = 0, len = 0, pref = 0;
  for (int i = 0; i < n; i++) {
    if ((i & 1) == 0) {
      best = max(best, up[i] + sum_up[i] * len + pref);
      pref += g[0][i] * len;
      len++;
      pref += g[1][i] * len;
      len++;
      if (i + 1 < n) {
        best = max(best, down[i + 1] + sum_down[i + 1] * len + pref);
      }
    } else {
      pref += g[1][i] * len;
      len++;
      pref += g[0][i] * len;
      len++;
      if (i + 1 < n) {
        best = max(best, up[i + 1] + sum_up[i + 1] * len + pref);
      }
    }
  }

  best = max(best, pref);

  cout << best << endl;

  return 0;
}
