// TLE ):
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
const int MN = 4e4 + 100;  // limit for array size

struct seg_tree {
  int n;  // array size
  int t[2 * MN];

  seg_tree() : n(MN) {}

  void clear() {
    memset(t, 0, sizeof t);
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  // Single modification, range query.
  void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
  }

  int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, t[l++]);
      if (r&1) res = max(res, t[--r]);
    }
    return res;
  }
};

const int S = 222;
seg_tree T[S];

struct node {
  node *l, *r;
  int ans;
  node() {
    l = r = NULL;
    ans = 0;
  }
};

typedef node* pnode;

void pull(pnode cur) {
  int ans = -1;
  if (cur->l) ans = max(cur->l->ans, ans);
  if (cur->r) ans = max(cur->r->ans, ans);
  cur->ans = ans;
}

void update(pnode &root, int b, int e, int pos, int val) {
  if (!root) root = new node();
  if (b == e) {
    if (val) root->ans = pos;
    else root->ans = -1;
    return;
  }

  int mid = (b + e) >> 1;
  if (pos <= mid) update(root->l, b, mid, pos, val);
  else update(root->r, mid + 1, e, pos, val);
  pull(root);
}

int query(pnode root, int b, int e, int l, int r) {
  if (!root || b > r || e < l) return -1;
  if (b >= l && e <= r)
    return root->ans;
  int mid = (b + e) >> 1;
  return max(query(root->l, b, mid, l, r), query(root->r, mid + 1, e, l, r));
}

struct query_t {
  int a, b, id, mod;
  query_t() {}
  query_t(int x, int y, int i, int m) : a(x), b(y), id(i), mod(m) {}
  bool operator < (const query_t &o) const {
    return b < o.b;
  }
};


vector<query_t> s[S];
int ans[MN];
struct DS {
  pnode root;
  void clear() {
    root = NULL;
  }
  void insert(int x) {
    update(root, 0, MN, x, 1);
  }
  void erase(int x) {
    update(root, 0, MN, x, 0);
  }

  long long solve(int mod) {
    int l = 0, ans = 0;
    while (l < MN) {
      int r = min(MN - 1, l + mod - 1);
      int cur = query(root, 0, MN, l, r) - l;
      ans = max(ans, cur);
      l += mod;
    }
    return ans;
  }
};

DS mo_data;

void solve_mo(vector<int> &a) {
  for (int b = 0; b < S; ++b) {
    if (s[b].size() == 0) continue;
    int i = s[b][0].a;
    int j = s[b][0].a - 1;
    mo_data.clear();
    for (int k = 0; k < (int)s[b].size(); ++k) {
      int L = s[b][k].a;
      int R = s[b][k].b;
      while (j < R) { j++; mo_data.insert(a[j]); }
      while (j > R) { mo_data.erase(a[j]); j--;  }
      while (i < L) { mo_data.erase(a[i]); i++;  }
      while (i > L) { i--; mo_data.insert(a[i]); }
      ans[s[b][k].id] = mo_data.solve(s[b][k].mod);
    }
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  pnode root = NULL;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 2; j < S; j++) {
      T[j].modify(i, a[i] % j);
    }
    update(root, 0, MN, a[i], 1);
  }

  for (int i = 0; i < q; i++) {
    int l, r, mod;
    cin >> l >> r >> mod;
    l--;

    if (mod < S) {
      if (mod == 1)
        ans[i] = 0;
      else
        ans[i] = T[mod].query(l, r);
    } else {
      r--;

      s[l / S].emplace_back(l, r, i, mod);
    }
  }

  for (int i = 0; i < S; ++i) {
    if (s[i].size()) sort(s[i].begin(), s[i].end());
  }
  solve_mo(a);

  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

