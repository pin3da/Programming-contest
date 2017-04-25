// http://codeforces.com/contest/483/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


long long a, b, x, y;

bool fun(long long m) {
  long long s1 = m - (m / x);
  long long s2 = m - (m / y);
  long long s3 = m - ((m / x) + (m / y) - (m / (x * y)));

  s1 -= s3;
  s2 -= s3;

  if (s1 < a)
    s3 -= (a - s1);
  if (s3 < 0) return false;
  if (s2 < b)
    s3 -= (b - s2);
  if (s3 < 0) return false;
  return true;
}

int main() { ___
  cin >> a >> b >> x >> y;

  long long lo = 0;
  long long hi = 2LL * (a + b);
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (fun(mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  cout << lo << endl;


  return 0;
}