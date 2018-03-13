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

const int MD = 31;

struct node_bin {
  node_bin *child[2];
  int val;

  node_bin() : val(0) {
    child[0] = child[1] = NULL;
  }
};

typedef node_bin* pnode;

pnode copy_node(pnode cur) {
  pnode ans = new node_bin();
  if (cur) *ans = *cur;
  return ans;
}

pnode modify(pnode cur, int key, int inc, int id = MD) {
  pnode ans = copy_node(cur);
  ans->val += inc;
  if (id >= 0) {
    int to = (key >> id) & 1;
    ans->child[to] = modify(ans->child[to], key, inc, id - 1);
  }
  return ans;
}

int sum_smaller(pnode cur, int key, int id = MD) {
  if (cur == NULL) return 0;
  if (id < 0) return 0;  // strictly smaller
  // if (id == - 1) return cur->val;  // smaller or equal

  int ans = 0;
  int to = (key >> id) & 1;
  if (to) {
    if (cur->child[0]) ans += cur->child[0]->val;
    ans += sum_smaller(cur->child[1], key, id - 1);
  } else {
    ans = sum_smaller(cur->child[0], key, id - 1);
  }
  return ans;
}

const int MN = 1e5 + 10;

struct seg_tree {
  pnode t[MN * 2];
  int n;
  seg_tree() : n(MN) {}

  void update(int p, int val, int delta) {
    p += n;
    while (p > 0) {
      t[p] = modify(t[p], val, delta);
      p >>= 1;
    }
  }

  int query(int l, int r, int val) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += sum_smaller(t[l++], val);
      if (r&1) res += sum_smaller(t[--r], val);
    }
    return res;
  }
};

seg_tree tree;

int get_kth_interval(int l, int r, int k) { // [l, r)
  int len = r - l;
  k = len - k;
  long long lo = 0, hi = 1e9 + 1;

  if (tree.query(l, r, hi) < k)
    return 0;

  while (lo < hi) {
    auto mid = (lo + hi + 1) >> 1;
    if (tree.query(l, r, mid) < k) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

void dbg(deque<long long> &cur) {
  for (auto it : cur)
    cerr << it << " ";
  cerr << endl;
}

void solve() {
  int n, q; read(n, q);

  vector<int> a(n);
  read(a);
  for (int i = 0; i < n; i++)
    tree.update(i, a[i], +1);

  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int pos, val;
      read(pos, val);
      pos--;
      tree.update(pos, a[pos], -1);
      a[pos] = val;
      tree.update(pos, a[pos], +1);
    } else {
      int l, r;
      read(l, r);

      l--; // interval [l, r)... no need of r--;

      int len = r - l;
      long long best = 0;


      if (len > 2) {
        deque<long long> cur;
        cur.push_back(get_kth_interval(l, r, 0));
        cur.push_back(get_kth_interval(l, r, 1));
        cur.push_back(get_kth_interval(l, r, 2));


        int nxt = 3;
        len -= 3;
        while (len && cur[0] >= (cur[1] + cur[2])) {
          cur.pop_front();
          cur.push_back(get_kth_interval(l, r, nxt++));
          len--;
        }

        if (cur[0] < (cur[1] + cur[2]))
          best = cur[0] + cur[1] + cur[2];
      }

      cout << best << endl;
    }
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

