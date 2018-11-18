#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


const int MN = 200000;  // limit for array size

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

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int q;
  cin >> q;
  vector<pair<pair<int, int>, int>> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i].first.first;
    cin >> queries[i].first.second;
    queries[i].second = i;
  }

  sort(queries.begin(), queries.end());

  vector<int> sieve(MN);
  sieve[0] = sieve[1] = MN + 100;
  for (int i = 2; i < int(sieve.size()); i++) {
    if (sieve[i] == 0) {
      sieve[i] = i;
      for (int j = i + i; j < int(sieve.size()); j += i)
        sieve[j] = i;
    }
  }

  seg_tree tree(sieve.size());

  vector<int> ans(queries.size());

  int last = 2; // [,)
  for (auto it : queries) {
    while (last <= it.first.first) {
      tree.modify(sieve[last], 1);
      last++;
    }
    ans[it.second] = tree.query(0, it.first.second + 1);
  }

  for (auto it : ans) {
    cout << it << endl;
  }
  return 0;
}
