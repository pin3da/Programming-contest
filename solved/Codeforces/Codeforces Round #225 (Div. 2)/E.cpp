// http://codeforces.com/contest/384/problem/E

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MN 200002

int n ,m, date1, date2;
long long tree[MN + 10][2];
int l[MN], r[MN], id[MN], val[MN], t[MN];
vector<int> g[MN];

void add(int where, int what, int t){
  for (where++; where <= n; where += where & -where) {
    tree[where][t] += what;
  }
}

long long query(int where, int t){
  long long sum = tree[0][t];
  for (where++; where > 0; where -= where & -where) {
    sum += tree[where][t];
  }
  return sum;
}

long long query(int from, int to, int t){
  return query(to, t) - query(from - 1, t);
}

void dfs(int node, int turn){
  t[node] = turn;
  int &date = (turn) ? date1 : date2;
  if (!g[node].size()) {
    id[node] = l[node] = r[node] = date;
    date++;
  } else {
    int left = n + 1, right = - 1;
    int leaf = true;
    for (int i = 0; i < g[node].size(); ++i ) {
      const int &tt = g[node][i];
      for (int j = 0; j < g[tt].size(); ++j) {
        leaf = false;
        dfs(g[tt][j], turn);
        left = min(left, l[g[tt][j]]);
        right = max(right, r[g[tt][j]]);
      }
    }
    if (leaf) {
      id[node] = l[node] = r[node] = date;
    }else{
      l[node] = left;
      r[node] = id[node] = date;
    }
    date++;
  }
}

int main(){ ___
  cin>>n>>m;
  for (int i = 0; i < n; ++i) cin>>val[i];

  int u,v;
  for (int i = 0; i < n - 1; ++i ){
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
  }

  date1 = date2 = 0;
  dfs(0, 0);
  for (int i = 0; i < g[0].size(); ++i) dfs(g[0][i], 1);

  int op, node, va;
  memset(tree, 0 , sizeof tree);

  for (int i = 0; i < m; ++i ) {
    cin>>op>>node;
    node--;
    if (1 == op) {
      cin>>va;
      add(l[node], va,  t[node]);
      add(r[node] + 1, -va, t[node]);
      for (int j = 0; j < g[node].size(); ++j) {
        const int &tt = g[node][j];
        add(l[tt], -va, t[tt]);
        add(r[tt] + 1, va, t[tt]);
      }
    }else{
      cout<<(query(id[node], t[node]) + val[node])<<endl;
    }
  }
  return 0;
}