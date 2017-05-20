#include<bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MD = 31;

struct node {
  node *child[2];
};

typedef node* pnode;

pnode copy_node(pnode cur) {
  pnode ans = new node();
  if (cur)
    *ans = *cur;
  return ans;
}

pnode add(pnode cur, int val, int id = MD) {
  pnode ans = copy_node(cur);
  if (id == -1) return ans;
  int t = (val >> id) & 1;
  ans-> child[t] = add(ans-> child[t], val, id - 1);
  return ans;
}

int query(pnode cur, int val, int is_max, int id = MD) {
  int target = (val >> id) & 1;
  target ^= is_max; // if is_max, target should be different from target.
  int ans = 0;
  if (cur-> child[target]) {
    if (id > 0) ans = query(cur-> child[target], val, is_max, id - 1);
    if (is_max) ans += (1 << id);
  } else {
    if (id > 0)  ans = query(cur-> child[target ^ 1], val, is_max, id - 1);
    if (!is_max) ans += (1 << id);
  }
  return ans;
}

void dfs(map<int, vector<int>> &g, map<int, int> &val, map<int, pnode> &ver,
         int node) {

  for (auto to: g[node]) {
    ver[to] = add(ver[node], val[to]);
    dfs(g, val, ver, to);
  }
}

int main() {

  int n, q;
  cin >> n >> q;
  map<int, int> val;
  map<int, vector<int>> g;
  map<int, pnode> version;

  int root, k;
  cin >> root >> k;
  root--;
  val[root] = k;

  for (int i = 0; i < n - 1; ++i) {
    int u, v, k;
    cin >> u >> v >> k;
    u--;v--;
    val[u] = k;
    g[v].push_back(u);
  }

  pnode root_tree = new node();
  version[root] = add(root_tree, k);
  dfs(g, val, version, root);

  int last = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    t ^= last;
    if (t == 0) {
      int u, v, k;
      cin >> v >> u >> k;
      u ^= last;
      v ^= last;
      k ^= last;
      u--;v--;
      version[u] = add(version[v], k);
    } else {
      int v, k;
      cin >> v >> k;
      v ^= last;
      k ^= last;

      v--;
      int min_ans = query(version[v], k, 0);
      int max_ans = query(version[v], k, 1);
      cout << min_ans << " " << max_ans << endl;
      last = min_ans ^ max_ans;
    }
  }
  return 0;
}
