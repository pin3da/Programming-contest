// http://codeforces.com/contest/436/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 1010;


int p[MN];

int find_set(int x) {
  if (p[x] == x) return x;
  return p[x] = find_set(p[x]);
}

int join(int x, int y) {
  p[find_set(y)] = find_set(x);
}

struct edge{
  int a, b, w;
  edge(){}
  edge(int x, int y, int z) : a(x), b(y) , w(z) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

vector<edge> edges;
int cost[MN][MN];
int degree[MN];
int parent[MN];
int visited[MN];
vector<int> g[MN];



int main() { ___

  int n, m, k , w;
  cin>>n>>m>>k>>w;

  memset(parent, -1, sizeof parent);

  char arr[k][n][m];
  for (int i = 0; i < k; ++i) p[i] = i;

  for (int a = 0 ; a < k; ++a) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin>>arr[a][i][j];
      }
    }

    for (int b = 0; b < a; ++b) {
      int diff = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (arr[a][i][j] != arr[b][i][j])
            diff++;
        }
      }
      edges.push_back(edge(a,b, min(diff * w, n*m)));
      cost[b][a] = cost[a][b] = min(diff * w, n*m);
      //cout<<"Cost from "<<a<<" to "<<b<<" = "<<cost[a][b]<<endl;
    }
  }

  sort(edges.begin(), edges.end());
  int ans = n*m;

  for (int i = 0; i < edges.size() ; ++i) {
    int a = edges[i].a;
    int b = edges[i].b;
    if (find_set(a) == find_set(b)) continue;
    join(a,b);
    ans += cost[a][b];
    if (cost[a][b] <  n*m) {
      //cout<<"Join "<<a<<" "<<b<<endl;
      g[a].push_back(b);
      g[b].push_back(a);
      parent[b] = a;
      degree[b]++;
    }
  }
  cout<<ans<<endl;

  /*queue<int> q;
  for (int i = 0; i < k; ++i)
    if (degree[i] == 0) q.push(i);

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    cout<<(cur + 1)<<" "<<(parent[cur] + 1)<<endl;
    for (int i = 0; i < g[cur].size(); ++i) {
      degree[g[cur][i]]--;
      if (degree[g[cur][i]] == 0) q.push(g[cur][i]);
    }
  }*/
  for (int i = 0; i < k; ++i) {
    if (!visited[i]) {
      queue<pair<int, int> > q;
      q.push(make_pair(i, -1));
      while(!q.empty()) {
        int cur = q.front().first;
        int pa  = q.front().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        cout<<(cur + 1)<<" "<<(pa + 1)<<endl;
        for (int j = 0 ; j < g[cur].size(); ++j ) {
          q.push(make_pair(g[cur][j], cur));
        }
      }
    }
  }

  return 0;
}

