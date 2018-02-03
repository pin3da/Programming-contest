#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif

const int MN = 200000 + 100;

struct seg_tree {
  int n;  // array size
  int t[2 * MN];

  seg_tree(int _n) : n(_n) {}

  void clear() {
    memset(t, 0, sizeof t);
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  // Single modification, range query.
  void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
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


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<int> data(n);
  for (auto &i : data) cin >> i;

  string move; cin >> move;

  seg_tree tree(n + 10);
  tree.clear();

  int last = 0;
  int ok = true;
  for (int i = 0; ok && i < n - 1; i++) {
    tree.modify(data[i] - 1, 1);

    if (move[i] == '0') {
      int sum = tree.query(last, i + 1);
      int len = (i - last + 1);
      if (sum != len) {
        ok = false;
      }
      last = i + 1;
    }
  }
  puts(ok ? "YES" : "NO");

  return 0;
}
