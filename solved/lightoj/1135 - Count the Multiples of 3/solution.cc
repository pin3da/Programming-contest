#include<bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 100;

struct seg_tree {
  int t[(MN << 2) + 4][3];
  int p[(MN << 2) + 4];
  int n;

  void init(int node, int b, int e) {
    if (b == e) {
      t[node][0] = 1;
      return;
    }
    int mid = (b + e) >> 1;
    init(node << 1, b, mid);
    init(node << 1 | 1, mid + 1, e);
    t[node][0] = t[node << 1][0] + t[node << 1 | 1][0];
  }

  void init(int len) {
    n = len;
    memset(t, 0, sizeof t);
    memset(p, 0, sizeof p);
    init(1, 0, n - 1);
  }

  void propagate(int node, int b, int e) {
    p[node] %= 3;

    for (int k = 0; k < p[node]; k++) {
      swap(t[node][0], t[node][1]);
      swap(t[node][1], t[node][2]);
    }

    if (b < e) {
      p[node << 1] += p[node];
      p[node << 1 | 1] += p[node];
    }

    p[node] = 0;
  }

  void add(int node, int b, int e, int i, int j) {
    propagate(node, b, e);

    if (b > j || e < i) // outside
      return;

    if (b >= i && e <= j) {
      p[node]++;
      propagate(node, b, e);
      return;
    }

    int mid = (b + e) >> 1;
    add(node << 1, b, mid, i, j);
    add(node << 1 | 1, mid + 1, e, i, j);

    for (int k = 0; k < 3; k++) {
      t[node][k] = t[node << 1][k] + t[node << 1 | 1][k];
    }
  }

  void increase(int b, int e) {
    add(1, 0, n - 1, b, e);
  }

  int query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);

    if (b > j || e < i) // outside
      return 0;


    if (b >= i && e <= j) {
      return t[node][0];
    }

    int mid = (b + e) >> 1;
    return query(node << 1, b, mid, i, j) + query(node << 1 | 1, mid + 1, e, i, j);
  }

  int query(int b, int e) {
    return query(1, 0, n - 1, b, e);
  }
};

seg_tree tree;

void solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  tree.init(n);
  while (q--) {
    int t, b, e;
    scanf("%d%d%d",  &t, &b, &e);
    if (t == 0) {
      tree.increase(b, e);
    } else {
      printf("%d\n", tree.query(b, e));
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);

  for (int i = 1; i <= tc; i++) {
    printf("Case %d:\n", i);
    solve();
  }
  return 0;
}

