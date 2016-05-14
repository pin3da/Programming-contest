#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int c; cin >> c;
  int first = true;
  while (c--) {
    int mod, n, t;
    cin >> mod >> n;
    vector<vector<int>> ht(mod);
    while (n--) {
      cin >> t;
      ht[t % mod].emplace_back(t);
    }

    if (!first) cout << endl;
    first = 0;
    for (int i = 0; i < mod; ++i) {
      cout << i;
      for (int j = 0; j < ht[i].size(); ++j) {
        cout << " ->";
        cout << ' ' << ht[i][j];
      }
      cout << " -> \\" << endl;
    }
  }

  return 0;
}
