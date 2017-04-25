// http://codeforces.com/contest/267/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(long long a, long long b) {
  long long ans = 0;
  while (a > 0 && b > 0) {
    if (a < b) swap(a, b);
    ans += a / b;
    a = a % b;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  long long n, m; while (t-- > 0 && cin >> n >> m) solve(n, m);
  return 0;
}
