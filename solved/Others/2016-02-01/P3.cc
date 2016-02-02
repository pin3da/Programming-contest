#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct node {
  int val, l, r;
  node () {
    val = l = r = -1;
  }
  node (int a) {
    val = a;
    l = r = -1;
  }
};

typedef  vector<node> graph;

void insert(graph &g, int node, int t) {
  if (t < g[node].val) {
    if (g[node].l == -1) {
      int id = g.size();
      g[node].l = id;
      g.emplace_back(t);
    } else {
      insert(g, g[node].l, t);
    }
  } else {
    if (g[node].r == -1) {
      int id = g.size();
      g[node].r = id;
      g.emplace_back(t);
    } else {
      insert(g, g[node].r, t);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  graph g;
  g.reserve(n);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (i == 0) {
      g.emplace_back(t);
    } else {
      insert(g, 0, t);
    }
  }
  queue<node> q;
  q.push(g[0]);
  vector<int> ans;
  ans.reserve(n);
  while (!q.empty()) {
    node cur = q.front();q.pop();
    ans.push_back(cur.val);
    if (cur.l != -1)
      q.push(g[cur.l]);
    if (cur.r != -1)
      q.push(g[cur.r]);
    //for (auto &e : g[cur]) {
    //  q.push(e.to);
    //}
  }

  for (int i = 0; i < ans.size(); ++i) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case " << (i + 1) << ":" << endl;
    solve();
    cout << endl;
  }
  return 0;
}
