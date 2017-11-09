#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 11234;

vector<int> divs[MN];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif


  for (int i = 1; i < MN; i++) {
    for (int j = 2; i * j < MN; j++) {
      divs[i * j].push_back(i);
    }
  }

  int tc; cin >> tc;
  while (tc--) {
    int a, b, x;
    cin >> a >> b >> x;
    vector<int> sieve(b + 1, 1);
    vector<int> ans;

    for (int i = b; i >= a; i--) {
      if (sieve[i]) {
        ans.push_back(i);
        for (auto d: divs[i])
          sieve[d] = false;
      }
    }
    if ((int)ans.size() < x) {
      cout << -1 << endl;
    } else {
      for (int i = 0; i < x; i++)
        cout << ans[i] << ' ';
      cout << endl;
    }
  }
  return 0;
}
