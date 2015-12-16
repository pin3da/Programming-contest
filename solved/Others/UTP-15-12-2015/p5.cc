using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 20;

void solve(int a) {
  vector<vector<int> > g(MN);
  int t;
  for (int i = 0; i < MN - 1; ++i) {
    if (i)  cin >> a;
    for (int j = 0; j < a; ++j) {
      cin >> t;
      t--;
      g[i].push_back(t);
      g[t].push_back(i);
    }
  }
  int k, u, v; cin >> k;
  while (k--) {
    cin >> u >> v;
    u--; v--;
    vector<int> dist(MN, 200);
    vector<int> q(MN * MN);
    int head = 0, tail = 0;
    q[head++] = u;
    dist[u] = 0;
    while (head > tail) {
      int cur = q[tail++];
      if (cur == v) {
        printf("%2d to %2d: %d\n", u + 1, v + 1, dist[v]);
        break;
      }
      for (int i = 0; i < g[cur].size(); ++i) {
        int to = g[cur][i]
          , w  = dist[cur] + 1;
        if (w < dist[to]) {
          q[head++] = to;
          dist[to] = w;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, p = 1;
  while (cin >> a) {
    printf("Test Set #%d\n", p++);
    solve(a);
    puts("");
  }
  return 0;
}
