#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 3; // size of alphabet
const int MS = 3000100; // Number of states.

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

  int add(int s){
    int cur_node = 0;
    for (int i = 30; i >= 0; i--) {
      int id = (s >> i) & 1;
      if(tree[cur_node].a[id] == -1){
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    tree[cur_node].c++;
    return tree[cur_node].c;
  }

  long long query(int node, int t, int dep=30) {
    if (dep == -1) return tree[node].c;
    int bt = (t >> dep) & 1;
    long long ans = 0;
    if (bt && tree[node].a[1] != -1)
      ans += query(tree[node].a[1], t, dep - 1);
    if (tree[node].a[0] != -1)
      ans += query(tree[node].a[0], t, dep - 1);
    return ans;
  }

};


trie tree;

void solve() {
  tree.init();
  int n; cin >> n;
  long long ans = 0;
  vector<int> all(n);
  for (int i = 0; i < n; i++)
    cin >> all[i];
  sort(all.begin(), all.end());

  for (int i = 0; i < n; i++) {
    int t = all[i];
    ans += tree.query(0, t);
    tree.add(t);
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
