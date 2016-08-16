#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


map<int, string> inv;
int get_id(map<string, int> &m, string &s) {
  if (m.count(s)) return m[s];
  int ans = m.size();
  inv[ans] = s;
  return m[s] = ans;
}

int nxint () {
  string b; getline(cin, b);
  return atoi(b.c_str());
}

const int MN = 21;
int v[MN];

struct edge {
  int to, cost;
  edge() {}
  edge(int a, int b) : to(a), cost(b) {}
};

int target;

typedef vector<vector<edge> > graph;

struct dpt {
  int c, t;
  dpt() {}
  dpt(int a, int b) : c(a), t(b) {}
};

const int inf = 1000;
int nodes;

dpt ch_best(dpt best, dpt ans) {
  if (ans.c > best.c) {
    best = ans;
  } else if (ans.c == best.c) {
    if (ans.t < best.t)
      best = ans;
  }
  return best;
}


int seen[(1 << 16) + 1][22][25];
dpt dp[(1 << 16) + 1][22][25];

dpt go(graph &g, int mask, int ant, int t) {
  if (seen[mask][ant][t])
    return dp[mask][ant][t];

  seen[mask][ant][t] = true;
  dpt ans(ant != target, v[ant]);
  for (int i = 0; i < g[ant].size(); ++i) {
    int to = g[ant][i].to;
    if (to == target) continue;
    if ((mask >> to) & 1) continue;
    int road = g[ant][i].cost;
    int cost = v[ant];
    int nt = t + v[ant] + road;
    int t2 = t;
    int v2 = v[ant];
    if (nt >= 24) {
      while (nt >= 24) {
        cost += 24 - t2;
        v2 -= 24 - t2;
        t2 = 8;
        nt = t2 + v2 + road;
      }
    }
    dpt nxt = go(g, mask | (1 << to), to, nt);
    nxt.c += 1;
    nxt.t += cost;
    if (nxt.t < 121) {
      ans = ch_best(ans, nxt);
    }
  }
  return dp[mask][ant][t] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<string, int> id;
  int n = nxint();
  for (int i = 0; i < n; ++i) {
    string line; getline(cin, line);
    stringstream ss(line);
    string name, st;
    getline(ss, name, ',');
    getline(ss, st);
    get_id(id, name);
    v[i] = atoi(st.c_str());
  }
  int m = nxint();
  vector<vector<edge> > g(n + 1);
  for (int i = 0; i < m; ++i) {
    string line; getline(cin, line);
    stringstream ss(line);
    string us, vs, cs;
    getline(ss, us, ',');
    getline(ss, vs, ',');
    getline(ss, cs);
    int u = get_id(id, us);
    int v = get_id(id, vs);
    int c = atoi(cs.c_str());
    if (c > 16) continue;
    g[u].push_back(edge(v, c));
    g[v].push_back(edge(u, c));
  }

  string Bevagna = "Bevagna";
  target = get_id(id, Bevagna);
  v[target] = 0;
  nodes = id.size();
  dpt best(-1, inf);
  memset(seen, 0, sizeof seen);
  int idb = -1;
  for (int i = 0; i < g[nodes - 1].size(); ++i) {
    int to = g[nodes - 1][i].to;
    int cost = g[nodes - 1][i].cost + 8;
    if (cost < 25) {
      dpt ans = go(g, 1 << to, to, 8);
      ans.t += cost;
      if (ans.t < 121) {
        best = ch_best(best, ans);
        if (best.c == ans.c && best.t == ans.t) {
          idb = to;
        }
      }
    }
  }

  int mask = 1 << idb, ant = idb, t = 8;
   while (true) {
    cout << inv[ant] << endl;
    int has_next = false;
    for (int i = 0; i < g[ant].size(); ++i) {
      int to = g[ant][i].to;
      if (to == target) continue;
      if ((mask >> to) & 1) continue;
      int road = g[ant][i].cost;
      int cost = v[ant];
      int nt = t + v[ant] + road;
      int t2 = t;
      int v2 = v[ant];
      if (nt >= 24) {
        while (nt >= 24) {
          cost += 24 - t2;
          v2 -= 24 - t2;
          t2 = 8;
          nt = t2 + v2 + road;
        }
      }
      dpt nxt = go(g, mask | (1 << to), to, nt);
      nxt.c += 1;
      nxt.t += cost;
      if (nxt.c == dp[mask][ant][t].c && nxt.t == dp[mask][ant][t].t) {
        mask |= 1 << to;
        ant = to;
        t = nt;
        has_next = true;
        break;
      }
    }
    if (!has_next) break;
  }
  return 0;
}
