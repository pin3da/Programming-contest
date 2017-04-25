// http://codeforces.com/contest/483/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

int main() { ___
  long long r, l;
  cin >> r >> l;

  for (long long a = r; a < l - 1; ++a)
    for (long long b = a + 1; b < l; ++b)
      for (long long c = b + 1; c  <= l; ++c)
        if (__gcd(a, b) == 1 and __gcd(b, c) == 1 and __gcd(a, c) != 1) {
          cout << a << " " << b << " " << c << endl;
          return 0;
        }

  cout << -1 << endl;


  return 0;
}