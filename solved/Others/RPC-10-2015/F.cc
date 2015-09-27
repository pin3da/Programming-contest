using namespace std;
#include <bits/stdc++.h>
#define D(x)  cout << #x " = " << (x) << endl

const int MN = 55;
const int MNODES = 50005;
long long D[MN][MN];
int T[MNODES];

const long long inf = 10000000000LL;
int E;


const long long base = MNODES;

long long dp[MNODES][MN];

int start;
long long go(vector<vector<int> > &g, int node, int col) {
  if (dp[node][col] != -1)
    return dp[node][col];

  long long ans = inf;
  if (T[node] == -1) {
    for (int c = 0; c < E; ++c) {
      long long cur = 0;
      for (int i = 0; i < g[node].size(); ++i) {
        cur += go(g, g[node][i], c);
      }
      long long extra = (node == start) ? 0 : D[col][c];
      ans = min(ans, cur + extra);
    }
  } else {
    long long cur = 0;
    for (int i = 0; i  < g[node].size(); ++i) {
      cur += go(g, g[node][i], T[node]);
    }
    long long extra = (node == start) ? 0 : D[col][T[node]];
    ans = min(ans, cur + extra);
  }

  return dp[node][col] = ans;
}

void magic(vector<vector<int> > &g, int node, int pi, vector<vector<int> > &g2) {
  for (int i = 0; i < g[node].size(); ++i) if (g[node][i] != pi) {
    g2[node].push_back(g[node][i]);
    magic(g, g[node][i], node, g2);
  }
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, e;
  cin >> n >> e;

  E = e;
  long long mincost = inf;
  for (int i = 0; i < e; ++i) {
    for (int j = 0; j < e; ++j) {
      cin >> D[i][j];
      mincost = min(mincost, D[i][j]);
    }
  }

  int t, p, seen = 0;
  start = 0;
  memset(T, -1, sizeof T);
  for (int i = 0; i < e; ++i) {
    cin >> t;
    for (int j = 0; j < t; ++j) {
      cin >> p;
      p--;
      T[p] = i;
      seen++;
      start = p;
    }
  }

  if (seen == 0) {
    cout << (n - 1) * mincost << endl;
    return 0;
  }
  vector<vector<int> > g(n);

  for (int i = 0; i < n - 1; ++ i)  {
    cin >> t >> p;
    t--; p --;
    g[p].push_back(t);
    g[t].push_back(p);
  }

  vector<vector<int> > g2(n);
  magic(g, start, -1, g2);

  memset(dp, -1, sizeof dp);
  long long ans = go(g2, start, T[start]);

  cout << ans << endl;
  return 0;
}
