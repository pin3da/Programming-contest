#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  map<string, int> id;
  for (int i = 0; i < n; i++) {
    string t; cin >> t;
    id[t] = i;
  }

  for (int i = 0; i < n; i++) {
    string node;
    int m;
    cin >> node >> m;

  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  solve();

  return 0;
}
