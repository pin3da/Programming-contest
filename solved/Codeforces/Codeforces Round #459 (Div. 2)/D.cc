#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

struct edge {
  int to;
  char c;
  edge(int a, char b) : to(a), c(b) {}
};

typedef vector<vector<edge>> graph;

const int MN = 101, MA = 30;
const char BA = 'a' - 1;
int dp[MN][MN][MA][3];


int go(graph &g, int a, int b, char la, int t) {
  if (dp[a][b][la - BA][t] != -1)
    return dp[a][b][la - BA][t];
  int win = false;
  if (t == 0) {
    for (auto e : g[a]) {
      if (e.c >= la)
        win |= !(go(g, e.to, b, e.c, 1));
    }
  } else {
    for (auto e : g[b]) {
      if (e.c >= la)
        win |= !(go(g, a, e.to, e.c, 0));
    }
  }
  return dp[a][b][la - BA][t] = win;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n, m;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    u--, v--;
    g[u].emplace_back(v, c);
  }

  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (go(g, i, j, BA, 0))
        cout << "A";
      else
        cout << "B";
    }
    cout << endl;
  }

  return 0;
}
