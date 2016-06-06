#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator !=(const PT &p)  const { return x != p.x || y != p.y ; }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS;
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}


typedef vector<vector<int>> graph;

bool dfs(graph &g, vector<int> &col, int node, int c) {
  if (col[node] != -1)
    return col[node] == c;

  col[node] = c;
  for (auto &to : g[node]) {
    if (!dfs(g, col, to, c ^ 1))
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<PT> wells(n);
    for (auto &i : wells) cin >> i.x >> i.y;
    vector<pair<PT, PT>> pipes(m);
    int t;
    for (auto &i : pipes) {
      cin >> t;
      t--;
      i.first = wells[t];
      cin >> i.second.x >> i.second.y;
    }

    graph g(m);
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        if (pipes[i].first != pipes[j].first) {
          if (SegmentsIntersect(pipes[i].first, pipes[i].second,
                                pipes[j].first, pipes[j].second)) {
            g[i].emplace_back(j);
            g[j].emplace_back(i);
          }
        }
      }
    }

    vector<int> col(m, -1);
    int ok = true;
    for (int i = 0; i < m; ++i) {
      if (col[i] == -1)
        ok = ok && dfs(g, col, i, 0);
    }
    if (ok)
      cout << "possible" << endl;
    else
      cout << "impossible" << endl;
  }
  return 0;
}
