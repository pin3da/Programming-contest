#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, d;
  while (cin >> d >> n) {
    vector<string> a(n);
    int acc = 0, ans = 0;
    for (auto &i : a) {
      cin >> i;
      int ok = 1;
      for (auto &j : i)
        ok &= j - '0';
      if (!ok)
        acc++;
      else {
        ans = max(ans, acc);
        acc = 0;
      }
    }
    cout << max(ans, acc) << endl;
  }

  return 0;
}
