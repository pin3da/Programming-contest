#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> m;
    vector<int> tot(n);
    int t;
    while (m--) {
      for (int i = 0; i < n; ++i) {
        cin >> t;
        tot[i] += t;
      }
    }
    cout << (max_element(tot.begin(), tot.end()) - tot.begin()) + 1 << endl;
  }

  return 0;
}
