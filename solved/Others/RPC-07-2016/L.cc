#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int tc; cin >> tc;
  for (int t = 0; t < tc; ++t) {
    cin >> line;
    vector<pair<int, int>> ans;
    for (int i = 1; i < line.size(); ++i) {
      int a = stoi(line.substr(0, i));
      int b = stoi(line.substr(i));
      if (__gcd(a, b) == 1) {
        ans.emplace_back(a, b);
      }
    }
    sort(ans.begin(), ans.end());
    cout << "Ticket #" << (t + 1) << ":" << endl;
    if (ans.size()) {
      cout << ans[0].first << " " << ans[0].second << endl;
    } else {
      cout << "Not relative" << endl;
    }
  }

  return 0;
}
