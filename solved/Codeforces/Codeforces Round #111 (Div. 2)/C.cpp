// http://codeforces.com/contest/160/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve(long long n, long long k) {
  map<long long, long long> a;
  vector<long long> b(n);
  long long t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    a[t]++;
    b[i] = t;
  }
  sort(b.begin(), b.end());
  for (auto &it : a) {
    long long cur = it.second * n;
    if (k < cur) {
      cout << it.first << " ";
      cout << b[k / it.second];
      cout << endl;
      return;
    } else {
      k -= cur;
    }
  }
}

int main() {
  long long n, k;
  while (cin >> n >> k) {
    solve(n, k - 1);
  }
  return 0;
}
