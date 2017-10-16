#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n; cin >> n;
  long long last = 1;
  for (long long i = 1; i * i <= n; i++)
    last = i;

  long long ans = last << 2;
  n -= last * last;
  if (n) {
    ans += 2;
    if (n > last)
      ans += 2;
  }
  cout << ans << endl;
  return 0;
}
