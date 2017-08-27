#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 2; // size of alphabet
const int MS = 400100; // Number of states.

int comp_st(int a, int b) {
  if (a && !b) return 1;
  if (!a && b) return 2;
  return 0;
}

struct trie{
  struct node{
    int c;
    int a[MN];
  };

  node tree[MS];
  int nodes;

  void clear(){
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  void init(){
    nodes = 0;
    clear();
  }

  int add(int s, int m){
    int cur_node = 0;
    for (int i = m; i >= 0; i--) {
      int id = (s >> i) & 1;
      if(tree[cur_node].a[id] == -1){
        tree[cur_node].a[id] = nodes;
        clear();
      }
      tree[cur_node].c++;
      cur_node = tree[cur_node].a[id];
    }
    tree[cur_node].c++;
    return tree[cur_node].c;
  }

  int query(int node, int t, int st, int dep) {
    if (dep == -1) {
      if (st == 3) return tree[node].c;
      return 0;
    }
    if (st == 3) return tree[node].c;
    int bt = (t >> dep) & 1;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
      if (tree[node].a[i] != -1) {
        int new_st = (st | (comp_st(i, bt)));
        ans += query(tree[node].a[i], t, new_st, dep - 1);
      }
    }
    return ans;
  }

};


trie tree;
int all[100012];

void solve() {
  tree.init();
  int n, m; cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < n; i++)
    cin >> all[i];

  m--;
  for (int i = 0; i < n; i++) {
    int t = all[i];
    ans += tree.query(0, t, 0, m);
    tree.add(t, m);
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
