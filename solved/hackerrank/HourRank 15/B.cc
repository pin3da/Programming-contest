#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

// RMQ.
const int MN = 1000000 + 10; // Max number of elements
const int ML = 20; // ceil(log2(MN));

struct st {
  int data[MN];
  int M[MN][ML];
  int n;
  map<int, int> inv;

  void read(int _n) {
    n = _n;
    inv.clear();
    for (int i = 0; i < n; ++i) {
      cin >> data[i];
      inv[data[i]] = i;
    }
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = data[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = max(M[i][j - 1], M[i + q][j - 1]);
  }

  int query(int b, int e) {
    int k = log2(e - b + 1);
    return max(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};


st tree;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int g; cin >> g;
  while (g--) {
    int n; cin >> n;
    tree.read(n);
    tree.build();
    int last = n - 1;
    int step = 0;
    while (last >= 0) {
      int mmax = tree.query(0, last);
      last = tree.inv[mmax] - 1;
      step++;
    }
    if (step & 1) {
      cout << "BOB" << endl;
    } else {
      cout << "ANDY" << endl;
    }
  }

  return 0;
}
