// http://codeforces.com/contest/478/problem/B

using namespace std;
#include <bits/stdc++.h>

long long f(long long x) {
  return (x * (x - 1)) >> 1;
}

int main() {

  int n, m;
  cin >> n >> m;

  long long mx = f(n - m + 1);
  long long a = n % m;
  long long b = m - a;
  long long mn = a * f((n / m) + 1) + b * f(n / m);
  cout << mn << " " << mx << endl;

  return 0;
}