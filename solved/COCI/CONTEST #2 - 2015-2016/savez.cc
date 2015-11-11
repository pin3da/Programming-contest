using namespace std;
#include <bits/stdc++.h>

const int MN = 2000002;



struct trie {
  struct node {
    int c;
    int e[26];
  };

  int nodes;
  node tree[MN];
  int dp[MN];
  int ans;

  void clear(int x = 0) {
    if (x == 0) {
      nodes = 1;
      ans = 1;
      memset(dp, 0, sizeof dp);
    }
    tree[x].c = 0;
    memset(tree[x].e, -1, sizeof tree[x].e);
  }

  void insert(int node, int depth, string &s, set<int> &b, int tmp) {

    if( depth == s.size() ){
      if (tree[node].c)
        tmp = max(tmp, dp[node] + 1);

      dp[node] = max(dp[node], tmp);

      ans = max(ans, dp[node]);
      tree[node].c = true;
      return;
    }

    if(tree[node].c && b.count(depth)){
      tmp = dp[node] + 1;

    }

    int to = s[depth] - 'A';

    if(tree[node].e[to] == -1){
      tree[node].e[to] = nodes;
      clear(nodes);
      nodes++;
    }

    insert(tree[node].e[to], depth + 1, s, b, tmp);

  }
};

trie tree;

set<int> compute_b(string &s) {
  int n = s.size();
  vector<int> z(n);
  z[0] = 0;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
      z[i] = 0;
      if (i <= r) z[i] = min(z[i - l], r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
      if (i + z[i] - 1 > r) {
          l = i;
          r = i + z[i] - 1;
      }
  }
  set<int> border;
  for (int i = 0; i < n; ++i)
    if (n - i == z[i])
      border.insert(z[i]);
  border.insert(n);
  return border;
}

int main() {
  int n;
  cin >> n;
  tree.clear();
  string line;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    set<int> b = compute_b(line);

    b.insert(line.size());
    tree.insert(0, 0, line, b, 1);
  }
  cout << tree.ans << endl;
  return 0;
}
