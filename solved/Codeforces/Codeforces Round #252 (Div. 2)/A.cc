#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, v;
  cin >> n >> v;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    int ok = false;
    while (t--) {
      int w; cin >> w;
      ok |= (v > w);
    }
    if (ok)
      ans.push_back(i + 1);
  }
  cout << ans.size() << endl;
  for (auto i : ans)
    cout << i << " ";
  cout << endl;

  return 0;
}
