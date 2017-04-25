// http://codeforces.com/contest/675/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

long long n;

bool v(long long x) {
  return x > 0 && x <= n;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b, c, d;
  while (cin >> n >> a >> b >> c >> d) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      long long x5 = i;
      long long x1 = x5 - a - b + c + d;
      long long x4 = x1 + a - d;
      long long x2 = d + x5 - a;
      if (v(x1) && v(x2) && v(x4) && v(x5)) {
        ans++;
      }
    }
    cout << ans * n << endl;
  }
  return 0;
}
