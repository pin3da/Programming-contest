#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

typedef vector<vector<int>> graph;

const int MN = 10000 + 1000;
bool cant[MN];

vector<int> ori;
void dfs(graph &g, vector<int> &v, int node) {
  v[node] = 1;
  for (auto &to : g[node]) {
    if (v[to] == 0) dfs(g, v, to);
    else if (v[to] == 1) ori.push_back(node);
  }
  v[node] = 2;
}


void dfs2(graph &g, vector<int> &v, int node) {
  v[node] = 1;
  cant[node] = 1;
  for (auto &to : g[node]) {
    if (v[to] == 0) {
      dfs2(g, v, to);
    }
  }
}

const long long mod = 1000LL * 1000LL * 1000LL;

bool gigante = 0;
long long add(long long x, long long y) {
  x += y;
  if (x >= mod) {
    gigante = true;
    x -= mod;
  }
  return x;
}



int dp[MN];

long long go(graph &g, int node) {
  if (node == 1) return 1;

  if (dp[node] != -1) return dp[node];
  long long ans = 0;
  for (auto &i : g[node])
    ans = add(ans, go(g, i));
  return dp[node] = ans;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    graph g(n), gi(n), g3(n);
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      gi[v].push_back(u);
    }

    vector<int> vi(n);
    dfs(g, vi, 0);
    if (!vi[1]) {
      cout << 0 << endl;
    } else {



      fill(vi.begin(), vi.end(), 0);
      memset(cant, 0, sizeof cant);
      for (auto &i : ori) {
        // debug(i);
        dfs2(g, vi, i);
      }

      for (int i = 0; i < n; ++i) {
        if (cant[i]) continue;
        for (auto &to : g[i]) {
          if (!cant[to]) {
            g3[i].push_back(to);
            // cout << "from " << i << " to " << to << endl;
          }
        }
      }


      fill(vi.begin(), vi.end(), 0);
      dfs(g3, vi, 0);
      if (!vi[1]) {
        cout << "inf" << endl;
      } else {
        gigante = 0;
        memset(dp, -1, sizeof dp);
        long long ans = go(g3, 0);
        if (!gigante)
          cout << ans << endl;
        else
          cout << setfill('0') << setw(9) << ans << endl;
      }

    }
  }
  return 0;
}
