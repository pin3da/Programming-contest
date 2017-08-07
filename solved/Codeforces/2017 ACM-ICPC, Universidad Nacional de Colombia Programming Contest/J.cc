#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int mod = 3 * 10000000;

int frec[mod];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m, q;
  cin >> n >> m >> q;
  vector<int> ans(n);
  for (int i = 0; i < m; i++)
    cin >> ans[i];

  for (int i = m; i < n; i++)
    ans[i] = (ans[i - m] + ans[i - m + 1]) % mod;

  for (int i = 0; i < n; i++)
    frec[ans[i]]++;


  int j = 0;
  for (int i = 0; i < mod; i++) {
    while (frec[i]--)
      ans[j++] = i;
  }

  while (q--) {
    int t; cin >> t;
    cout << ans[t - 1] << endl;
  }

  return 0;
}
