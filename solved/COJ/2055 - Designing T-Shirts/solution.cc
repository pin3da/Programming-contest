#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 26; // size of alphabet
const int MS = 100010; // Number of states.

int gid(char a) {
    return a - 'A';
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

  int add(const string &s, bool query = 0){
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = gid(s[i]);
      if(tree[cur_node].a[id] == -1){
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
      if(!query) tree[cur_node].c++;
      else tree[cur_node].c--;
    }
    return tree[cur_node].c;
  }

  int dfs(int node) {
    int ans = fabs(tree[node].c);
    for (int i = 0; i < MN; ++i) {
        if (tree[node].a[i] != -1)
            ans += dfs(tree[node].a[i]);
    }
    return ans;
  }

};

trie tree;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while (cin >> n && n > 0) {
        vector<string> a(n), b(n);
        tree.init();
        int total = 0;
        for (auto &i : a) {
            cin >> i;
            total += i.size();
            tree.add(i, 0);
        }
        for (auto &i : b) {
            cin >> i;
            total += i.size();
            tree.add(i, 1);
        }

        cout << (total - tree.dfs(0)) / 2 << endl;
    }
    return 0;
}
