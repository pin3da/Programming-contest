#include <bits/stdc++.h>

using namespace std;

const int inf = 2000000;

int num_equal(const vector<int> &a, int target) {
  int total = 0;
  for (auto i : a)
    if (i == target) total++;
  return total;
}

set<int> divisors(int n) {
  set<int> divs;
  for (int d = 1; d * d <= n; d++) {
    if ((n % d) == 0) {
      divs.insert(d);
      divs.insert(n / d);
    }
  }
  return divs;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  int best = -1;
  for (auto start : a) {
    int same = num_equal(a, start);
    if (same >= (n / 2)) {
      cout << -1 << endl;
      return;
    }
    map<int, int> freq_divs;
    for (auto i : a) {
      if (i < start) continue;
      set<int> divs = divisors((i - start));
      for (auto d : divs) freq_divs[d]++;
    }

    for (auto [d, f] : freq_divs) {
      if (f >= (n / 2) - same) {
        best = max(best, d);
      }
    }
  }
  cout << best << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}