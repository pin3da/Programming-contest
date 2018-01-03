#include<bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MN = 1e5 + 100;
const int tree_size = (MN << 2) + 4;

struct node_t {

  int best;
  pair<int, int> left, right;

  node_t() : best(0) {}

  void clear() {
    left = right = make_pair(0, 0);
    best = 0;
  }

  void init(int x) {
    right = left = make_pair(x, 1);
    best = 1;
  }

  node_t merge(node_t& rhs) { // merge with a node to the right
    node_t ans;
    ans.left = left;
    ans.right = rhs.right;
    ans.best = max(best, rhs.best);

    if (right.first == rhs.left.first) {  // merge center
      ans.best = max(ans.best, right.second + rhs.left.second);
    }

    if (ans.left.first == rhs.left.first) {
      ans.left.second += rhs.left.second;
    }

    if (ans.right.first == right.first) {
      ans.right.second += right.second;
    }

    return ans;
  }
};


struct seg_tree {
  node_t t[tree_size];
  int n;

  void init(vector<int> &data) {
    for (int i = 0; i < tree_size; i++) {
      t[i].clear();
    }

    n = data.size();
    build(1, 0, n - 1, data);
  }

  void build(int node, int b, int e, vector<int> &data) {
    if (b == e) {
      t[node].init(data[b]);
      return;
    }

    int mid = (b + e) >> 1;
    build(node << 1, b, mid, data);
    build(node << 1 | 1, mid + 1, e, data);

    t[node] = t[node << 1].merge(t[node << 1 | 1]);
  }

  node_t query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) {
      return node_t();
    }

    if (b >= i && e <= j) {
      return t[node];
    }

    int mid = (b + e) >> 1;
    node_t rhs = query(node << 1 | 1, mid + 1, e, i, j);
    return query(node << 1, b, mid, i, j).merge(rhs);
  }

  node_t query(int i, int j) {
    return query(1, 0, n - 1, i, j);
  }

};

seg_tree tree;

void solve() {
  int n, c, q;
  scanf("%d%d%d", &n, &c, &q);

  vector<int> data(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &data[i]);

  tree.init(data);

  while (q--) {
    int i, j;
    scanf("%d%d", &i, &j);
    i--; j--;
    printf("%d\n", tree.query(i, j).best);
  }
}

int main() {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
      printf("Case %d:\n", i);
      solve();
    }
    return 0;
}

