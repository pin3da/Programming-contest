using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

const int MN = 50005;

void solve() {
  int n, m, q;
  vector<long long> x(MN, 0), y(MN, 0);
  cin >> n >> m >> q;
  int u, v, w;
  long long total = 0;
  for (int i = 0; i < q; ++i) {
    cin >> u >> v >> w;
    x[u] += w;
    y[v] += w;
    total += w;
  }

  long long accum = 0;
  int i;
  for (i = 0; i < MN and 2 * accum < total; ++i) {
    accum += x[i];
  }
  cout << (i - 1) << " ";

  accum = 0;
  for (i = 0; i < MN and 2 * accum < total; ++i) {
    accum += y[i];
  }
  cout << (i - 1) << endl;

}

int main() { ___
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case " << i + 1 << ": ";
    solve();
  }

  return 0;
}
