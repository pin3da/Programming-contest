// http://codeforces.com/contest/448/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long go(vector<long long> &a, int i, int j, int h) {
  if (i == j) return a[i] > h;
  long long best = (j - i + 1);
  long long mmin = a[i];
  for (int k = i; k <= j; ++k) mmin = min(a[k], mmin);
  for (int k = i; k <= j; ++k)
    if (a[k] == mmin)
      return min(best, go(a, i, k - 1, mmin) + go(a, k + 1, j, mmin) + mmin - h);

  return best;
}

void solve(int n) {
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  cout << go(a, 0, n - 1, 0) << endl;
}

int main() {
  int n;
  while(cin >> n)
    solve(n);
  return 0;
}
