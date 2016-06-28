#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int go(string &a, string &b) {
  int top = min(a.size(), b.size());
  int ans = 0;
  for (int i = 0; i < top; ++i)
    ans += a[i] != b[i];
  ans += b.size() - top + a.size() - top;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string x;
  int k;
  while (cin >> x >> k) {
    int best = 111, id_best = -1;
    for (int i = 0; i < 5; ++i) {
      string line; cin >> line;
      int cur = go(x, line);
      if (cur < best) {
        best = cur;
        id_best = i + 1;
      }
    }
    if (best < k)
      cout << id_best << endl << best << endl;
    else
      cout << - 1 << endl;
  }
  return 0;
}
