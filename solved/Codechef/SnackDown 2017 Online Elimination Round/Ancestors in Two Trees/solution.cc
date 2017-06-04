#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int N = 1000000 + 100;  // limit for array size

struct binary_index_tree {
  int n;
  int t[2 * N];

  void add(int where, long long what){
    for (where++; where <= n; where += where & -where){
      t[where] += what;
    }
  }

  void add(int from, int to, long long what) {
    add(from, what);
    add(to + 1, -what);
  }

  long long query(int where){
    long long sum = t[0];
    for (where++; where > 0; where -= where & -where){
      sum += t[where];
    }
    return sum;
  }
};

binary_index_tree tree;
int t_left[2 * N], t_right[2 * N];

void gen_times(vector<vector<int>> &g, int node, int pi, int &time_stamp) {
  t_left[node] = time_stamp++;
  for(auto to : g[node]) if (to != pi)
    gen_times(g, to, node, time_stamp);
  t_right[node] = time_stamp++;
}

void dfs(vector<vector<int>> &g, int node, int pi, vector<int> &ans) {
  ans[node] = tree.query(t_left[node]);
  tree.add(t_left[node], t_right[node], 1);
  for(auto to : g[node]) if (to != pi)
    dfs(g, to, node, ans);
  tree.add(t_left[node], t_right[node], -1);
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> g1(n), g2(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    u--;v--;
    g1[u].push_back(v);
    g1[v].push_back(u);
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    u--;v--;
    g2[u].push_back(v);
    g2[v].push_back(u);
  }
  int time_stamp = 0;
  gen_times(g1, 0, 0, time_stamp);
  vector<int> ans(n);
  dfs(g2, 0, 0, ans);
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  tree.n = 2 * 500000 + 10;
  for (int i = 0; i < tc; ++i)
    solve();
  return 0;
}
