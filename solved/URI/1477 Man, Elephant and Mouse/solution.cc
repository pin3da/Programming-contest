#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct state {
  int a, b, c;
  state () : a(0), b(0), c(0) {}
  state (int x, int y, int z) : a(x), b(y), c(z) {}
  void shift(int n) {
    n %= 3;
    if (n == 1) {
      int t = c;
      c = b;
      b = a;
      a = t;
    }
    if (n == 2) {
      int t = a;
      a = b;
      b = c;
      c = t;
    }
  }
  state operator + (const state &o) const {
    return state(a + o.a, b + o.b, c + o.c);
  }
};

struct seg_tree {
  vector<state> m;
  vector<long long> p;
  seg_tree (int n) {
    m.assign(4 * n + 10, state(0, 0, 0));
    p.assign(4 * n + 10, 0);
  }

  void build(int node, int b, int e) {
    if (b == e)
      return (void) (m[node] = state(1, 0, 0));
    int mid = (b + e) >> 1;
    build(node << 1, b, mid);
    build(node << 1 | 1, mid + 1, e);
    m[node] = m[node << 1] + m[node << 1 | 1];
  }

  void push_down(int node, int b, int e, int d = 2) {
    if (b > e) return;
    if (p[node] == 0) return;
    m[node].shift(p[node]);
    if (b < e) {
      p[node << 1] += p[node];
      p[node << 1 | 1] += p[node];
    }
    p[node] = 0;
  }

  void shift(int node, int b, int e, int l, int r, long long val) {
    push_down(node, b, e);
    if (b > r || e < l) return;
    if (b >= l && e <= r) {
      p[node] += val;
      push_down(node, b, e);
      return;
    }
    int mid = (b + e) >> 1;

    shift(node << 1, b, mid, l, r, val);
    shift(node << 1 | 1, mid + 1, e, l, r, val);
    m[node] = m[node << 1] + m[node << 1 | 1];
  }

  state query(int node, int b, int e, int l, int r) {
    push_down(node, b, e);
    if (e < l || b > r ) return state(0, 0, 0);
    if ( b >= l && e <= r) {
      assert(p[node] == 0);
      return m[node];
    }

    int mid = (b + e) >> 1;
    return  query(node << 1, b, mid, l, r)
      + query(node << 1 | 1, mid + 1, e, l, r);
  }
};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    string op;
    seg_tree tree(n);
    tree.build(1, 0, n - 1);
    int a, b;
    while (m--) {
      cin >> op >> a >> b;
      a--;b--;
      if (op == "M") {
        tree.shift(1, 0, n - 1, a, b, 1);
        state cur = tree.query(1, 0, n - 1, a, b);
        // cout << cur.a << ' ' << cur.b << ' ' << cur.c << endl;

      } else {
        state cur = tree.query(1, 0, n - 1, a, b);
        cout << cur.a << ' ' << cur.b << ' ' << cur.c << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
