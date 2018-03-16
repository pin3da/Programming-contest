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

struct node {
  long long min;
  int zeros, ones;
  node() : min(0), zeros(0), ones(0) {}
  node(long long a) : min(a), zeros(0), ones(0) {}
};

struct segtree {
  node T[MN * 4 + 10];

  void update(int cur, int b, int e) {
    if (b < e) {
      T[cur].min = min(T[cur << 1].min, T[cur << 1 | 1].min);
    }
  }

  void push_down(int cur, int b, int e) {
    if (b < e) {
      T[cur << 1].zeros |= T[cur].zeros;
      T[cur << 1].ones |= T[cur].ones;

      T[cur << 1 | 1].zeros |= T[cur].zeros;
      T[cur << 1 | 1].ones |= T[cur].ones;

      if ((T[cur].zeros | T[cur].ones) == M) {
        T[cur << 1].min = T[cur].min;
        T[cur << 1 | 1].min = T[cur].min;
      }

    }
  }

  void build(vector<int> &a, int cur, int b, int e) {
    if (b == e) {
      T[cur] = node(a[b]);
      T[cur].zeros = M;
      T[cur].ones = M;
    } else {
      int mid = (b + e) >> 1;
      build(a, cur << 1, b, mid);
      build(a, cur << 1 | 1, mid + 1, e);
      update(cur, b, e);
    }
  }

  void set_zero(int cur, int b, int e, int l, int r, int mask) {
    push_down(cur, b, e);

    if (b > r || e < l)
      return;

    if (b >= l && e <= r) {
      if (b == e) {
        T[cur].min &= (M ^ mask); // leaf
        debug("set leaf 0", b, T[cur].min, mask);
        return;
      } else {
        T[cur].ones &= (M  ^ mask);
        T[cur].zeros |= mask;
      }
      if (((T[cur].zeros | T[cur].ones)) == M) { // all bits known
        T[cur].min &= (M ^ mask); // set bits on mask to 0;
        return;
      }
    }


    debug("befor split", b, e, T[cur].min);

    int mid = (b + e) >> 1;
    set_zero(cur << 1, b, mid, l, r, mask);
    set_zero(cur << 1 | 1, mid + 1, e, l, r, mask);

    update(cur, b, e);

    debug("after split" , b, e, T[cur].min);
  }

  void set_ones(int cur, int b, int e, int l, int r, int mask) {
    push_down(cur, b, e);

    if (b > r || e < l)
      return;

    if (b >= l && e <= r) {
      if (b == e) {
        T[cur].min |= mask; // leaf
        return;
      } else {
        T[cur].ones |= mask;
        T[cur].zeros &= (M ^ mask);
      }
      if (((T[cur].zeros | T[cur].ones)) == M) { // all bits known
        T[cur].min |= mask; // set bits on mask to 1;
        return;
      }
    }

    int mid = (b + e) >> 1;
    set_ones(cur << 1, b, mid, l, r, mask);
    set_ones(cur << 1 | 1, mid + 1, e, l, r, mask);

    update(cur, b, e);
  }

  long long query(int cur, int b, int e, int l, int r) {
    push_down(cur, b, e);

    if (b > r || e < l)  return inf;

    long long ans = inf;
    if (b >= l && e <= r) {
      debug("quer", b, e, T[cur].min);
      ans = T[cur].min;
    } else {
      int mid = (b + e) >> 1;
      ans = min(ans, query(cur << 1, b, mid, l, r));
      ans = min(ans, query(cur << 1 | 1, mid + 1, e, l, r));
    }
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
      tree.set_zero(1, 0, n - 1, l, r, M ^ x);
      debug("=================");
    }
    if (t == '|') {
      cin >> x;
      tree.set_ones(1, 0, n - 1, l, r, x);
    }
    if (t == '?') {
      cout << tree.query(1, 0, n - 1, l, r) << endl;
    }

  }

  return 0;
}

