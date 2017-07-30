#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long MN = 100000;
const long long MT = 1000000000;

void solve(map<int, vector<int>> &p, map<int, int> &inv) {
  int a, b;
  cin >> a >> b;
  debug(a);
  debug(b);
  if (inv.count(a) == 0  || inv.count(b) == 0) {
    puts("NO");
    return;
  }
  debug(inv[a]);
  debug(inv[b]);
  if (inv[a] != inv[b]) {
    puts("NO");
    return;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  map<int, vector<int>> powers;
  map<int, int> inv;
  for (int i = 2; i < MN; ++i) {
    if (inv.count(i)) continue;
    long long p = i;
    while (p <= MT) {
      powers[i].push_back(p);
      inv[p] = i;
      p *= i;
    }
  }

  int n; cin >> n;
  while (n--) solve(powers, inv);
  return 0;
}
