#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, k;
  cin >> n >> k;

  long long ans = 0;
  for (int i = 60; i >= 0; i--) {
    long long cur = (1LL << i);
    if (cur <= n && k) {
      ans += n;
      k--;
      if (k > 0 && i > 0) {
        ans |= (1LL << i) - 1;
      }
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
