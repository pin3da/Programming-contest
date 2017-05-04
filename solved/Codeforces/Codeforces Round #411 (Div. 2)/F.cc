#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 100000 + 100;
int p[MN];
void init(int n) {
  for (int i = 0; i < n; ++i)
    p[i] = i;
}

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  p[fs(x)] = fs(y);
}


map<pair<int, int>, int> dp;
int go(vector<vector<int>> &g, int node, int pi) {
  int ans = 0;
  auto state = make_pair(node, pi);
  if (dp.count(state)) return dp[state];
  for (int to : g[node]) {
    if (to == pi) continue;
    ans = max(ans, go(g, to, node) + 1);
  }
  return dp[state] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m, q;
  cin >> n >> m >> q;
  init(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; u--;v--;
    js(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<int>> cc(n);
  vector<int> best_cc(n);
  vector<vector<long long>> acc(n), ans_tree(n);
  for (int i = 0; i < n; ++i) {
    cc[fs(i)].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    for (auto node : cc[i]) {
      ans_tree[i].push_back(go(g, node, node));
      best_cc[i] = max(best_cc[i], go(g, node, node));
    }
    sort(ans_tree[i].begin(), ans_tree[i].end());
    acc[i] = ans_tree[i];
    for (int j = ans_tree[i].size() - 2; j >= 0; --j) {
      acc[i][j] += acc[i][j + 1];
    }
  }

  map<pair<int, int>, double> all;
  for (int i = 0; i < q; ++i) {
    int u, v; cin >> u >> v; u--;v--;
    int A = fs(u), B = fs(v);
    if (A == B) {
      printf("-1\n");
    } else {
      if (cc[A].size() > cc[B].size()) {
        swap(A, B);
        swap(u, v);
      }
      if (all.count(make_pair(A, B))) {
        printf("%.10lf\n", all[make_pair(A, B)]);
        continue;
      }
      double t1 = cc[fs(u)].size();
      double t2 = cc[fs(v)].size();
      double ans = 0;
      double den = t1 * t2;
      int best = max(best_cc[fs(u)], best_cc[fs(v)]);
      for (auto node: cc[fs(u)]) {
        int it = lower_bound(ans_tree[fs(v)].begin(), ans_tree[fs(v)].end(), best - go(g, node, node) - 1) - ans_tree[fs(v)].begin();
        ans += (best * it);
        if (it != (int)ans_tree[fs(v)].size())
          ans += acc[fs(v)][it];
        ans += (dp[make_pair(node, node)] + 1) * (ans_tree[fs(v)].size() - it);
      }
      ans /= den;
      all[make_pair(A, B)] = ans;
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
