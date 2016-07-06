#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<int> ans(10);
    while (n--) {
      int t; cin >> t;
      for (int i = 2; i <= 5; ++i)
        if ((t % i) == 0)
          ans[i]++;
    }
    for (int i = 2; i < 6; ++i) {
      cout << ans[i] << " Multiplo(s) de " << i << endl;
    }
  }
  return 0;
}
