#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  int from, to, w;
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

const int MN = 40000 << 1;

int p[MN];

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  if (fs(x) == fs(y))
    return 0;
  p[fs(x)] = fs(y);
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    vector<edge> g(m);
    for (auto &i : g) {
      cin >> i.from >> i.to >> i.w;
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < n + 1; ++i)
      p[i] = i;

    long long ans = 0;
    for (auto &i : g) {
      if (js(i.from, i.to))
        ans += i.w;
    }
    cout << ans << endl;
  }
  return 0;
}
