#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 111;
int p[MN];

int fs(int x) {
  return x == p[x] ? x : fs(p[x]);
}

void js(int x, int y) {
  p[fs(x)] = fs(y);
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < MN; ++i) p[i] = i;
  int u, v;
  while (m--) {
    cin >> u >> v;
    js(u - 1, v - 1);
  }

  set<int> a;
  for (int i = 0; i < n; ++i)
    a.insert(fs(i));

  if (a.size() == 1) {
    cout << "a promessa foi cumprida" << endl;
  } else {
    cout << "ainda falta(m) " << a.size() - 1 << " estrada(s)" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  int tc = 1;
  while (t--) {
    cout << "Caso #" << (tc++) << ": ";
    solve();
  }
  return 0;
}
