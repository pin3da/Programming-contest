// Chef and Game with Sequence
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> data(2);

    int ans = n;
    for (int i = 0; i < n; i++) {
      int t; cin >> t;
      data[t & 1]++;
    }

    while (data[1] > 1) {
      data[1] -= 2;
      data[0] += 1;
      ans--;
    }

    while (data[0] > 1) {
      data[0]--;
      ans--;
    }
    cout << ans << endl;
  }

  return 0;
}
