using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define gen(node) int l = node << 1, r = (node << 1) | 1,  m = (b + e) >> 1;


const int MN = 100000 + 10;
const int MQ = 50000 + 50;
const int N  = MN + MQ;

struct seg_tree {
  int t[1 << 20]; // 1 <<  (ceil(log(N) / log(2)) + 2);
  int data[N], s, cur;

  void clear() {
    s = cur = 0;
    memset(t, 0, sizeof t);
  }

  void build(int node, int b, int e) {
    if (b == e) {
      if (b < s)
        t[node] = 1;
      return;
    }
    gen(node);
    build(l, b, m);build(r, m + 1, e);
    t[node] = t[l] + t[r];
  }

  void inc(int node, int b, int e, int p, int &val) {
    if (b == e) {
      t[node] = 1;
      data[cur++] = val;
      s++;
      return;
    }
    gen(node);
    if (p <= m) inc(l, b, m, p, val);
    else        inc(r, m + 1, e, p, val);
    t[node] = t[l] + t[r];
  }

  int query(int node, int b, int e, int value) {
    if (b == e) {
      t[node] = 0;
      s--;
      return b;
    }
    gen(node);
    int ans;
    if (value <= t[l]) ans = query(l, b, m, value);
    else               ans = query(r, m + 1, e, value - t[l]);
    t[node] = t[l] + t[r];
    return ans;
  }

  void add(int value) {
    cur++;
    data[s++] = value;
  }

};

seg_tree tree;

void solve() {
  int n, q, t;
  cin >> n >> q;
  int ts = n + q + 10;
  tree.clear();

  for (int i = 0; i < n; ++i) {
    cin >> t;
    tree.add(t);
  }
  tree.build(1, 0, ts);

  char op;
  int val;
  while (q--) {
    cin >> op >> val;
    if (op == 'c') {
      if (val > tree.s) {
        puts("none");
      } else {
        int index = tree.query(1, 0, ts, val);
        // D(index);
        printf("%d\n", tree.data[index]);
      }
    } else {
      tree.inc(1, 0, ts, n, val);
      n++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
