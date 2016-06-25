#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = (50000 << 1) + 10;
int p[MN];
int c[MN];


int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

bool js(int x, int y) {
  if (fs(x) == fs(y)) {
    c[fs(x)]++;
    return false;
  }
  c[fs(y)] += c[fs(x)];
  p[fs(x)] = fs(y);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    for (int i = 0; i < MN; ++i)
      p[i] = i, c[i] = 0;

    for (int i = 0; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      js(u, v);
    }

    bool ok = true;
    for (int i = 0; i < MN && ok; ++i)
      ok &= c[fs(i)] < 2;

    if (ok)
      cout << "possible" << endl;
    else
      cout << "impossible" << endl;
  }

  return 0;
}
