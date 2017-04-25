// http://codeforces.com/contest/478/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

typedef long long bart;

bart a[3];
bool check(bart t) {
  bart need  = 3 * t;
  bart total = a[0] + a[1] + a[2];
  if (need > total)
    return false;

  if (a[0] + a[1] >= t)
    return true;

  return false;
}

int main() {

  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);


  bart lo = 0, hi = a[0] + a[1] + a[2];
  hi /= 3;


  while (lo < hi) {
    if (lo + 1 == hi) {
      if (check(hi))
        lo = hi;
      break;
    }
    bart mid = (lo + hi) >> 1;
    if (check(mid)) lo = mid;
    else hi = mid - 1;
  }
  cout << lo << endl;

  return 0;
}