#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;
const int MN = 64;

typedef unsigned long long ull;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  vector<ull> sheldon;
  for (int i = 1; i < MN; ++i) {
    for (int j = 0; j < MN; ++j) {
      ull one = 1;
      ull block = (one << i) - 1;
      int cur = i, iter = 1;
      ull x = 0;
      while (cur < MN) {
        if (iter & 1) {
          x <<= i;
          x |= block;
          cur += j;
        } else {
          x <<= j;
          cur += i;
        }
        iter ^= 1;
        if (x)
          sheldon.push_back(x);
      }
    }
  }

  sort(sheldon.begin(), sheldon.end());
  sheldon.resize(unique(sheldon.begin(), sheldon.end()) - sheldon.begin());

  // for (int i = sheldon.size() - 100; i < sheldon.size() - 90; ++i) {
  //  debug(sheldon[i]);
  // }

  ull x, y;
  while (cin >> x >> y) {
    int id1 = lower_bound(sheldon.begin(), sheldon.end(), x)
                - sheldon.begin();
    int id2 = upper_bound(sheldon.begin(), sheldon.end(), y)
               - sheldon.begin();
    cout << id2 - id1 << endl;
  }

  return 0;
}
