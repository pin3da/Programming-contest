#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

struct point {
  int x, y;
  point(int a, int b) : x(a), y(b) {}
};

struct edge {
  int u, v, w;
  edge(int a, int b, int c) : u(a), v(b), w(c) {}

  bool operator < (const edge &o) const {
    return w > o.w;
  }
};


int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

const int inf = 100000;

const int MN = 1004004 + 100;
const int ML = 20; // ceil(log2(MN));

int p[MN];

int find_set(int x) {
  return p[x] == x ? x : p[x] = find_set(p[x]);
}

void join_set(int x, int y) {
  p[find_set(x)] = find_set(y);
}

struct lowest_ca {
  int T[MN], L[MN], W[MN];
  int P[MN][ML], MI[MN][ML], MA[MN][ML];

  void dfs(vector<vector<edge> > &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = W[root] = 0;
      T[root] = -1;
    }
    for (int i = 0; i < (int)g[root].size(); ++i) {
      int to = g[root][i].v;
      if (to != pi) {
        T[to] = root;
        W[to] = g[root][i].w;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(vector<vector<edge> > &g, int root) {
    dfs(g, root);
    int N = g.size(), i, j;

    for (i = 0; i < N; i++) {
      for (j = 0; 1 << j < N; j++) {
        P[i][j] = -1;
        MI[i][j] = inf;
      }
    }

    for (i = 0; i < N; i++) {
      P[i][0] = T[i];
      MI[i][0] = W[i];
    }

    for (j = 1; 1 << j < N; j++)
      for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1) {
          P[i][j] = P[P[i][j - 1]][j - 1];
          MI[i][j] = min(MI[i][j-1], MI[ P[i][j - 1] ][j - 1]);
        }
  }

  int query(int p, int q) {
    int tmp, log, i;

    int mmin = inf;
    if (L[p] < L[q])
      tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
      if (L[p] - (1 << i) >= L[q]) {
        mmin = min(mmin, MI[p][i]);
        p = P[p][i];
      }

    if (p == q)
      // return p;
      return mmin;

    for (i = log; i >= 0; i--)
      if (P[p][i] != -1 && P[p][i] != P[q][i]) {
        mmin = min(mmin, min(MI[p][i], MI[q][i]));
        p = P[p][i], q = P[q][i];
      }

    // return T[p];
    return min(mmin, min(MI[p][0], MI[q][0]));
  }
};

lowest_ca lca;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  vector<vector<int>> g(n + 2, vector<int> (n + 2, inf));
  vector<vector<int>> id(n + 2, vector<int> (n + 2));
  deque<point> q;
  int N = n + 2;
  for (int i = 0; i < N; i++) {
    q.emplace_back(0, i);
    q.emplace_back(i, 0);
    q.emplace_back(N - 1, i);
    q.emplace_back(i, N - 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char t; cin >> t;
      if (t == '#') q.emplace_back(i + 1, j + 1);
    }
  }

  for (auto i : q) {
    g[i.x][i.y] = 0;
  }

  while (!q.empty()) {
    point cur = q.front(); q.pop_front();
    for (int i = 0; i < 8; i++) {
      int x = cur.x + dx[i];
      int y = cur.y + dy[i];
      if (x >= 0 && x < N && y >= 0 && y < N) {
        if (g[x][y] == inf) {
          g[x][y] = g[cur.x][cur.y] + 1;
          if (g[cur.x][cur.y] > 0) g[x][y]++;
          q.emplace_back(x, y);
        }
      }
    }
  }

  int _id = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      id[i][j] = _id++;

  for (int i = 0; i < N * N; i++)
    p[i] = i;

  vector<edge> all;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < N && y >= 0 && y < N) {
          all.emplace_back(id[i][j], id[x][y], min(g[i][j], g[x][y]));
        }
      }
    }
  }

  sort(all.begin(), all.end());

  vector<vector<edge>> tree(N * N + 10);

  int root = 0;
  for (auto e : all) {
    if (find_set(e.u) != find_set(e.v)) {
      join_set(e.u, e.v);
      tree[e.u].emplace_back(e.u, e.v, e.w);
      tree[e.v].emplace_back(e.v, e.u, e.w);
      // cout << "from " << e.u << " to " << e.v << " w " << e.w << endl;
      root = e.u;
    }
  }

  lca.init(tree, root);

  int queries; cin >> queries;
  while (queries--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << lca.query(id[a][b], id[c][d]) << endl;
  }

  return 0;
}
