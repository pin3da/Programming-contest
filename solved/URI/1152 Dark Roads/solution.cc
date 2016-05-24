#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  int u, v;
  long long w;
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

const int MN = 200000;
int p[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  if (fs(x) == fs(y)) return false;
  p[fs(x)] = fs(y);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    vector<edge> e(m);
    for (auto &i : e) cin >> i.u >> i.v >> i.w;
    for (int i = 0; i < n; ++i) p[i] = i;
    sort(e.begin(), e.end());
    long long ans = 0;
    for (auto &i : e)
      if (!js(i.v, i.u)) ans += i.w;
    cout << ans << endl;
  }
  return 0;
}
