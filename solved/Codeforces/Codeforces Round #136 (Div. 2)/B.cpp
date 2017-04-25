// http://codeforces.com/contest/221/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

bool check(long long a, long long b) {
  vector<bool> seen(10);
  while (a > 0) {
    seen[a % 10] = true;
    a /= 10;
  }
  while (b > 0) {
    if (seen[b % 10]) return true;
    b /= 10;
  }
  return false;
}

void solve(long long n) {
  long long b = 1;
  int ans = 0;
  while (b * b <= n) {
    if ((n % b) == 0) {
      if (check(b, n)) ans++;
      if (n / b != b)
        if (check(n / b, n)) ans++;
    }
    b++;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  while (cin >> n) solve(n);
  return 0;
}
