using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 10000 * 10 + 1;

struct trie{
  struct node{
    int c;
    int edges[11];
  };

  node tree[MN];
  int tot_nodes;

  void init(int node = 0) {
    if (node == 0)
      tot_nodes = 1;
    memset(tree[node].edges, -1, sizeof tree[node].edges);
    tree[node].c = 0;
  }

  int add(const string &s) {
    int node = 0;
    bool ok  = true;
    for (int i = 0; i < s.size(); ++i) {
      int cur = s[i] - '0';
      if (tree[node].edges[cur] == -1) {
        tree[node].edges[cur] = tot_nodes;
        init(tot_nodes);
        tot_nodes++;
      }
      node = tree[node].edges[cur];
      if (tree[node].c)  ok = false;
    }
    tree[node].c++;
    for (int i = 0; i < 10; ++i)
      ok = ok && (tree[node].edges[i] == -1);
    return ok;
  }
};

trie tree;

void solve() {
  int n;
  tree.init();

  cin >> n;
  string line;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    if (ok) ok = ok && tree.add(line);
  }
  printf("%s\n", (ok? "YES": "NO"));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
