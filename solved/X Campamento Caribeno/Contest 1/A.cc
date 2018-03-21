#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MN = 5 * 1e5 + 10;

const long long inf = 1e12;
const int M = (1 << 30) - 1;

#define neg(x) (~x)
#define twice(_i) for (int _i = 0; _i < 2; _i++)

struct node {
  long long min, val[2], tag[2]; //0 and, 1 or
  node(long long a = inf) : min(a) {
    tag[0] = neg(0), tag[1] = 0,
      val[0] = a, val[1] = a;
  }
};

struct segtree {
  node T[MN * 4 + 10];

  void merge_ch(int node, int b, int e) {
    T[node].val[0] = T[node << 1].val[0] & T[node << 1 | 1].val[0];
    T[node].val[1] = T[node << 1].val[1] | T[node << 1 | 1].val[1];
    T[node].min = min(T[node << 1].min, T[node << 1 | 1].min);
  }

  void build(vector<int> &a, int cur, int b, int e) {
    T[cur].tag[0] = neg(0);
    T[cur].tag[1] = 0;
    if (b == e) {
      T[cur] = node(a[b]);
      return;
    }
    int mid = (b + e) >> 1;
    build(a, cur << 1, b, mid);
    build(a, cur << 1 | 1, mid + 1, e);
    merge_ch(cur, b, e);
  }

  void apply_tag(long long &v, int and_mask, int or_mask) {
    v = (v & and_mask) | or_mask;
  }

  void push_down(int node, int b, int e) {
    if (b >= e) return;
    if (!neg(T[node].tag[0]) && !neg(T[node].tag[1])) return;

    apply_tag(T[node << 1].min,
        T[node].tag[0], T[node].tag[1]);
    apply_tag(T[node << 1 | 1].min,
        T[node].tag[0], T[node].tag[1]);

    if (b < e) {
      twice(i) {
        apply_tag(T[node << 1].tag[i],
            T[node].tag[0], T[node].tag[1]);
        apply_tag(T[node << 1 | 1].tag[i],
            T[node].tag[0], T[node].tag[1]);

        apply_tag(T[node << 1].val[i],
            T[node].tag[0], T[node].tag[1]);
        apply_tag(T[node << 1 | 1].val[i],
            T[node].tag[0], T[node].tag[1]);
      }
    }

    T[node].tag[0] = neg(0);
    T[node].tag[1] = 0;
  }

  void update_or(int node, int b, int e, int l, int r, long long val) {
    push_down(node, b, e);
    if (b > r || e < l) return;
    if (!(neg(T[node].val[0]) & val)) return;
    if (l <= b && e <= r && (neg(T[node].val[0]) & val) == (neg(T[node].val[1]) & val)) {
      T[node].min |= val;
      twice(i) T[node].val[i] |= val;
      T[node].tag[1] |= val;
      return;
    }
    int mid = (b + e) >> 1;
    update_or(node << 1, b, mid, l, r, val);
    update_or(node << 1 | 1, mid + 1, e, l, r, val);
    merge_ch(node, b, e);
  }

  void update_and(int node, int b, int e, int l, int r, long long val) {
    push_down(node, b, e);
    if (b > r || e < l) return;
    if (!(T[node].val[1] & neg(val))) return;
    if (l <= b && e <= r && (T[node].val[1] & neg(val)) == (T[node].val[0] & neg(val))) {
      T[node].min &= val;
      twice(i) T[node].val[i] &= val;
      twice(i) T[node].tag[i] &= val;
      return;
    }
    int mid = (b + e) >> 1;
    update_and(node << 1, b, mid, l, r, val);
    update_and(node << 1 | 1, mid + 1, e, l, r, val);
    merge_ch(node, b, e);
  }

  long long query(int node, int b, int e, int l, int r) {
    push_down(node, b, e);
    if (b > r || e < l) return inf;
    if (l <= b && e <= r) return T[node].min;
    int mid = (b + e) >> 1;
    long long ans = min(
        query(node << 1, b, mid, l, r),
        query(node << 1 | 1, mid + 1, e, l, r)
        );
    return ans;
  }
};

segtree tree;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (auto &it : a) cin >> it;

  tree.build(a, 1, 0, n - 1);

  int q; cin >> q;
  while (q--) {
    char t; cin >> t;
    int l, r, x;
    cin >> l >> r;
    l--, r--;
    if (t == '&') {
      cin >> x;
      tree.update_and(1, 0, n - 1, l, r, x);
    }
    if (t == '|') {
      cin >> x;
      tree.update_or(1, 0, n - 1, l, r, x);
    }
    if (t == '?') {
      cout << tree.query(1, 0, n - 1, l, r) << endl;
    }

  }

  return 0;
}

