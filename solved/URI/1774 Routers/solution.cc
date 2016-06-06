#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  int from, to, w;
  edge() {}
  edge(int a, int b, int c) : from(a), to(b), w(c) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

const int MN = 1234;

int p[MN];

int fs(int x) { return p[x] == x ? x : p[x] = fs(p[x]); }
bool js(int x, int y) { if (fs(x) == fs(y)) return false; p[fs(x)] = fs(y); return true;}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) p[i] = i;
    vector<edge> e(m);
    for (auto &i: e) {
      cin >> i.from >> i.to >> i.w;
      i.from--; i.to--;
    }
    sort(e.begin(), e.end());
    long long ans = 0;
    for (auto &i: e)
      if (js(i.to, i.from)) ans += i.w;
    cout << ans << endl;
  }

  return 0;
}
