#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  long long l, r; cin >> l >> r;
  long long best = 1, id = l;
  for (long long  i = 2; i * i <= r; ++i) {
    long long ans = (r / i) - ((l - 1) / i);
    if (ans > best) {
      best = ans;
      id = i;
    }
  }
  cout << id << endl;

  return 0;
}
