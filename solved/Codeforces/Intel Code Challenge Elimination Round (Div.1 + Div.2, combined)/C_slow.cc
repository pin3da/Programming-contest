#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 1e5 + 100;

int cool[MN];
int a[MN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;

  while (cin >> n) {

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> cool[i];

    set<int> bad;
    for (int i = 0; i < n; ++i) {
      long long best = 0;
      bad.insert(cool[i] - 1);
      long long cur = 0;
      for (int j = 0; j < n; ++j) {
        if (bad.count(j)) {
          best = max(best, cur);
          cur = 0;
        } else {
          cur += a[j];
        }
      }
      if (cur)
        best = max(best, cur);
      cout << best << endl;
    }
  }
  return 0;
}
