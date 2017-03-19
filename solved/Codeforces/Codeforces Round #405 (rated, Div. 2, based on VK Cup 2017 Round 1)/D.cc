#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

const int MN = 200001;
const int MK = 6;

int K;

map<pair<int, int>, int> dp1;
map<pair<int, int>, long long> dp2[MK];

vector<int> g[MN];

int go_size(int node, int pi) {
  int ans = 1;
  pair<int, int> id = make_pair(node, pi);
  if (dp1.count(id))
    return dp1[id];

  for (int to : g[node]) {
    if (to == pi) continue;
    ans += go_size(to, node);
  }
  return dp1[id] = ans;
}

long long go(int node, int pi, int x) {
  long long ans = 0;

  pair<int, int> id = make_pair(node, pi);
  if (dp2[x].count(id))
    return dp2[x][id];

  for (int to : g[node]) {
    if (to == pi) continue;
    if (x) ans += go(to, node, x - 1);
    else   ans += go(to, node, K - 1) + go_size(to, node);
  }
  return dp2[x][id] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n >> K;
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  /*
  for (int i = 0; i < n; ++i) {
    for (int x = 0; x < K; ++x) {
      long long tmp = go(g, i, i, x);
      cout << "node " << i + 1 << " mod " << x << " : " << tmp << endl;
    }
  }
  */

  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans += go(i, i, 0);
  cout << (ans >> 1) << endl;
  return 0;
}
