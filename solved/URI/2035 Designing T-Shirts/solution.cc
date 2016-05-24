using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 26; // size of alphabet
const int MS = 1000010; // Number of states.

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

  int add(const string &s, int val, bool query = 0){
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = s[i] - 'A';
      if(tree[cur_node].a[id] == -1){
        if(query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
      if(!query) tree[cur_node].c += val;
    }
    return tree[cur_node].c;
  }

  long long dfs(int node) {
    long long ans = abs(tree[node].c);
    for (int i = 0; i < 26; ++i) {
      if (tree[node].a[i] != -1) {
        ans += dfs(tree[node].a[i]);
      }
    }
    return ans;
  }
};

trie tree;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n && n != -1) {
    string line;
    tree.init();
    int total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> line;
      tree.add(line, 1);
      total += line.size();
    }
    for (int i = 0; i < n; ++i) {
      cin >> line;
      tree.add(line, -1);
      total += line.size();
    }

    total -= tree.dfs(0);
    cout << (total >> 1) << endl;
  }
  return 0;
}
