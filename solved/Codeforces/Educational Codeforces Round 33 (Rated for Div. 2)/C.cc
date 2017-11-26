#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1e5 + 100;
int p[MN];
int val[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  int px = fs(x);
  int py = fs(y);
  if (px == py) return;
  val[py] = min(val[py], val[px]);
  p[px] = py;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> val[i];
    p[i] = i;
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    js(u, v);
  }

  set<int> roots;
  for (int i = 0; i < n; i++) {
    roots.insert(fs(i));
  }

  long long ans = 0;
  for (auto i: roots) {
    ans += val[i];
  }
  cout << ans << endl;

  return 0;
}
