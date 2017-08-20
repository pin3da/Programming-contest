#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> frec(10);
  int j = 0;
  for (int i = 1; i <= 7; i++) {
    while (j < n && a[j] == i) {
      frec[i]++;
      j++;
    }
  }
  int ok = true;
  for (int i = 1; i <= 7; i++)
    ok &= (frec[i] != 0);

  for (int i = 6; i >= 1; i--) {
    while (j < n && frec[i]) {
      ok &= (a[j] == i);
      j++;
      frec[i]--;
    }
    ok &= (frec[i] == 0);
  }
  ok &= (j == n);
  puts(ok ? "yes" : "no");
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
