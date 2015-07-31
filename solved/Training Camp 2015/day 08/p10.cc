#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int inf = 1000000000;
const int MN = 1000;

struct edge{
  int v;
  long long w;
  edge(){} edge(int v, int w) : v(v), w(w) {}
};

vector<edge> g[MN];

long long d[MN][MN];

int karp(int n){
  for(int i = 0;i<n;++i)
    if(!g[i].empty())
      g[n].push_back(edge(i,0));
  ++n;

  for(int i = 0;i<n;++i)
    fill(d[i],d[i]+(n+1),INT_MAX);

  d[n-1][0] = 0;

  for (int k = 1;k<=n;++k) for (int u = 0;u<n;++u){
    if(d[u][k-1]==INT_MAX) continue;

    for(int i = g[u].size()-1;i>=0;--i)
      d[g[u][i].v][k] = min(d[g[u][i].v][k],d[u][k-1]+g[u][i].w);
  }

  bool flag = true;

  for(int i = 0;i<n && flag;++i)
    if(d[i][n]!=INT_MAX)
      flag = false;

  if(flag){
    return true;
  }

  double ans = 1e15;

  for(int u = 0;u+1<n;++u){
    if(d[u][n]==INT_MAX) continue;
    double W = -1e15;

    for(int k = 0;k<n;++k)
      if(d[u][k]!=INT_MAX)
        W = max(W,(double)(d[u][n]-d[u][k])/(n-k));

    ans = min(ans,W);
  }

  // printf("%.2lf\n", -ans);

  ans = -ans;
  cout << fixed << setprecision(2) << ans << endl;

  return false;
}

void solve(map<string, int> &cod, int n) {
  string line;
  for (int i = 0; i < MN; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    cin >> line;
    if (line.size() < 2) continue;
    int u = cod[line.substr(0, 2)];
    int v = cod[line.substr(line.size() - 2, 2)];
    g[u].push_back(edge(v, -line.size()));
  }
  if (karp(cod.size())) {
    cout << "No solution." << endl;
  }
}

int main() {
  map<string, int> cod;
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string cur(2, '0');
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      cur[0] = char(i + 'a');
      cur[1] = char(j + 'a');
      cod[cur] = i * 26 + j;
    }
  }
  int n;
  while (cin >> n && n) {
    solve(cod, n);
  }
  return 0;
}
