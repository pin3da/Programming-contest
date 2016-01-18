#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  while (cin >> n) {
    set<int> seen;
    vector<vector<int> >  g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> g[i][j];

    int x, y;
    for (int i = 0; i < 2 * n; ++i) {
      cin >> x >> y;
      seen.insert(g[x - 1][y - 1]);
    }
    cout << seen.size() << endl;
  }
  return 0;
}
