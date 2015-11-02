using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 10000 * 40 + 1;

struct trie {
  struct node {
    int c;
    int edges[26];
  };

  int nodes;
  node tree[MN];

  void init(int node = 0) {
    if (node == 0)
      nodes = 1;
    memset(tree[node].edges, -1, sizeof tree[node].edges);
    tree[node].c = 0;
  }

  void add(const string &s) {
    int node = 0;
    for (int i = 0; i < s.size(); ++i) {
      int cur = s[i] - 'a';
      if (tree[node].edges[cur] == -1) {
        tree[node].edges[cur] = nodes;
        init(nodes);
        nodes++;
      }
      node = tree[node].edges[cur];
    }
    tree[node].c++;
  }
};

trie preffix;
trie suffix;

void dfs_suffix(int node, int depth, vector<int> &frec) {
  for (int i = 0; i < 26; ++i) {
    if (suffix.tree[node].edges[i] == -1) continue;
    frec[i]++;
    dfs_suffix(suffix.tree[node].edges[i], depth + 1, frec);
  }
}

long long fun(int node, int c, int d, vector<int> &frec) {
  int ans = 0;
  if (preffix.tree[node].c || (d > 0 && suffix.tree[0].edges[c] != -1))
    ans++;

  for (int i = 0; i < 26; ++i)
    if (preffix.tree[node].edges[i] == -1)
      ans += frec[i];

  return ans;
}

long long dfs_preffix(int node, int depth, int cur, vector<int> &frec) {
  long long ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (preffix.tree[node].edges[i] == -1) continue;
    ans += fun(preffix.tree[node].edges[i], i, depth, frec);
    ans += dfs_preffix(preffix.tree[node].edges[i], depth + 1, cur, frec);
  }
  return ans;
}


void solve(int n) {
  preffix.init();
  suffix.init();
  string line;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    preffix.add(line);
    reverse(line.begin(), line.end());
    suffix.add(line);
  }
  vector<int> frec(26);
  dfs_suffix(0, 0, frec);
  cout << dfs_preffix(0, 0, 0, frec) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
