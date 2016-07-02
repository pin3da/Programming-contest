#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long double mp(long double b, int e) {
  long double ans = 1;
  for (int i = 0; i < e; ++i)
    ans *= b;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  cout << fixed << setprecision(4);
  while (tc--) {
    int n, i;
    long double p;
    cin >> n >> p >> i;

    long double ans = 0;
    for (int j = 0; j < 1000; ++j)
      ans += pow(1.0 - p, n * j + i - 1) * p;
    cout << ans << endl;
    /*
    long double num = mp(1.0 - p, i - 1) * p;
    long double den = 1.0 - mp(1 - p, n);
    cout << num / den << endl;
    */
  }
  return 0;
}
