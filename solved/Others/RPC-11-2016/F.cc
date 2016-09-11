#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

struct node {
  int a, b;
  node () {
    a = -1;
    b = -1;
  }
};
typedef vector<node> graph;

int getroot(graph &g) {
  vector<int> in(g.size());
  for (int i = 0; i < g.size(); ++i) {
    if (g[i].a != -1)
      in[g[i].a]++;
    if (g[i].b != -1)
      in[g[i].b]++;
  }

  for (int i = 0; i < g.size(); ++i)
    if (in[i] == 0) return i;

  assert(false);
}


int maxL = 0, maxR = 0;

int firstL(graph &g, int root) {
  int cur = 1;
  while (g[root].b >= 0) {
    cur++;
    root = g[root].b;
  }
  return cur;
}

int firstR(graph &g, int root) {
  int cur = 1;
  while (g[root].a >= 0) {
    cur++;
    root = g[root].a;
  }
  return cur;
}

void genleft(graph &g, int root) {
  int cur = 1;
  while (g[root].b >= 0) {
    if (g[root].a >= 0) genleft(g, g[root].a);
    cur++;
    root = g[root].b;
  }
  maxL = max(maxL, cur);
  if (g[root].a >= 0) genleft(g, g[root].a);
}


void genright(graph &g, int root) {
  int cur = 1;
  while (g[root].a >= 0) {
    if (g[root].b >= 0) genright(g, g[root].b);
    cur++;
    root = g[root].a;
  }
  maxR = max(maxR, cur);
  if (g[root].b >= 0) genright(g, g[root].b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    graph left(n);
    for (int i = 0; i < n; ++i) {
      int id, l, m;
      cin >> id >> l >> m;
      id--; l--; m--;
      if (l >= 0) left[id].a = (l);
      if (m >= 0) left[id].b = (m);
    }
    int m; cin >> m;
    graph right(m);
    for (int i = 0; i < m; ++i) {
      int id, q, r;
      cin >> id >> q >> r;
      id--; q--; r--;
      if (q >= 0) right[id].a = (q);
      if (r >= 0) right[id].b = (r);
    }

    maxL = maxR = 0;
    int rootL =  getroot(left);
    int rootR =  getroot(right);
    genleft(left, rootL);
    genright(right, rootR);

    int A = firstL(left, rootL);
    int B = firstR(right, rootR);

    int best = max(min(A, maxR), min(B, maxL));

    cout << n + m - best << endl;
  }
  return 0;
}
