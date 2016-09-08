#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

typedef vector<vector<int> > graph;

const int MN = 200022;
int p[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  if (fs(x) == fs(y)) return true;
  p[fs(x)] = fs(y);
  return false;
}

int dfs(graph &g, vector<int> &vi, int node) {
  if (vi[node]) return 0;
  vi[node] = true;
  int ans = 1;
  for (int i = 0; i < g[node].size(); ++i)
    ans += dfs(g, vi, g[node][i]);
  return ans;
}

const long long mod = 1000000LL * 1000LL + 7;

long long mod_pow(long long b, long long e, long long mod) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) p[i] = i;
    graph g(n);
    int t;
    vector<int> inc;
    for (int i = 0; i < n; ++i) {
      cin >> t; t--;
      g[i].push_back(t);
      if (js(i, t)) inc.push_back(i);
    }

    vector<int> vi(n);
    vector<int> len;
    for (int i = 0; i < inc.size(); ++i) {
      int cur = dfs(g, vi, inc[i]);
      len.push_back(cur);
    }

    int out = 0;
    for (int i = 0; i < n; ++i)
      if (!vi[i]) out++;

    long long ans = mod_pow(2, out, mod);
    for (int i = 0; i < len.size(); ++i) {
      long long t = (mod_pow(2, len[i], mod) - 2 + mod) % mod;
      ans = (ans * t) % mod;
    }
    cout << ans << endl;
  }

  return 0;
}
