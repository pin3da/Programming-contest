// http://codeforces.com/contest/519/problem/E

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x)  cout << #x " = " << (x) << endl
#define endl '\n'


void process3(vector<int> &T, vector<vector<int> > &P) {
  int N = T.size();
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; 1 << j < N; j++)
      P[i][j] = -1;
  for (i = 0; i < N; i++)
    P[i][0] = T[i];
  for (j = 1; 1 << j < N; j++)
    for (i = 0; i < N; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}

int query(vector<vector<int> > &P, vector<int> &T, vector<int> &L, int p, int q) {
  int N = T.size();
  int tmp, log, i;
  if (L[p] < L[q])
    tmp = p, p = q, q = tmp;
  for (log = 1; 1 << log <= L[p]; log++);
  log--;
  for (i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];
  if (p == q)
    return p;
  for (i = log; i >= 0; i--)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  return T[p];
}


int dist(vector<vector<int> > &P, vector<int> &T, vector<int> &L, int a, int b, int &lca) {
  lca = query(P, T, L, a, b);
  return L[a] + L[b] - 2 * L[lca];
}

int dfs(vector<vector<int> > &G, vector<int> &memo, int node) {
  int ans = 0;
  for (int i = 0; i < G[node].size(); ++i) {
    ans += dfs(G, memo, G[node][i]);
  }
  return memo[node] = ans + 1;
}

int main() { ___

  int n;
  while (cin >> n) {
    vector<vector<int> > g(n);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }


    int root = 0;
    vector<int> L(n, 0);
    vector<vector<int> > G(n);
    queue<int> q;
    q.push(root);
    vector<bool> visited(n, false);
    vector<int> T(n);
    while (!q.empty()) {
      int cur =  q.front();
      q.pop();
      if (visited[cur]) continue;
      visited[cur] = true;
      for (int i = 0; i < g[cur].size(); ++i) {
        if (!visited[g[cur][i]]) {
          q.push(g[cur][i]);
          G[cur].push_back(g[cur][i]);
          T[g[cur][i]] = cur;
          L[g[cur][i]] = L[cur] + 1;
        }
      }
    }

    vector<vector<int> > P(n, vector<int>(22));
    process3(T, P);
    vector<int> children(n, 0);
    dfs(G, children, root);

    int queries;
    cin >> queries;
    int a, b;
    while (queries--) {
      cin >> a >> b;
      a--;b--;
      int lca;
      int cur_dist = dist(P, T, L, a, b, lca);
      if (cur_dist & 1) {
        cout << 0 << endl;
      } else if (a == b) {
        cout << n << endl;
      } else {

        if (L[a] < L[b])
          swap(a, b);

        int target = (cur_dist >> 1);
        int p = a;
        for (int i = 0; i < 22; ++i) {
          if ((target >> i) & 1) {
            p = P[p][i];
          }
        }
        if (p == lca) {
          target--;
          int bad_a = a;
          for (int i = 0; i < 22; ++i) {
            if ((target >> i) & 1) {
              bad_a = P[bad_a][i];
            }
          }
          int bad_b = b;
          for (int i = 0; i < 22; ++i) {
            if ((target >> i) & 1) {
              bad_b = P[bad_b][i];
            }
          }

          cout << n - children[bad_a] - children[bad_b] << endl;


        } else {
          int bad = a;
          target--;
          for (int i = 0; i < 22; ++i) {
            if ((target >> i) & 1) {
              bad = P[bad][i];
            }
          }
          cout << children[p] - children[bad] << endl;
        }
      }
    }
  }
  return 0;
}
