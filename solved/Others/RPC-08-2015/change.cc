using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 10001 + 100;

struct edge{
  int to, weight;
  edge() {}
  edge(int t, int w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

vector<edge> g[MN];

int d[MN]; 
int p[MN]; 
int dijkstra(int s, int n){
  for (int i=0; i<n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }
  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()){
    int node = q.top().to;
    int dist = q.top().weight;
    q.pop();

    if (dist > d[node]) continue;
    
    for (int i=0; i<g[node].size(); ++i){
      int to = g[node][i].to;
      int w_extra = g[node][i].weight;

      if (dist + w_extra < d[to]){
        d[to] = dist + w_extra;
        p[to] = node;
        q.push(edge(to, d[to]));
      }
    }
  }
  return INT_MAX;
}

const int inf = 10002;

void solve(long long n, long long m, long long k) {
    vector<int> sp(k);
    map<pair<int, int>, int> cool; 
    for (int i = 0; i < k; ++i) {
      cin >> sp[i];
      sp[i]--;
      if (i)
        cool[(make_pair(sp[i - 1], sp[i]))] = inf;
    }
      
    for (int i = 0; i < n + 10; ++i) 
      g[i].clear();
      
    int u, v, c;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      u--;v--;
      if (cool.count(make_pair(u, v))) {
        cool[make_pair(u, v)] = min(cool[make_pair(u, v)], c);
      }
      if (cool.count(make_pair(v, u))) {
        cool[make_pair(v, u)] = min(cool[make_pair(v, u)], c);
      }
      g[u].push_back(edge(v, c));
      g[v].push_back(edge(u, c));
    }
    
    dijkstra(0, n);
    vector<long long> d1(n);
    for (int i = 0; i < n; ++i) {
      d1[i] = d[i];
    }
    
    long long cost = d[n - 1];
    
    dijkstra(n - 1, n);
    vector<long long> d2(n);
    for (int i = 0; i < n; ++i) {
      d2[i] = d[i];
    }
    
    map<pair<int, int>, int> frec;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        u = i; v = g[i][j].to; c = g[i][j].weight;
        if (cool.count(make_pair(u, v)) > 0 && cool[make_pair(u, v)] == c) {
          frec[make_pair(u, v)]++;
        }
      }
    }
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        u = i; v = g[i][j].to; c = g[i][j].weight;
        if (d1[u] + d2[v] + c == cost) {
          if (cool.count(make_pair(u, v)) == 0 || 
              frec[make_pair(u, v)] > 1) {
            //cout << "from " << u << " to " << v << endl;
            cout << "yes" << endl;
            return;
          }
        }
      }
    }
    cout << "no" << endl;
}

int main() {
  long long n, m, k;
  while (cin >> n >> m >> k) {
    solve(n, m, k);
  }  
  return 0;
}
