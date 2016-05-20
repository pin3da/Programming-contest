#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    unordered_map<int, int> seen;
    int t;
    int ans = 0;
    while (m--) {
      cin >> t;
      if (seen[t] == 1) ans++;
      seen[t]++;
    }
    cout << ans << endl;
  }
  return 0;
}
