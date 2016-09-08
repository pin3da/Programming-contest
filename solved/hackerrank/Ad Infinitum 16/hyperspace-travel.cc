#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int> > a(m, vector<int> (n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> a[j][i];

    int id = ((n + 1) >> 1) - 1;
    for (int i = 0; i < m; ++i) {
      sort(a[i].begin(), a[i].end());
      if (i) cout << ' ';
      cout << a[i][id];
    }
    cout << endl;
  }
  return 0;
}
