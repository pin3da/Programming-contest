#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


long long go(int n, int s) {
  if (n == 0) return 1;
  long ans = 0;
  for (int l = 1; l <= min(n, s); l++) {
    ans += (go(n - l, s));
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, s;
  cin >> n >> s;
  long long ans = go(n - 1, s);
  cout << ans << endl;

  return 0;
}
