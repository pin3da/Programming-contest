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
    // g is undirected
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

  int get_child(int p, int q) { // p is ancestor of q
    if (p == q) return -1;

    int i, log;
    for (log = 1; 1 << log <= L[q]; log++) {}
    log--;

    for (i = log; i >= 0; i--)
      if (L[q] - (1 << i) > L[p]) {
        q = P[q][i];
      }

    assert(P[q][0] == p);
    return q;
  }

  int is_ancestor(int p, int q) {
    if (L[p] >= L[q])
      return false;

    int dist = L[q] - L[p];

    int cur = q;
    int step = 0;
    while (dist) {
      if (dist & 1)
        cur = P[cur][step];
      step++;
      dist >>= 1;
    }

    return cur == p;
  }
};

