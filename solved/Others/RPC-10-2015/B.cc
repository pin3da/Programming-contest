#include <bits/stdc++.h>
using namespace std;

long long l, k;

bool f(long long m) {
  long long used = 0, act = 0;
  for (long long i = 1; i <= 2 * l - 1; i += 2) {
    act += i;
    if (act >= m) {
      used++;
      act = 0;
    }
    if (used >= k)
      return true;
  }
  return used >= k;
}

int main() {
  cin >> l >> k;

  long long lo = 1, hi = l * l;

  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (f(mid))
      lo = mid;
    else
      hi = mid - 1;
  }

  cout << lo << endl;
  return 0;
}
