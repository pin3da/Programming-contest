#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 30;
int p[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  if (fs(x) > fs(y))
    p[fs(x)] = fs(y);
  else
    p[fs(y)] = fs(x);
}

void solve() {
  int n, m; cin >> n >> m;
  char a, b;
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    js(a - 'a', b - 'a');
  }
  map<int, vector<int>> cc;
  for (int i = 0; i < n; ++i)
    cc[fs(i)].emplace_back(i);

  for (auto &i : cc) {
    for (auto &j : i.second)
      cout << char(j + 'a') << ',';
    cout << endl;
  }
  cout << cc.size() << " connected components" << endl;
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << (i + 1) << ":" << endl;
    solve();
  }
  return 0;
}
