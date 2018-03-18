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

const int MN = 3 * 50000 + 20;
const int MD = 32;

set<int> pos[MN];
vector<int> data;
vector<int> all_values;

int get_index(int x) {
  return lower_bound(all_values.begin(), all_values.end(), x) - all_values.begin();
}

int N;

int get_next(int cur_pos) {
  auto it = pos[get_index(data[cur_pos])].upper_bound(cur_pos);
  if (it == pos[get_index(data[cur_pos])].end()) return N + 10;
  return *it;
}

int get_prev(int cur_pos) {
  auto it = pos[get_index(data[cur_pos])].lower_bound(cur_pos);
  if (it == pos[get_index(data[cur_pos])].begin()) return -1;
  it--;
  return *it;
}

typedef pair<int, int> my_key;


struct node_bin {
  node_bin *child[2];
  long long val;

  node_bin() : val(0) {
    child[0] = NULL;
    child[1] = NULL;
  }
};

typedef node_bin* pnode;

pnode copy_node(pnode cur) {
  if (cur) return cur;
  return new node_bin();
}


pnode modify(pnode cur, my_key _key, int inc, int id = MD) {
  long long key = _key.first; key = key * MN +  _key.second;
  pnode ans = copy_node(cur);
  ans->val += inc;
  if (id >= 0) {
    int to = (key >> id) & 1;
    ans->child[to] = modify(ans->child[to], _key, inc, id - 1);
  }
  return ans;
}

long long sum_smaller(pnode cur, my_key _key, int id = MD) {
  long long key = _key.first; key = key * MN +  _key.second;

  if (cur == NULL) return 0;
  if (id < 0) return 0;  // strictly smaller
  // if (id == - 1) return cur->val;  // smaller or equal

  long long ans = 0;
  int to = (key >> id) & 1;
  if (to) {
    if (cur->child[0]) ans += cur->child[0]->val;
    ans += sum_smaller(cur->child[1], _key, id - 1);
  } else {
    ans = sum_smaller(cur->child[0], _key, id - 1);
  }
  return ans;
}

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
      T[where] = modify(T[where], make_pair(what, pos_ori), data[pos_ori]);
      where >>= 1;
    }
  }

  void del(int where, int what) {
    int pos_ori = where;
    where += n;
    while (where > 0) {
      T[where] = modify(T[where], make_pair(what, pos_ori), -data[pos_ori]);
      where >>= 1;
    }
  }

  long long make_query(int cur_n, int r) {
    pnode cur = T[cur_n];
    my_key key(r, N + 100);
    long long ans = cur->val;
    return ans - sum_smaller(T[cur_n], key);
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

struct query {
  char t;
  int l, r;
};

void solve() {
  int n;
  cin >> n;
  N = n;

  tree.clean();
  data.resize(n); read(data);

  for (auto it : data)
    all_values.push_back(it - 1);

  int q; cin >> q;
  vector<query> queries(q);
  for (auto &q : queries) {
    cin >> q.t >> q.l >> q.r;
    if (q.t== 'U') all_values.push_back(q.r - 1);
  }

  sort(all_values.begin(), all_values.end());

  for (int i = 0; i < n; i++)
    pos[get_index(data[i])].insert(i);

  for (int i = 0; i < n; i++) {
    tree.add(i, get_next(i));
  }


  for (int i = 0; i < q; i++) {
    char t = queries[i].t;
    if (t == 'U') {
      int where = queries[i].l, what = queries[i].r;
      where--;

      int id_last = get_prev(where);
      int id_next = get_next(where);


      if (id_last >= 0) tree.del(id_last, where);
      tree.del(where, id_next);

      pos[get_index(data[where])].erase(where);
      data[where] = what;
      pos[get_index(data[where])].insert(where);

      if (id_last >= 0) tree.add(id_last, id_next);
      tree.add(where, get_next(where));

    } else {
      int l = queries[i].l, r = queries[i].r;
      l--; r--;
      cout << tree.query(l, r) << endl;
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

