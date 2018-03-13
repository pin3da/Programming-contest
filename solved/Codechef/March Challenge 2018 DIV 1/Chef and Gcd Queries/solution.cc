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


const int MP = 100000 + 1;

struct data {

  pnode t[MP];

  void update(int p, int value, int delta) {
    t[value] = modify(t[value], p, delta);
  }

  int query(int l, int r, int val) { // interval [l, r)
    return sum_smaller(t[val], r) - sum_smaller(t[val], l);
  }

};

data tree;



vector<int> get_primes[MP];

void fill() {
  for (int i = 2; i < MP; i++) {
    if (int(get_primes[i].size()) == 0) {
      for (int j = i; j < MP; j += i) {
        get_primes[j].push_back(i);
      }
    }
  }
}


void modify(int i, int t, int delta) {
  vector<int> &pr = get_primes[t];
  int top = 1 << pr.size();
  for (int mask = 1; mask < top; mask++) {
    int cur = 1;
    for (int j = 0; j < int(pr.size()); j++) {
      if ((mask >> j) & 1) {
        cur *= pr[j];
      }
    }
    tree.update(i, cur, delta);
  }
}

int query(int i, int j, int t) {
  vector<int> &pr = get_primes[t];
  int top = 1 << pr.size();
  int total = j - i + 1;
  for (int mask = 1; mask < top; mask++) {
    int cur = 1;
    for (int j = 0; j < int(pr.size()); j++) {
      if ((mask >> j) & 1) {
        cur *= pr[j];
      }
    }
    int side = __builtin_popcount(mask) & 1 ? -1 : 1;
    total += side * tree.query(i, j + 1, cur);
  }
  return total;
}


void solve() {
  fill();

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    a[i] = t;
    modify(i, t, +1);
  }

  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int x, y; cin >> x >> y;
      modify(x - 1, a[x - 1], -1);
      modify(x - 1, y, 1);
      a[x - 1] = y;
    } else {
      int l, r, g;
      read(l, r, g);
      l--; r--;
      cout << query(l, r, g) << endl;
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}

