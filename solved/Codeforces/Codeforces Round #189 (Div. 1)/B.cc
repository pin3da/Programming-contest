#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 1e5 + 100;
int a[MN];
int b[MN];

struct seg_tree {
  int n;  // array size
  int t[2 * MN];
  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
  }

  // Single modification, range query.
  void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
  }

  int query(int l, int r) {  // [l, r)
    int res = -1e6;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, t[l++]);
      if (r&1) res = max(res, t[--r]);
    }
    return res;
  }
};

seg_tree t1, t2;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;
  while (cin >> m) {
    t1.n = m + 10;
    t2.n = m + 10;
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }

    int ans = 0;
    memset(t2.t, -1, sizeof t2.t);
    memset(t1.t, -1, sizeof t1.t);
    for (int i = 0; i < m; ++i) {
      int j = t1.query(a[i], m + 1);
      if (j >= 0) {
        int tmp = max(t2.query(j + 1, i), 0);
        t2.modify(i, tmp + 1);
        ans = max(ans, tmp + 1);
      } else {
        t2.modify(i, -1);
      }
      t1.modify(a[i], i);
    }
    cout << ans << endl;
  }

  return 0;
}
