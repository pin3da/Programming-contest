#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  sort(a.rbegin(), a.rend());

  long long nodes = 1;
  long long ans = 1;

  for (int i = 0; i < n; i++) {
    nodes *= a[i];
    ans += nodes;
  }

  cout << ans << endl;

  return 0;
}
