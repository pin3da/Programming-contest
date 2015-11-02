#include <bits/stdc++.h>
using namespace std;

const int MN = 20020;
vector<int> g[MN];
int sz;

int bfs(int s, vector<bool>& vis) {
  queue<pair<int,bool> > Q; // (node, turn)
  Q.push(make_pair(s, 0));
  vis[s] = true;
  int ans1 = 0, ans2 = 0;
  while (!Q.empty()) {
    int t = Q.front().first;
    bool turn = Q.front().second;
    Q.pop();

    if (turn)
      ans1++;
    else
      ans2++;
    int n = g[t].size();
    for (int i = 0; i < n; i++) {
      int to = g[t][i];
      if (!vis[to]) {
	vis[to] = true;
	Q.push(make_pair(to, !turn));
      }
    }
  }
  return max(ans1, ans2);
}

void get_g(int n) {
  map<int,int> name;
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v); u--; v--;
    if (!name.count(u))
      name[u] = name.size() - 1;
    if (!name.count(v))
      name[v] = name.size() - 1;
    g[name[u]].push_back(name[v]);
    g[name[v]].push_back(name[u]);
  }
  sz = name.size();
}

int solve(int n) {
  for (int i = 0; i < MN; i++)
    g[i].clear();
  get_g(n);
  vector<bool> vis(sz, false);
  
  int ans = 0;
  for (int i = 0; i < sz; i++)
    if (!vis[i])
      ans += bfs(i, vis);
  return ans;
}

int main() {
  int tc; scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", i + 1, solve(n));
  }
  return 0;
}
