// http://codeforces.com/contest/298/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve() {
  string line; cin >> line;
  int rb = line.size(), re = -1, lb = line.size(), le = -1;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == 'L') lb = min(lb, i), le = max(le, i);
    if (line[i] == 'R') rb = min(rb, i), re = max(re, i);
  }
  // cout << rb << " " << re << " " << lb << " " << le << endl;
  if (le == -1) {
    cout << rb + 1 << " " << re + 2 << endl;
    return;
  }

  if (re == -1) {
    cout << le + 1 << " " << lb << endl;
    return;
  }

  if (rb < lb) {
    cout << rb + 1 << " "  << lb << endl;
    return;
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve();
  return 0;
}
