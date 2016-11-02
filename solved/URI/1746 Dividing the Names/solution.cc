#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 200 * 18 + 100;
struct trie {
  int frec[MN];
  int right[MN];
  int down[MN];
  int tree[MN][30];
  int nodes;

  void clear() {
    memset(tree, -1, sizeof tree);
    memset(frec, 0, sizeof frec);
    nodes = 1;
  }

  void add(string &s) {
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int to = s[i] - 'A';
      if (tree[cur][to] == -1) {
        tree[cur][to] = nodes;
        nodes++;
      }
      cur = tree[cur][to];
      frec[cur]++;
    }
  }

  void fix() {
    for (int i = 0; i < nodes; ++i) {
      int last = -1;
      for (int j = 30 - 1; j >= 0; --j) {
        if (tree[i][j] != -1) {
          right[tree[i][j]] = last;
          last = tree[i][j];
        }
      }
      down[i] = last;
    }
  }
};


const int inf = 100000;
trie tree;

int dp[MN][MN];

int go(int node, int st, int d) {

  if (dp[node][st] != -1) return dp[node][st];
  int ans = inf;
  for (int s = 0; s <= min<int>(st, tree.frec[node]); ++s) {
    if (tree.right[node] == -1 && s != st) continue;

    int cur = 0;
    if (s == 1) cur += d;
    if ((tree.frec[node] - s) == 1) cur += d;
    if (tree.right[node] != -1) cur += go(tree.right[node], st - s, d);
    if (tree.down[node] != -1) {
      cur += go(tree.down[node], s, d + 1);
      if (s == 1) cur -= d + 1;
      if ((tree.frec[node] - s) == 1) cur -= d + 1;
    }
    ans = min(ans, cur);
  }
  return dp[node][st] = ans;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    vector<string> w(n + n);
    tree.clear();
    for (int i = 0; i < n + n; ++i) {
      cin >> w[i];
      tree.add(w[i]);
    }

    tree.fix();
    memset(dp, -1, sizeof dp);
    cout << n * go(tree.down[0], n, 1) << endl;

  }
  return 0;
}
