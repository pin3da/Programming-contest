#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const long long inf =  100000LL * 100000LL;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    long long ans = inf;
    for (long long i = 2; i * i <= c; ++i) {
      if (c % i) continue;
      if ((i % a) == 0 && (i % b != 0) && (d % i != 0)) {
        ans = min(ans, i);
      }
      long long j = c / i;
      if ((j % a) == 0 && (j % b != 0) && (d % j != 0)) {
        ans = min(ans, j);
      }
    }

    if (ans < inf) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
