#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int MN = 1e6 + 1;
struct seg_tree {
  int n;
  int t[2 * MN];

  seg_tree() : n(MN) {}

  // Single modification, range query.
  void modify(int p, int value) {  // set value at position p
    for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};

seg_tree tree;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long n, a;
  cin >> n >> a;
  vector<pair<int, int>> data(n);
  for (auto &it : data) cin >> it.first >> it.second;

  sort(data.begin(), data.end());

  int best = 0;
  for (auto p : data) {
    tree.modify(p.second, +1);
    int hi = min<long long>((a / p.first) + 1, MN);
    best = max(best, tree.query(0, hi));
  }
  cout << best << endl;

  return 0;
}
