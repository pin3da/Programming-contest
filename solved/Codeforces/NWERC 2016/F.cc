#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl


bool f(vector<long long> &a, vector<long long> &b, long long M) {
  vector<long long> x, y;
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] > M) x.push_back(a[i]);
  for (int i = 0; i < (int)b.size(); ++i)
    if (b[i] > M) y.push_back(b[i]);

  int ok = ((x.size() % 2) == 0) && ((y.size() % 2) == 0);
  if (!ok) return false;
  for (int i = 0; i < (int)x.size(); i += 2)
    ok &= x[i] == x[i + 1];
  for (int i = 0; i < (int)y.size(); i += 2)
    ok &= y[i] == y[i + 1];
  return ok;
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];

  long long lo = 0, hi = 1e9 + 1;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (f(a, b, mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
  return 0;
}
