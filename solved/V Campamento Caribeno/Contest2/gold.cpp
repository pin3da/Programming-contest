using namespace std;
#include<bits/stdc++.h>

const int MN = 40;
int n,m;
int gold[MN];
int dist[MN];
vector<int> g[MN];
const int inf = 987654321;

struct state{
  int node, cost, col;
  long long visited;
  state(){ visited = 0;}
  state(int x, int b, int c, long long v) : node(x), cost(b), col(c) , visited(v) {}

  bool operator < (const state &o) const {
    if ( cost == o.cost) return col < o.col;
    return cost > o.cost;
  }
};

struct st{
  int node,cost;
  st(){}
  st(int a,int b): node(a), cost(b) {}
  bool operator < (const st &o) const {
    return cost > o.cost;
  }
};


int d2[MN];

int fun(long long mask) {

  priority_queue<st> q;
  for (int i = 0 ; i < n; ++i) d2[i] = inf;

  q.push(st(1,0));
  int ans = inf;
  while (!q.empty()) {
    int node = q.top().node;
    int cost = q.top().cost; q.pop();

    if (node == 0)
      return cost;

    for (int i = 0; i < g[node].size(); ++i) {
      int v = g[node][i];
      int ncost = cost;
      if ((mask>>v) & 1) ncost += gold[v];
      if (ncost < d2[v]) {
        d2[v] = ncost;
        q.push(st(v, ncost));
      }
    }
  }
  return ans;

}

int main() {
  while (cin>>n>>m) {
    if (n == 0 and m == 0) break;
    for (int i = 0; i < MN; ++i) g[i].clear();
    for (int i = 0; i < n - 2; ++i) cin>>gold[i + 2];
    int u,v;
    for (int i = 0; i < m; ++i) {
      cin>>u>>v;v--;u--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < MN; ++i) dist[i] = inf;


    int ans = 0;
    int first_found = -1;
    priority_queue<state> q;
    q.push(state(0,0,0,1)); // node, dist, collected, visited.
    while (!q.empty()) {
      state cur = q.top();q.pop();
      if (cur.node == 1) {

        if (first_found == -1)
          first_found = cur.cost;
         else
          if (first_found < cur.cost)
            break;

        int other = fun(cur.visited);

        ans = max(ans, cur.col - other);

/*
        cout<<"Possible ruta!"<<endl;
        for (int i = 0; i < n; ++i) {
          if ((cur.visited>>i) & 1)
            cout<<i<<" ";
        }
        cout<<endl;*/
      }
      int u = cur.node;
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (cur.cost + 1 > dist[v]) continue;
        dist[v] = cur.cost + 1;
        int ncost = cur.cost + gold[u];
        long long nmask = cur.visited | (1LL<<v);
        q.push(state(v, dist[v], cur.col + gold[v],  nmask));
      }
    }
    cout<<ans<<endl;
    //cout<<"termina"<<endl;
  }

  return 0;
}
