using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

long long f(long long x) {
  long long ans = 0;
  if (x <= 100)
    return 2 * x;
  if (x <= 10000)
    return 2 * 100 + 3 * (x  - 100);
  if (x <= 1000000)
    return 2 * 100 + 3 * 9900 + 5 * (x - 10000);
  return 2 * 100 + 3 * 9900 + 5 * (1000000 - 10000) + 7 * (x - 1000000);
}

int inv(int a) {
  int lo = 0, hi = a;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (f(mid) >= a)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

int a, b;
bool k(int c, int x) {
  return f(c - x) - f(x) >= b;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  while (cin >> a >> b && (a | b)) {
    int c = inv(a);
    int lo = 1, hi = c - 1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (k(c, mid))
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << f(lo) << endl;
  }
  return 0;
}

