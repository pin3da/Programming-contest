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

map<int, set<short>> pos;
vector<int> data;

int N;

int get_next(int cur_pos) {
  auto it = pos[data[cur_pos]].upper_bound(cur_pos);
  if (it == pos[data[cur_pos]].end()) return N + 10;
  return *it;
}

int get_prev(int cur_pos) {
  auto it = pos[data[cur_pos]].lower_bound(cur_pos);
  if (it == pos[data[cur_pos]].begin()) return -1;
  it--;
  return *it;
}

int my_rand() {
  return rand();
}

typedef pair<short, short> my_key;
struct node {
  my_key x;
  long long sum;
  int val, y; // x = key, y = depth in tree
  node *left, *right;
  node(my_key key, int val) :
    x(key),
    sum(val), val(val), y(my_rand()),
    left(NULL), right(NULL)
  {}
};

typedef node* pnode;

pnode relax(pnode cur) {
  if (cur) {
    cur->sum = cur->val;
    if (cur->left) cur->sum += cur->left->sum;
    if (cur->right) cur->sum += cur->right->sum;
  }
  return cur;
}

// splits all elements <= x in l and all elements > x in r.
void split(pnode cur, my_key x, pnode &left, pnode &right) {
  if (!cur)
    left = cur = NULL;
  else {
    if (cur->x <= x) {
      split(cur->right, x, cur->right, right);
      left = relax(cur);
    } else {
      split(cur->left, x, left, cur->left);
      right = relax(cur);
    }
  }
}

pnode merge(pnode left, pnode right) {
  if (!left) return relax(right);
  if (!right) return relax(left);
  if (left->y > right->y) { // left deeper than right
    left->right = merge(left->right, right);
    return relax(left);
  } else {
    right->left = merge(left, right->left);
    return relax(right);
  }
}

pnode insert(pnode t, pnode m) {
  if (!t || m->y > t->y) {
    split(t, m->x, m->left, m->right);
    return relax(m);
  }
  if (m->x < t->x) t->left = insert(t->left, m);
  else t->right = insert(t->right, m);
  return relax(t);
}

pnode erase(pnode t, my_key x) {
  if (!t) return NULL;
  if (t->x == x) {
    pnode q = merge(t->left, t->right);
    delete t;
    return relax(q);
  } else {
    if (x < t->x) t->left = erase(t->left, x);
    else t->right = erase(t->right, x);
    return relax(t);
  }
}

const int MN = 50000 + 10;

struct seg_tree {
  pnode T[2 * MN];

  pnode left, right;
  int n;

  void clean() {
    n = MN;
    for (int i = 0; i < 2 * n; i++)
      delete T[i];
  }

  void add(int where, int what) {
    int pos_ori = where;
    where += n;
    while (where > 0) {
      // pnode c = new node(make_pair(what, pos_ori), data[pos_ori]); // the sum
      pnode c = new node(make_pair(what, pos_ori), 1); // count the number of different
      T[where] = insert(T[where], c);
      where >>= 1;
    }
  }

  void del(int where, int what) {
    my_key key(what, where);
    where += n;
    while (where > 0) {
      T[where] = erase(T[where], key);
      where >>= 1;
    }
  }

  long long make_query(int cur_n, int r) {
    pnode cur = T[cur_n];
    left = NULL, right = NULL;
    split(cur, make_pair(r, N + 100), left, right);
    long long ans = 0;
    if (right)  ans = right->sum;
    T[cur_n] = merge(left, right);
    return ans;
  }

  long long query(int l, int r) {  // sum on interval [l, r]
    long long res = 0;
    int R = r;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += make_query(l++, R);
      if (r&1) res += make_query(--r, R);
    }
    return res;
  }
};

seg_tree tree;

void solve() {
  int n;
  cin >> n;
  N = n;

  tree.clean();
  data.resize(n); read(data);

  for (int i = 0; i < n; i++)
    pos[data[i]].insert(i);

  for (int i = 0; i < n; i++) {
    tree.add(i, get_next(i));
  }

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    l--; r--;
    cout << tree.query(l, r) << endl;
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


