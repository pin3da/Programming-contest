#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 2 * 1e5 + 100;  // limit for array size
struct seg_tree {
  int n;
  int t[2 * MN];

  seg_tree() : n(MN) {}

  void clear() {
    memset(t, 0, sizeof t);
  }

  // Single modification, range query.
  void add(int p, int value) {  // set value at position p
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

seg_tree tree_l, tree_g;

void solve() {

  tree_l.clear();
  tree_g.clear();

  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<int, int> > a(n), b(m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  for (int i = 0; i < m; i++)
    scanf("%d%d", &b[i].first, &b[i].second);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int j = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (j < m && b[j].first < a[i].first) {
      tree_l.add(b[j].second, 1);
      j++;
    }
    ans += tree_l.query(a[i].second, n + m + 1);
  }

  j = m - 1;
  for (int i = n - 1; i >= 0; i--) {
    while (j >= 0 && b[j].first > a[i].first) {
      tree_g.add(b[j].second, 1);
      j--;
    }
    ans += tree_g.query(0, a[i].second + 1);
  }

  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; i++) {
    printf("Case %d: ", i);
    solve();
  }
  return 0;
}
