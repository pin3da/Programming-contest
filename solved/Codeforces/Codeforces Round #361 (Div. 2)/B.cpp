// http://codeforces.com/contest/689/problem/B

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

struct edge{
  int to, weight;
  edge() {}
  edge(int t, int w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

const int MAXNODES = 200002;

vector<edge> g[MAXNODES];
int d[MAXNODES];
int p[MAXNODES];

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
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < MAXNODES; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) {
      int t; cin >> t; t--;
      if (i) g[i].emplace_back(i - 1, 1);
      g[i].emplace_back(t, 1);
      if (i + 1 < n);
      g[i].emplace_back(i + 1, 1);
    }
    dijkstra(0, n);
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << d[i];
    }
    cout << endl;
  }
  return 0;
}
