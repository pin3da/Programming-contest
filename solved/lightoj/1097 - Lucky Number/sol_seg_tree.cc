using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define gen(node) int l = node << 1, r = (node << 1) | 1,  m = (b + e) >> 1;

const int MN = 100000 + 10;
const int ML = 1429431;
const int N  = ML + 1;

struct seg_tree {
  int t[1 << 22];
  int data[N], s;

  void clear() { s = 0; memset(t, 0, sizeof t); }

  void build(int node, int b, int e) {
    if (b == e) {
      if (b < s) t[node] = 1;
      return;
    }
    gen(node);
    build(l, b, m);build(r, m + 1, e);
    t[node] = t[l] + t[r];
  }

  int seek_and_destroy(int node, int b, int e, int value, int destroy = 0) {
    if (b == e) {
      if (destroy) {
        t[node] = 0;
        s--;
      }
      return b;
    }
    gen(node);
    int ans;
    if (value <= t[l]) ans = seek_and_destroy(l, b, m, value, destroy);
    else               ans = seek_and_destroy(r, m + 1, e, value - t[l], destroy);
    t[node] = t[l] + t[r];
    return ans;
  }

  void add(int value) {
    data[s++] = value;
  }
};

seg_tree tree;

int main() {

  tree.clear();
  for (int i = 1; i <= ML; i += 2)
    tree.add(i);

  tree.build(1, 0, N);

  int i = 2;
  while (true) {
    int idx = tree.seek_and_destroy(1, 0, N, i);
    if (idx >= N) break;
    int step = tree.data[idx];
    for (int j = step; j < N; j += step) {
      int cur = tree.data[tree.seek_and_destroy(1, 0, N, j, true)];
      if (cur == 0) break;
      j--;
    }
    ++i;
  }


  int tc, t;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cin >> t;
    printf("Case %d: %d\n", i + 1, tree.data[tree.seek_and_destroy(1, 0, N, t)]);
  }
  return 0;
}
