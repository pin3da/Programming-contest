// http://codeforces.com/contest/625/problem/A

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    long long nt = n;
    if (n >= b) {
      long long d = b - c;
      if (a <= d) {
        cout << n / a << endl;
        continue;
      }
      long long ans = (n - c) / d;
      n = n - ans * d;
      ans += n / a;
      cout << max(ans, nt / a) << endl;
    } else {
      cout << n / a << endl;
    }
  }
  return 0;
}
