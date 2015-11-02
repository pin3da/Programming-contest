using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 50000 * 50 + 1;

int get_ind(const char &c) {
  if (c == 'A') return 0;
  if (c == 'C') return 1;
  if (c == 'G') return 2;
  return 3;
}

struct trie {
  struct node {
    int c;
    int edges[4];
  };

  node tree[MN];
  int nodes;

  void init(int node = 0) {
    if (node == 0)
      nodes = 1;
    memset(tree[node].edges, -1, sizeof tree[node].edges);
    tree[node].c = 0;
  }

  void add(const string &s) {
    int node = 0;
    for (int i = 0; i < s.size(); ++i) {
      int cur = get_ind(s[i]);
      if (tree[node].edges[cur] == -1) {
        tree[node].edges[cur] = nodes;
        init(nodes);
        nodes++;
      }
      node = tree[node].edges[cur];
      tree[node].c++;
    }
  }
};

trie tree;

void dfs(int node, long long depth, long long &best) {
  best = max(depth * tree.tree[node].c, best);
  for (int i = 0; i < 4; ++i) if (tree.tree[node].edges[i] != -1) {
    dfs(tree.tree[node].edges[i], depth + 1, best);
  }
}

void solve() {
  int n;
  tree.init();
  cin >> n;
  string line;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    tree.add(line);
  }

  long long ans = 0;
  dfs(0, 0, ans);
  printf("%lld\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
