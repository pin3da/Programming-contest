#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MS = 'z' - 'a' + 1;
const int MN = 1000 * 1000 + 1000;

struct trie {
  struct node {
    int c;
    int to[MS];
  };

  node tree[MN];
  int nodes;

  void clear(int node = 0) {
    if (node == 0) nodes = 1;
    memset(tree[node].to, -1, sizeof tree[node].to);
    tree[node].c = 0;
  }

  int insert(const string &s) {
    int state = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      if (tree[state].to[c] == -1) {
        clear(nodes);
        tree[state].to[c] = nodes;
        nodes++;
      }
      state = tree[state].to[c];
      if (tree[state].c) return false;
    }
    tree[state].c++;
    for (int i = 0; i < MS; ++i)
      if (tree[state].to[i] != -1) return false;
    return true;
  }
};

trie tree;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    tree.clear();
    int ok = true;
    for (int i = 0; i < n; ++i) {
      string line; cin >> line;
      if (ok)
        ok &= tree.insert(line);
    }
    if (!ok)
      cout << "Conjunto Ruim" << endl;
    else
      cout << "Conjunto Bom" << endl;
  }
  return 0;
}
