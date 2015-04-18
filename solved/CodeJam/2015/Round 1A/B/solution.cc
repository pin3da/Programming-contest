using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

bool f(vector<long long> &m, long long n, long long time) {
  long long total = 0;
  for (int i = 0; i < m.size(); ++i) {
    total += time / m[i];
  }
  if (total < n)
    return false;
  return true;
}
long long get_time(vector<long long> &m, long long n, long long mmax) {
  long long lo = 0, hi = mmax;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (f(m, n, mid)) {
      hi = mid;
    } else
      lo = mid + 1;
  }
  return lo;
}

void solve() {
  int b;
  long long n;
  cin >> b >> n;
  vector<long long> m(b);
  long long mmax = 0;
  for (int i = 0; i < b; ++i) {
    cin >> m[i];
    mmax = max(mmax, m[i] * n);
  }
  mmax += 10;
  long long a1 = get_time(m, n - b, mmax);
  long long a2 = get_time(m, n, mmax);
  long long already = 0;
  for (int i = 0; i < m.size(); ++i) {
    already += ceil(a1 / (double) m[i]);
  }
  int j = 0;
  while (already < n && j < m.size()) {
    if ((a1 % m[j]) == 0)
      already++;
    j++;
  }
  cout << j << endl;
}
int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
