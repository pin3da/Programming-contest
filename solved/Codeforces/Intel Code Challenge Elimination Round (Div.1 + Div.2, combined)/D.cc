#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 50000 + 100;
long long a[MN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  while (cin >> n) {
    set<long long> cur;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cur.insert(a[i]);
    }

    while (cur.size()) {
      long long c = *(--cur.end());
      int seen = 0;
      while (c > 1) {
        c >>= 1;
        if (cur.count(c) == 0) {
          cur.erase(--cur.end());
          cur.insert(c);
          seen = true;
          break;
        }
      }
      if (!seen) {
        cout << *(--cur.end()) << ' ';
        cur.erase(--cur.end());
      }
    }
    cout << endl;
  }
  return 0;
}
