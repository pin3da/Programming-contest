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

struct segment {
  int x1, x2, y;
  segment(int a, int b, int c) : x1(a), x2(b), y(c) {}
  bool operator < (const segment &o) const {
    if (y == o.y) return make_pair(x1, x2) < make_pair(o.x1, o.x2);
    return y < o.y;
  }
};


const int MN = 100000 + 100;
struct seg_tree {
  int val[MN * 4 + 4];
  int pending[MN * 4 + 4];

  seg_tree() {
    memset(val, -1, sizeof val);
    memset(pending, -1, sizeof pending);
  }

  void propagate(int node, int b, int e) {
    if (pending[node] != -1) {
      val[node] = pending[node];
      if (b < e) {
        pending[node << 1] = pending[node];
        pending[node << 1 | 1] = pending[node];
      }
      pending[node] = -1;
    }
  }

  void set(int node, int b, int e, int from, int to, int v) {
    if (b > to || e < from) return;

    if (b >= from && e <= to) {
      pending[node] = v;
      propagate(node, b, e);
      return;
    }

    int mid = (b + e) >> 1;

    set(node << 1, b, mid, from, to, v);
    set(node << 1 | 1, mid + 1, e, from, to, v);
  }



  int query(int node, int b, int e, int pos) {
    propagate(node, b, e);

    if (b == e && b == pos) {
      return val[node];
    }

    int mid = (b + e) >> 1;
    if (pos <= mid)
      return query(node << 1, b, mid, pos);
    return query(node << 1 | 1, mid + 1, e, pos);
  }

  void set(int from, int to, int v) {
    return set(1, 0, MN - 1, from, to, v);
  }

  int query(int pos) {
    return query(1, 0, MN - 1, pos);
  }
};

seg_tree tree;
int le[MN], ri[MN];

int get_fall(vector<segment> &all, int x) {
  int id = tree.query(x);
  if (id == -1) return x;

  if ((x - all[id].x1) <= (all[id].x2 - x))
    return le[id];
  return ri[id];
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;

  vector<segment> all;
  for (int i = 0; i < n; i++) {
    int a, b, c; cin >> a >> b >> c;
    all.emplace_back(a, b, c);
  }

  sort(all.begin(), all.end());


  for (int i = 0; i < n; i++) {
    int x1 = all[i].x1, x2 = all[i].x2;
    le[i] = get_fall(all, x1);
    ri[i] = get_fall(all, x2);
    tree.set(x1, x2, i);
  }

  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    cout << get_fall(all, x) << endl;
  }
  return 0;
}
