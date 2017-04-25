// http://codeforces.com/contest/198/problem/A

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long k, b, n, t;
  while (cin >> k >> b >> n >> t) {
    long long cur = 1;
    int ans = 0;
    while (cur <= t) {
      cur *= k;
      cur += b;
      ans++;
    }
    cout << max(n - (ans  - 1), 0LL) << endl;
  }
  return 0;
}
