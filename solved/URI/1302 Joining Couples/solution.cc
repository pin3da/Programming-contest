using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>

#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXN 100010

const int LD = 20;
int n, nxt[MAXN], degree[MAXN];
vector<int> g[MAXN];

bool in_cycle[MAXN], visit[MAXN];
int current_ring, ring_size[MAXN], component_id[MAXN], current_tree, tree_id[MAXN];

int P[MAXN][LD], L[MAXN], T[MAXN];

void prepare(int node) {
  queue<int> Q;
  Q.push(node);

  while (!Q.empty()) {
    int act = Q.front(); Q.pop();
    int p = act == node ? -1: T[act];
    L[act] = p == -1 ? 0 : L[p] + 1; // root
    memset(P[act], -1, sizeof P[act]);
    P[act][0] = p;
    for (int i = 0; i + 1 < LD && P[act][i] != -1; ++i)
      P[act][i + 1] = P[P[act][i]][i];

    for (auto &it : g[act]) {
      int v = it;
      if (!in_cycle[v]) {
        component_id[v] = component_id[act];
        tree_id[v] = tree_id[act];
        T[v] = act;
        Q.push(v);
      }
    }
  }
}

int jump(int u, int d) {
  for (int i = 0; i < LD; ++ i) {
    if (d >> i & 1) {
      u = P[u][i];
    }
  }
  return u;
}

int lca(int u, int v) {
  if (L[u] > L[v]) {
    swap(u, v);
  }
  v = jump(v, L[v] - L[u]);
  if(u == v)
    return u;

  for (int i = LD - 1; i >= 0; --i) {
    if (P[u][i] != P[v][i]) {
      u = P[u][i];
      v = P[v][i];
    }
  }
  return P[u][0];
}

int solve(int a, int b) {
  if (component_id[a] != component_id[b]) {
    return -1;
  }
  if (tree_id[a] != tree_id[b]) {
    int r = ring_size[component_id[a]];
    int d = fabs(tree_id[a] - tree_id[b]);
    return L[a] + L[b] + min(d, r - d);
  }
  int c = lca(a, b);
  return L[a] + L[b] - 2 * L[c];
}

void toposort() {
  queue<int> Q;
  memset(in_cycle, true, sizeof in_cycle);
  for (int i = 0; i < n; ++i)
    if (!degree[i])
      Q.push(i);

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    in_cycle[u] = false;
    if (!--degree[nxt[u]])
      Q.push(nxt[u]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n) {
    for (int i = 0; i < n; ++ i)
      g[i].clear();

    memset(degree, 0, sizeof degree);
    for (int i = 0; i < n; ++ i) {
      cin >> nxt[i];
      g[--nxt[i]].push_back(i);
      degree[nxt[i]]++;
    }

    toposort();

    current_ring = current_tree = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; ++ i) {
      if (in_cycle[i]) {
        if (!visit[i]) {
          ring_size[current_ring] = 0;
          int j = i;
          do {
            visit[j] = true;
            component_id[j] = current_ring;
            ring_size[current_ring]++;
            tree_id[j] = current_tree++;
            j = nxt[j];
          } while (j != i);
          current_ring++;
        }
        prepare(i);
      }
    }

    int q; cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      cout << solve(a - 1, b - 1) << endl;
    }
  }
  return 0;
}
