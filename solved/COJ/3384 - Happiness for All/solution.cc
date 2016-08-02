#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 1000 + 100;
int p[MN];
int s[MN];
int edges[MN];

void clear(int i) {
  p[i] = i;
  s[i] = 1;
  edges[i] = 0;
}

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

bool js(int x, int y) {
  if (fs(x) == fs(y)) {
    edges[fs(x)]++;
    return false;
  }

  s[fs(y)] += s[fs(x)];
  edges[fs(y)] += edges[fs(x)] + 1;
  p[fs(x)] = fs(y);
  return true;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, r, e;
  while (cin >> n >> m >> r >> e) {
    for (int i = 0; i < n; ++i) clear(i);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      js(u - 1, v - 1);
    }

    set<int> cols;
    for (int i = 0; i < n; ++i) cols.insert(fs(i));

    long long ans = 0;
    for (auto &i : cols)
      ans += min(s[i] * e, (((s[i] * (s[i] - 1)) / 2) - edges[i]) * r);

    cout << ans << endl;

  }
  return 0;
}
