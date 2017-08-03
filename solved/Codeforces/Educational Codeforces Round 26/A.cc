#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  string s;
  int best = 0;
  while (cin >> s) {
    int cur = 0;
    for (auto i : s) {
      if (i >= 'A' && i <= 'Z') cur++;
    }
    best = max(best, cur);
  }
  cout << best << endl;
  return 0;
}
