using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

long long f(long long n) {
  return (n * (n - 3)) >> 1;
}

void solve(long long n) {
  long long lo = 1, hi = 100000000LL;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (f(mid) >= n)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = 0;
  long long n;
  while (cin >> n && n) {
    cout << "Case " << (++tc) << ": ";
    solve(n);
  }
  return 0;
}
