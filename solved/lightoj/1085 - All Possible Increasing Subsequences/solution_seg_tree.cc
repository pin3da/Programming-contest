using namespace std;
#include <bits/stdc++.h>

const int N = 100000 + 10;
const int mod = 1000000007;
struct seg_tree{
  int n;
  long long t[2 * N];
  void build() {
    for (int i = n - 1; i > 0; --i) t[i] = (t[i<<1] + t[i<<1|1]) % mod;
  }
  void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = (t[p] + t[p^1]) % mod;
  }
  int query(int l, int r) { // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = (res + t[l++]) % mod;
      if (r&1) res = (res + t[--r]) % mod;
    }
    return res;
  }
};


struct entry{
  int val, index;
  entry () {}
  entry(int a, int b) : val(a), index(b) {}
  bool operator < (const entry &o) const {
    if (val == o.val)
      return index > o.index;
    return val < o.val;
  }
};

seg_tree tree;

void solve() {
  int n, t;
  cin >> n;
  tree.n = n;
  vector<entry> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    a[i] = entry(t, i);
  }
  sort(a.begin(), a.end());
  memset(tree.t, 0, sizeof tree.t);
  for (int i = 0; i < a.size(); ++i)
    tree.modify(a[i].index, tree.query(0, a[i].index + 1) + 1);
  printf("%lld\n", tree.query(0, n) % mod);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
