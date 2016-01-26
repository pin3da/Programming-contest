#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (true) {
    vector<int> x(3), y(2);
    set<int> seen;
    for (auto &i : x) {
      cin >> i;
      seen.insert(i);
    }
    for (auto &i : y) {
      cin >> i;
      seen.insert(i);
    }
    if (x[0] == 0) break;
    int ok = false;
    for (int k = 1; k < 53; ++k) {
      if (seen.count(k)) continue;
      vector<int> a = x;
      vector<int> b = y;
      b.push_back(k);

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      int lose = 0;
      for (int i = 0; i < b.size(); ++i) {
        int ll = 0;
        for (int j = 0; j < a.size(); ++j) {
          if (b[i] < a[j]) {
            lose++;
            b.erase(b.begin() + i);
            a.erase(a.begin() + j);
            --i;--j;
            ll = true;
            break;
          }
        }
        if (!ll)
          a.erase(a.begin());
      }

      if (lose >= 2) {
        continue;
      }

      cout << k << endl;
      ok = true;
      break;
    }
    if (!ok)
      cout << -1 << endl;
  }
  return 0;
}
