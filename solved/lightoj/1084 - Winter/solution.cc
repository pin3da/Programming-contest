using namespace std;
#include <bits/stdc++.h>

const int inf = 1 << 25;

const int N = 100001 + 10;
struct seg_tree {
  int n;
  int t[2 * N];

  seg_tree(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i)
      t[n + i] = inf;
  }

  void build() {
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
  }

  void modify(int p, const int &value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
  }

  int query(int l, int r) {  // min on interval [l, r)
    int res = inf;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = min(res, t[l++]);
      if (r&1) res = min(res, t[--r]);
    }
    return res;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  for (int i = 0; i < n; ++i)
    cin >> l[i];

  if (n < 3) {
    puts("-1");
    return;
  }

  sort(l.begin(), l.end());
  vector<int> last_rechable(n);
  int i = 0, j = 0;
  while (i < n) {
    while (j < n && l[j] - l[i] <= 2 * k)
      j++;
    last_rechable[i] = j - 1;
    i++;
  }

  seg_tree rmq(n + 1);
  rmq.build();

  rmq.modify(n, 0);
  for (int i = n - 3; i >= 0; --i)
    rmq.modify(i, rmq.query(i + 3, last_rechable[i] + 2) + 1);

  if (rmq.query(0, 1) < inf)
    printf("%d\n", rmq.query(0, 1));
  else
    puts("-1");
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
