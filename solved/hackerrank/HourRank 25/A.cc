#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  int n;
  cin >> n;
  int acc = 0;

  while (n--) {
    string line; cin >> line;
    for (auto &i : line) {
      acc = (acc + (i - '0')) % 3;
    }
  }
  puts(acc == 0 ? "Yes" : "No");
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
