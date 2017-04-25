// http://codeforces.com/contest/348/problem/A

using namespace std;
#include <bits/stdc++.h>

bool sim(vector<long long> &c, long long n) {
  long long s = 0;
  for (auto &i : c) {
    if (i > n) return false;
    s += n - i;
  }
  return s >= n;
}

int main() {
  long long n;
  while (cin >> n) {
    vector<long long> c(n);
    for (auto &i : c) cin >> i;
    long long lo = 0, hi = 100000000000LL;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      if (sim(c, mid))
        hi = mid;
      else
        lo = mid + 1;
    }
    cout << lo << endl;
    /*
    for (int i = 0; i < 1000; ++i) {
      if (sim(c, i)) {
        cout << i << endl;
        break;
      }
    }*/
  }
  return 0;
}
