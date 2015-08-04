using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int n;
int transform(int m1, int m2) {
  int tot = 0;

  for (int i = 0; i < n; ++i) {
    int a = (m1 >> i) & 1;
    int b = (m2 >> i) & 1;
    if (a != b) {
      for (int j = i + 1; j < n; ++j) {
        if (((m1 >> j) & 1) == b) {
          // cout << "  swap " << i << " = " << j << endl;
          tot += (j - i);
          m1 ^= (1 << i);
          m1 ^= (1 << j);
          break;
        }
      }
    }
  }
  return tot;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;
  while (cin >> n >> m) {
    int mask = 0, t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      mask = (mask << 1) + t;
    }

    int t1 = 0, t2 = (1 << n) - 1;
    int tot_ones = 0;
    for (int i = 0; i < m; ++i) {
      cin >> t;
      t1 <<= t;
      if ((i & 1) == 0) {
        t1 |= ((1 << t) - 1);
        tot_ones += t;
      }
    }

    int best = 1 << 20;
    if (tot_ones == __builtin_popcount(mask)) {
      // cout << "first:" << endl;
      best = transform(mask, t1);
    }

    if ((n - tot_ones) == __builtin_popcount(mask)) {
      t2 ^= t1;
      // cout << "second:" << endl;
      best = min(best, transform(mask, t2));
    }

    cout << best << endl;

  }
  return 0;
}

