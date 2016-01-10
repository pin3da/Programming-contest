#include <bits/stdc++.h>

using namespace std;

struct edge{
  int u, v, w;
  bool operator <(const edge &o) const {
    return w < o.w;
  }
};

const int MN = 1001 + 10;
int pi[MN];

int fs(int x) {
  return x == pi[x] ? x : pi[x] = fs(pi[x]);
}

void js(int y, int x) {
  pi[fs(x)] = fs(y);
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + 1; ++i) pi[i] = i;
  vector<edge> a(m);
  long long total = 0;
  for (auto &i : a) {
    cin >> i.u >> i.v >> i.w;
    total += i.w;
  }

  sort(a.begin(), a.end());
  int edges = 0;
  for (auto &i : a) {
    if (fs(i.u) != fs(i.v)) {
      edges++;
      js(i.u, i.v);
      total -= i.w;
    }
    if (edges == n - 1) break;
  }
  cout << total << endl;
}

int main() {
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
